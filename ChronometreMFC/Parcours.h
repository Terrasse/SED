#ifndef Parcours_H
#define Parcours_H

#include "Etape.h"
#include "Position.h"
#include "Chronometre.h"
#include "GPS.h"
#include <iostream>
#include <sstream>
using namespace std;

//#define MAX_TOUR 15

class Parcours { 
private :

	Etape* etape;
	Position* origine;
	Chronometre* c;
	GPS* gps;
public : 
	Parcours(Chronometre *chrono);

	// fonctions 
	void init();
	void start();
	void stop();
	void tour();
	void reset();
	Chronometre* getChronometre();
	
	//Permet de récupérer la dernière étape 
	string getLastEtape();

	int getNbTours();	

};
#endif
