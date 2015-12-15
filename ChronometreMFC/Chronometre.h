// class permettant de gérer le chronomètre
#include "stdafx.h"
#include "Heure.h"
#include "windows.h"
#include "iostream"
using namespace std;

class Chronometre{

public:

	DWORD tick_count_start;
	DWORD tick_count_stop;

	virtual Heure* getCurrentTime();
	
	virtual void start();
	virtual void stop();
};
