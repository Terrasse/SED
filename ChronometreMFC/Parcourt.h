#ifndef Parcourt_H
#define Parcourt_H

#include "Etape.h"
#include "Chronometre.h"
using namespace std;

class Parcourt {
private :
	Etape etape[40];
	int current;
	Chronometre* c;
public : 
	Parcourt();

	// fonctions 
	void init();
	void start();
	void stop();
	void pause();
	void restart();
	void tour();

	//Permet de récupérer l'étape i
	string getEtape(int i){
	}

	//Permet de récupérer la dernière étape 
	string getLastEtape(){
	}

};
#endif
