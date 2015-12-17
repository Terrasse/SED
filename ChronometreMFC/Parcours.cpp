#include "stdafx.h"
#include "Parcours.h"

Parcours::Parcours(){
	Parcours::origine = NULL;
	Parcours::etape = NULL;
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
	if(Parcours::current < max_tour)
		Parcours::current += 1;*/
};

void Parcours::tour(){
	//Création d'un nouvelle étape
		//Parcours::current++;
		Etape* nouvelle = new Etape();
		nouvelle->heure = c->getCurrentTime();
		nouvelle->position = gps->getPosition();
		if ( Parcours::etape != NULL){
			nouvelle->tour=Parcours::etape->tour + 1 ;
			nouvelle->terry=Parcours::etape;
		}else{
			nouvelle->tour=1 ;
			nouvelle->terry=NULL;
		}
		Parcours::etape = nouvelle;
};


Chronometre* Parcours::getChronometre(){
	return Parcours::c;
};

int Parcours::getNbTours(){
	if(Parcours::etape != NULL){
		return Parcours::etape->tour+1;
	}
	return 1;
}
string Parcours::getLastEtape(){
	string cur, h, pos,ret;
	if(Parcours::etape == NULL){
		ret = "";
		return ret;
	}
	{
		ostringstream oss;
		if(Parcours::etape->tour<10){
			oss << "00" << Parcours::etape->tour;
		}else if(Parcours::etape->tour<100){
			oss << "0" << Parcours::etape->tour;
		}else{
			oss <<  Parcours::etape->tour;
		}
		cur = oss.str();
	}
	{
		ostringstream oss;
		if(Parcours::etape->terry==NULL){
			oss << Parcours::etape->heure->format();
		}else{
			oss << Parcours::etape->terry->heure->diff(Parcours::etape->heure)->format();
		}
		h = oss.str();
	}
	{
		ostringstream oss;
		if(Parcours::etape->terry==NULL){
			oss << Position::calculDistanceToString(Parcours::etape->position,Parcours::origine);
		}else{
			oss << Position::calculDistanceToString(Parcours::etape->position,Parcours::etape->terry->position);
		}
		pos = oss.str();
	}

	ret = cur + "   " + h + "   " + pos + "  "+Parcours::etape->position->toString();//+"  "+ Parcours::etape[(Parcours::current - 1)].position->toString();
	return ret;

};

