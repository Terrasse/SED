#ifndef Position_H
#define Position_H
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;

#define PI 3.14159265358979323846
#define RAYON_TERRE 6371000

class Position {
private: 
	double longitude;
	double latitude;

public:
	
	Position(Position* pos);
	Position(double longitude,double lalitude);

	// modification des attributs
	// longitude
	virtual double getLongitude();
	virtual void setLongitude(double new_longitude);
	
	// latitude
	virtual double getLatitude();
	virtual void setLatitude(double new_latitude);

	// affichage
	virtual string toString();

	static string calculDistanceToString(Position * p1 , Position * p2){
		ostringstream oss;
		string ret;
		double round;
		double dist ;
		dist = Position::calculDistance(p1,p2);
		if(dist>1000000){
			dist = (int)(dist / 1000);
			oss << dist << "km" ;
		}else if(dist>1000){
			dist = (int)(dist / 10);
			round = dist / 100.0;
			oss << round << "km" ;
		}else if(dist<1){
			dist = ((int)(dist *1000))/100.0;
			oss << dist << "cm" ;
		}else{
			
			dist = ((int)(dist *10))/10.0;
			oss << dist << "m" ;
		}
		ret = oss.str();
		return ret;
	}

	static double calculDistance(Position * p1 , Position * p2){
		return Position::distance(p1->getLatitude(),p1->getLongitude(),p2->getLatitude(),p2->getLongitude());
	}

	static double distance(double lat1, double lon1, double lat2, double lon2){
		double theta, dist;
		theta = lon1 - lon2;
		dist = sin(Position::deg2rad(lat1)) * sin(Position::deg2rad(lat2)) + cos(Position::deg2rad(lat1)) * cos(Position::deg2rad(lat2)) * cos(Position::deg2rad(theta));
		dist = acos(dist);
		dist = dist * RAYON_TERRE;
		return dist;
	}

	static double deg2rad(double deg) {
		return (deg * PI / 180);
	}
	static double rad2deg(double rad) {
		return (rad * 180 / PI);
	}
};
#endif
