// class permettant de g�rer le chronom�tre

#include "stdafx.h"
#include "Heure.h"
#include "windows.h"
#include "etat.h"
#include <iostream>
#include <afxmt.h>

using namespace std;

#ifndef Chrono_H
#define Chrono_H
// class permettant de g�rer le chronom�tre
//#include "EtatChronometre.h"


class Chronometre{


public:
	DWORD _tick_count_start;
	DWORD _tick_count_stop;
	Heure* _current_time;
	etat _state;
	HANDLE mu;
	// constructeur 
	Chronometre();

	// m�thode
	virtual Heure* getCurrentTime();
	// virtual UINT start(void *pParam);
	virtual void start();
	virtual void restart();
	virtual void stop();
	virtual void changeState(etat newState);
	virtual void initChronometre();
};
// Threading function
UINT UpdateCurrentTime(LPVOID pParam);
#endif
