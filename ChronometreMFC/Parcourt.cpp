#include "stdafx.h"
#include "Parcourt.h"

Parcourt::Parcourt(){
	current = 0;
	c = new Chronometre;
};

void Parcourt::start(){
	c->start();
	//TODO : Gestion du GPS
};

void Parcourt::stop(){
	c->stop();
};