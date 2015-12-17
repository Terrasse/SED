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
		int dist ;
		dist = Position::calculDistance(p1,p2);
			printf("%d\t",dist);
		if(dist>1000000){
			printf("1\n");
			dist = (int)(dist / 1000);
			oss << dist << "km" ;
		}else if(dist>1000){
			printf("2\n");
			dist = (int)(dist / 10);
			round = dist / 100.0;
			oss << round << "km" ;
		}else{
			printf("3\n");
			oss << dist << "m" ;
		}
		ret = oss.str();
		return ret;
	}

	static int calculDistance(Position * p1 , Position * p2){
		int i;
		i = rand()%10;
		printf("%d\t",i);
		if(i ==1){
			return 1;
		}else if(i ==2){
			return 22;
		}else  if(i ==3){
			return 333;
		}else  if(i ==4){
			return 4444;
		}else  if(i ==5){
			return 55555;
		}else  if(i ==6){
			return 666666;
		}else  if(i ==7){
			return 7777777;
		}else  if(i ==8){
			return 88888888;
		}else  if(i ==9){
			return 9999999999;
		}else {
			return 0.01;
		}

		return Position::distance(p1->getLatitude(),p1->getLongitude(),p2->getLatitude(),p2->getLongitude());
	}
	static int distance(double lat1, double lon1, double lat2, double lon2){
		double theta, dist;
		theta = lon1 - lon2;
		dist = sin(Position::deg2rad(lat1)) * sin(Position::deg2rad(lat2)) + cos(Position::deg2rad(lat1)) * cos(Position::deg2rad(lat2)) * cos(Position::deg2rad(theta));
		dist = acos(dist);
		dist = dist * RAYON_TERRE;
		return (int)dist;
	}
	static double deg2rad(double deg) {
		return (deg * PI / 180);
	}
	static double rad2deg(double rad) {
		return (rad * 180 / PI);
	}
};
#endif
