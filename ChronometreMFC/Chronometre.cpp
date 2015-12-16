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
		if ( current_state == OFF ) {
			if(Chronometre::tick_count_pause > 0){
				DWORD elapse =  GetTickCount() - Chronometre::tick_count_pause;
				Chronometre::tick_count_start += elapse;
				Chronometre::tick_count_stop += elapse;
			}
			else{
			Chronometre::tick_count_start = GetTickCount();
			}
			current_state = ON;
		}
	};

	void Chronometre::stop(){
		if ( current_state == ON ) {
			Chronometre::tick_count_stop = GetTickCount();
			Chronometre::tick_count_pause = Chronometre::tick_count_stop;
			current_state = OFF;
		}
	};

	void Chronometre::restart(){
		tick_count_start = 0;
		tick_count_stop = 0;
		tick_count_pause = 0;
	}; 