#include "stdafx.h"
#include "Chronometre.h"

	Chronometre::Chronometre(){
		tick_count_start = 0;
		tick_count_stop = 0;
		tick_count_pause = 0;
		current_state = OFF;
	}

	Heure* Chronometre::getCurrentTime(){
		if ( current_state == ON ) {
			DWORD tick_count_current = GetTickCount();
			Heure* h = new Heure(tick_count_start, tick_count_current);
			return h;
		} 
		
		if ( current_state == OFF ) {
			Heure* h = new Heure(tick_count_start, tick_count_stop);
			return h;
		}
		return NULL;
	};

	void Chronometre::start(){
		if ( current_state == OFF || current_state == WAIT ) {
			Chronometre::tick_count_start = GetTickCount();
			Chronometre::tick_count_stop = Chronometre::tick_count_start;
			current_state = ON;
		}
		
	};

	void Chronometre::stop(){
		if ( current_state == ON ) {
			Chronometre::tick_count_stop = GetTickCount();
			current_state = OFF;
		}
		/*current_state = Chronomettre::state::stop;*/
		//Pour après
		/*
		return new Heure(tick_count_start, tick_count_stop
		*/
	};

	void Chronometre::pause(){
	/*	current_state = Chronomettre::state::pause;*/
		if ( current_state == ON ) {
			Chronometre::tick_count_pause = GetTickCount();
			current_state = WAIT;
		}
	};

	void Chronometre::restart(){
		/*	current_state = Chronomettre::state::running;*/
		Chronometre::tick_count_start = Chronometre::tick_count_start + (GetTickCount() - tick_count_pause);
	};