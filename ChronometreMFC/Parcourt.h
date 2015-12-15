#ifndef Parcourt_H
#define Parcourt_H

#include 'Etape.h'
class Parcourt {
private :
	int* etapes = new Etape[40];
	int current;
public : 

	// fonctions 
	void start();
	void stop();
	void pause();
	void restart();

	// affichage
	String toString();

};
#endif
