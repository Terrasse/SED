// class permettant de gérer le chronomètre

#include "stdafx.h"
#include "Heure.h"
#include "windows.h"
#include <iostream>
#include <afxmt.h>

using namespace std;

#ifndef Chrono_H
#define Chrono_H
// class permettant de gérer le chronomètre
//#include "EtatChronometre.h"
enum etat { ON = '0', OFF = '1', RESET = '2'};

class Chronometre{


public:
	DWORD _tick_count_start;
	DWORD _tick_count_stop;
	Heure* _current_time;
	etat _state;
	HANDLE mu;
	// constructeur 
	Chronometre();

	// méthode
	virtual Heure* getCurrentTime();
	// virtual UINT start(void *pParam);
	virtual void start();
	virtual void restart();
	virtual void stop();
	virtual void changeState(etat newState);
	virtual void initThread();
};
// Threading function
UINT UpdateCurrentTime(LPVOID pParam);
#endif
