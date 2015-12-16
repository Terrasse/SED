#include "stdafx.h"
#include "GPS.h"

#define MAX_WAIT    5000
#define MAX_AGE     3000
#define GPS_CONTROLLER_EVENT_COUNT 3

#include <iostream>
using namespace std;

GPS::GPS(void){
    m_hGPS_Device = NULL;
    m_hNewLocationData = NULL;
	this->initGps();
}
Position* GPS::getPosition(){		
	DWORD dwRet = 0;
    GPS_POSITION gps_Position = {0};
    GPS_DEVICE gps_Device = {0};

	gps_Position.dwSize = sizeof(gps_Position);
    gps_Position.dwVersion = GPS_VERSION_1;

    gps_Device.dwVersion = GPS_VERSION_1;
    gps_Device.dwSize = sizeof(gps_Device);

	GPSGetPosition(
                this->m_hGPS_Device, 
                &gps_Position, MAX_AGE, 0);

	cout << "lat" << gps_Position.dblLatitude <<"; long" << gps_Position.dblLongitude <<"\n";

	Position* p= new Position();
	p->setLatitude(gps_Position.dblLatitude);
	p->setLongitude(gps_Position.dblLongitude);
	return p;
}
void GPS::initGps(){

	m_hNewLocationData = CreateEvent(NULL, FALSE, FALSE, NULL);
	m_hDeviceStateChange = CreateEvent(NULL, FALSE, FALSE, NULL);
	this->m_hGPS_Device = GPSOpenDevice( 
            this->m_hNewLocationData, 
            this->m_hDeviceStateChange, 
            NULL, NULL);
	if( this->m_hGPS_Device){
		cout << "Get GPS ok\n";
	}else{
		cout << "Le GPS t'envoie chier\n";
	}	
}