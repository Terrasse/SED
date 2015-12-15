// class permettant de gérer le chronomètre

#include "stdafx.h"
#include "Heure.h"
#include "windows.h"
#include "iostream"
using namespace std;

#ifndef Chrono_H
#define Chrono_H


class Chronometre{
public:
	virtual char* getHeure();
	virtual char* getMinute();
	virtual char* getSeconde();
	virtual void start();
	virtual void stop();
};

#endif
