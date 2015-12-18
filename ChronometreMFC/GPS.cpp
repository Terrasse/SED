#include "stdafx.h"
#include "GPS.h"

#define MAX_WAIT    5000
#define MAX_AGE     3000
#define GPS_CONTROLLER_EVENT_COUNT 3
#define FREQUENCE_RAF 1000

GPS::GPS(void){
    m_hGPS_Device = NULL;
    m_hNewLocationData = NULL;
	_position = new Position(0,0);
	_state = OFF;
	mu_state = CreateMutex(NULL,FALSE,NULL);
	mu_position = CreateMutex(NULL,FALSE,NULL);
	this->initGps();
}

Position* GPS::getPosition(){		
	DWORD dwWaitResult=WaitForSingleObject(mu_position,INFINITE);
	Position* p=_position;
	ReleaseMutex(mu_position);
	return p;
}

void GPS::setPosition(double newLongitude, double newLatitude){		
	DWORD dwWaitResult=WaitForSingleObject(mu_position,INFINITE);
	if(newLongitude != 0 && newLatitude != 0) {
		_position = new Position(newLongitude,newLatitude);
	}
	ReleaseMutex(mu_position);
}

void GPS::initGps(){
	m_hNewLocationData = CreateEvent(NULL, FALSE, FALSE, NULL);
	m_hDeviceStateChange = CreateEvent(NULL, FALSE, FALSE, NULL);
	this->m_hGPS_Device = GPSOpenDevice( 
            this->m_hNewLocationData, 
            this->m_hDeviceStateChange, 
            NULL, NULL);
	if( this->m_hGPS_Device ){
		cout << "Get GPS ok\n";
	}else{
		cout << "Le GPS t'envoie chier\n";
	}	
	AfxBeginThread(UpdateCurrentPosition,this);
}

GPS::~GPS(void){
	GPSCloseDevice(this->m_hGPS_Device);
}


void GPS::start(){
	changeState(ON);
};

void GPS::stop(){
	changeState(OFF);
};

void GPS::changeState(etat newState){
	DWORD dwWaitResult=WaitForSingleObject(mu_state,INFINITE);
	_state = newState;
	ReleaseMutex(mu_state); 
}

UINT UpdateCurrentPosition(LPVOID pParam){
	GPS *gps=(GPS *)pParam;
	GPS_POSITION gps_Position={0};
	gps_Position.dwSize = sizeof(gps_Position);
	gps_Position.dwVersion = GPS_VERSION_1;
	do{
		DWORD dwWaitResult=WaitForSingleObject(gps->mu_state,INFINITE);
		switch(gps->_state){
			case ON: 
				
				GPSGetPosition(gps->m_hGPS_Device, &gps_Position, MAX_AGE, 0);
				printf("lat%d\n",gps_Position.dblLatitude);
				gps->setPosition(gps_Position.dblLongitude,gps_Position.dblLatitude);
				printf("lat%d\n",gps->getPosition()->getLatitude());
				break;
			case OFF:
				break;
		}
		ReleaseMutex(gps->mu_state); 
		Sleep(FREQUENCE_RAF);
	} while ( TRUE );
	return 0;
}