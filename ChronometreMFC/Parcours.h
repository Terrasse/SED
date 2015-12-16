#ifndef Parcours_H
#define Parcours_H

#include "Etape.h"
#include "Position.h"
#include "Chronometre.h"
#include "GPS.h"
#include <iostream>
#include <sstream>
using namespace std;

#define MAX_TOUR 15

class Parcours {
private :

	Etape etape[MAX_TOUR];
	int current;
	Position* origine;
	Chronometre* c;
	GPS* gps;
public : 
	Parcours();

	// fonctions 
	void init();
	void start();
	void stop();
	void tour();

	Chronometre* getChronometre();
	

	//Permet de récupérer la dernière étape 
	string getLastEtape();
	int getNbTours();
	static int getMaxTours(){
		return MAX_TOUR;
	}
	
};
#endif
