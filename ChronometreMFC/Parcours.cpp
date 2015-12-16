#include "stdafx.h"
#include "Parcours.h"

Parcours::Parcours(){
	Parcours::current = 0;
	Parcours::c = new Chronometre();
};

void Parcours::start(){
	c->start();
	//TODO : Gestion du GPS
};

void Parcours::stop(){

	c->stop();
	//Création d'un nouvelle étape
	
	Parcours::etape[Parcours::current].heure = c->getCurrentTime();
	//etape[current].position = NULL;
	if(Parcours::current < 39)
		Parcours::current += 1;
};

void Parcours::tour(){
	//Création d'un nouvelle étape
	Parcours::etape[Parcours::current].heure = c->getCurrentTime();
	//etape[current].position(NULL);
	if(Parcours::current < 39)
		Parcours::current++;
};


Chronometre* Parcours::getChronometre(){
	return Parcours::c;
};

string Parcours::getLastEtape(){
	ostringstream oss;
	string cur, h, pos;

	oss << Parcours::current;
	cur = oss.str();

	oss << Parcours::etape[(Parcours::current - 1)].heure;
	h = oss.str();

	//TODO : Position
	cout << cur << h;
	return cur + h;

};

