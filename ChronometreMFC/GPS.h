#ifndef GPS_H
#define GPS_H

#include "Position.h"
#include "etat.h"
#include <iostream>
#include <afxmt.h>
#include <GPSApi.h>
using namespace std;

interface IGPSSink
{
    virtual HRESULT SetGPSPosition(GPS_POSITION gps_Position) = 0;
    virtual HRESULT SetGPSDeviceInfo(GPS_DEVICE gps_Device) = 0;
};

class  GPS{
public:
    //Device handle
    HANDLE m_hGPS_Device;

    //Event for location data updates
    HANDLE m_hNewLocationData;

    //Event for device state changes
    HANDLE m_hDeviceStateChange;

    //Thread's handle and id
    HANDLE m_hThread;
    DWORD m_dwThreadID;

    //Exit event
    HANDLE m_hExitThread;

	Position *_position;

	etat _state;
	// Mutex
	HANDLE mu_position;
	HANDLE mu_state;

private :
	virtual void initGps();
public :
	GPS(void);
	virtual void start();
	virtual void stop();
	virtual void changeState(etat newState);
	virtual Position * getPosition();
	virtual void setPosition(double newLongitude, double newLatitude);
	//destructeur;
	~GPS(void);
};

UINT UpdateCurrentPosition(LPVOID pParam);
#endif
