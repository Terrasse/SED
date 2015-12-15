#ifndef GPS_H
#define GPS_H

#include <GPSApi.h>
interface IGPSSink
{
    virtual HRESULT SetGPSPosition(GPS_POSITION gps_Position) = 0;
    virtual HRESULT SetGPSDeviceInfo(GPS_DEVICE gps_Device) = 0;
};

#include "Position.h"

class  GPS {
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
public :
	GPS(void);
	virtual Position* getPosition();
	virtual void initGps(GPS * pDevice);
	//destructeur;
	~GPS(void);
};
#endif
