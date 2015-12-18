#include "stdafx.h"
#include "Position.h"
	
	Position::Position(Position* pos){
		Position::longitude=pos->getLongitude();
		Position::latitude=pos->getLatitude();
	};
	Position::Position(double longitude, double latitude){
		Position::longitude=longitude;
		Position::latitude=latitude;
	};
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
		pos << "(" << this->getLatitude() << ";" << this->getLongitude() << ")"  ;
		return pos.str();
	}

	