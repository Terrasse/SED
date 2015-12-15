#include "stdafx.h"
#include "Chronometre.h"

Heure* Chronometre::getCurrentTime(){
		DWORD tick_count_current = GetTickCount();
		Heure* h = new Heure(tick_count_start, tick_count_current);
		return h;
	};

	void Chronometre::start(){
		Chronometre::tick_count_start = GetTickCount();
		Chronometre::tick_count_stop = Chronometre::tick_count_start;
	};

	void Chronometre::stop(){
		Chronometre::tick_count_stop = GetTickCount();
		//Pour après
		/*
		return new Heure(tick_count_start, tick_count_stop
		*/
	};