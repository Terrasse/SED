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
		this->latitude=new_latitude;}

	// affichage
	char* Position::toString(){
		return "test";
	}