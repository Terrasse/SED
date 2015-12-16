#ifndef Position_H
#define Position_H
#include <math.h>
#include <iostream>
#include <sstream>
using namespace std;

#define pi 3.14159265358979323846

class Position {
private: 
	double longitude;
	double latitude;

public:
	
	// modification des attributs
	// longitude
	virtual double getLongitude();
	virtual void setLongitude(double new_longitude);
	
	// latitude
	virtual double getLatitude();
	virtual void setLatitude(double new_latitude);

	// affichage
	virtual string toString();

	static double calculDistance(Position * p1 , Position * p2);
	static double deg2rad(double);
	static double rad2deg(double);
	static double distance(double lat1, double lon1, double lat2, double lon2);
};
#endif
