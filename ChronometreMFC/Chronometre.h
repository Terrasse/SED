// class permettant de gérer le chronomètre

#include "stdafx.h"
#include "Heure.h"
#include "windows.h"
#include "iostream"
using namespace std;

#ifndef Chrono_H
#define Chrono_H

// class permettant de gérer le chronomètre
#include "stdafx.h"
#include "Heure.h"
#include "windows.h"
//#include "EtatChronometre.h"


class Chronometre{

enum etat { ON = '0', OFF = '1', WAIT = '2' };

public:

	DWORD tick_count_start;
	DWORD tick_count_pause;
	DWORD tick_count_stop;
	
	etat current_state;

	// constructeur 
	Chronometre();

	// méthode
	virtual Heure* getCurrentTime();
	
	virtual void start();
	virtual void pause();
	virtual void restart();
	virtual void stop();
};

#endif
