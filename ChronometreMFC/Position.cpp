#include "stdafx.h"
#include "Position.h"

	// modification des attributs
	// longitude
	double Position::getLongitude(){
		return this->longitude;
	}
	void Position::setLongitude(double new_longitude){
		this->longitude=new_longitude;
	}
	
	// latitude
	double Position::getLatitude(){
		return this->latitude;
	}
	void Position::setLatitude(double new_latitude){
		this->latitude=new_latitude;
	}
	// affichage
	string Position::toString(){
		ostringstream  pos;
		pos << "(lat:" << this->getLatitude() << "; long:" << this->getLongitude() << ")"  ;
		return pos.str();
	}

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