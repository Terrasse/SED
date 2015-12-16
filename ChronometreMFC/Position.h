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

	static double calculDistance(Position * p1 , Position * p2){
		return Position::distance(p1->getLatitude(),p1->getLongitude(),p2->getLatitude(),p2->getLongitude());
	}
	static double distance(double lat1, double lon1, double lat2, double lon2){
		double theta, dist;
		theta = lon1 - lon2;
		dist = sin(Position::deg2rad(lat1)) * sin(Position::deg2rad(lat2)) + cos(Position::deg2rad(lat1)) * cos(Position::deg2rad(lat2)) * cos(Position::deg2rad(theta));
		dist = acos(dist);
		dist = Position::rad2deg(dist);
		dist = dist * 60 * 1.1515 * 1.609344;
		return dist;
	}
	static double deg2rad(double deg) {
		return (deg * pi / 180);
	}
	static double rad2deg(double rad) {
		return (rad * 180 / pi);
	}
};
#endif
