#ifndef Parcours_H
#define Parcours_H

#include "Etape.h"
#include "Chronometre.h"
using namespace std;

class Parcours {
private :
	Etape etape[40];
	int current;
	Chronometre* c;
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

};
#endif
