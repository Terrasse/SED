#include "stdafx.h"
#include "Chronometre.h"

Heure* Chronometre::getCurrentTime(){
		DWORD tick_count_current = GetTickCount();
		Heure* h = new Heure(tick_count_start, tick_count_current);
		return h;
	};

	void Chronometre::start(){
		/*current_state = Chronomettre::state::running;*/
		Chronometre::tick_count_start = GetTickCount();
		Chronometre::tick_count_stop = Chronometre::tick_count_start;
	};

	void Chronometre::stop(){
		/*current_state = Chronomettre::state::stop;*/
		Chronometre::tick_count_stop = GetTickCount();
		//Pour après
		/*
		return new Heure(tick_count_start, tick_count_stop
		*/
	};

	void Chronometre::pause(){
	/*	current_state = Chronomettre::state::pause;*/
		Chronometre::tick_count_pause = GetTickCount();
	};

	void Chronometre::restart(){
	/*	current_state = Chronomettre::state::running;*/
		Chronometre::tick_count_start = Chronometre::tick_count_start + (GetTickCount() - tick_count_pause);
	};