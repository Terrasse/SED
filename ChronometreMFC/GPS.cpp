#include "stdafx.h"
#include "GPS.h"

#define MAX_WAIT    5000
#define MAX_AGE     3000
#define GPS_CONTROLLER_EVENT_COUNT 3


GPS::GPS(void){
	printf("construct");
    m_hGPS_Device = NULL;
    m_hNewLocationData = NULL;
    m_hDeviceStateChange = NULL;
    m_hExitThread = NULL;
}
Position* GPS::getPosition(){

	Position* p= new Position();
	p->setLatitude(10);
	p->setLongitude(12);
	return p;
}
void GPS::initGps(GPS * pDevice){
	m_hNewLocationData = CreateEvent(NULL, FALSE, FALSE, NULL);
	m_hDeviceStateChange = CreateEvent(NULL, FALSE, FALSE, NULL);
	GPSOpenDevice(NULL,NULL,NULL, NULL);
	if( pDevice->m_hGPS_Device ){
		printf("erreur");
	}
}