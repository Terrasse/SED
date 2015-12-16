#include "stdafx.h"
#include "Parcours.h"

Parcours::Parcours(){
	Parcours::current = 0;
	Parcours::origine = NULL;
	Parcours::c = new Chronometre();
	Parcours::gps = new GPS();

};

void Parcours::start(){
	c->start();
	Parcours::origine = gps->getPosition();
	//TODO : Gestion du GPS
};

void Parcours::stop(){

	c->stop();
	//Création d'un nouvelle étape
	//Pourquoi une sauvegarde de tour
	/*Parcours::etape[Parcours::current].heure = c->getCurrentTime();
	Parcours::etape[Parcours::current].position = gps->getPosition();;
	if(Parcours::current < 39)
		Parcours::current += 1;*/
};

void Parcours::tour(){
	//Création d'un nouvelle étape
	Parcours::etape[Parcours::current].heure = c->getCurrentTime();
	Parcours::etape[Parcours::current].position = gps->getPosition();
	if(Parcours::current < 39)
		Parcours::current++;
};


Chronometre* Parcours::getChronometre(){
	return Parcours::c;
};

string Parcours::getLastEtape(){
	string cur, h, pos,ret;
	{
		ostringstream oss;
		if(Parcours::current<10){
			oss << Parcours::current;
		}else{
			oss <<  "0" << Parcours::current;
		}
		cur = oss.str();
	}
	{
		ostringstream oss;
		if((Parcours::current - 1)==0){
			oss << Parcours::etape[(Parcours::current - 1)].heure->format();
		}else{
			oss << Parcours::etape[(Parcours::current - 1)].heure->format();
			// revoir diff oss << Parcours::etape[(Parcours::current - 1)].heure->diff(Parcours::etape[(Parcours::current - 2)].heure).format();
		}
		h = oss.str();
	}
	{
		ostringstream oss;
		if((Parcours::current - 1)==0){
			oss << Position::calculDistance(Parcours::etape[(Parcours::current - 1)].position,Parcours::origine);
		}else{
			oss << Position::calculDistance(Parcours::etape[(Parcours::current - 1)].position,Parcours::etape[(Parcours::current - 2)].position);
		}
		pos = oss.str();
	}

	ret = cur + "  " + h + "  " + pos;
	return ret;

};

