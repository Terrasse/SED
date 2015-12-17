#include "stdafx.h"
#include "Chronometre.h"
#define FREQUENCE_RAF 20

	Chronometre::Chronometre(){
		_tick_count_start = 0;
		_tick_count_stop = 0;
		_current_time = new Heure(0,0);
		_state = RESET;
		mu = CreateMutex(NULL,FALSE,NULL);
		this->initChronometre();
	}
	
	Heure* Chronometre::getCurrentTime(){
		DWORD dwWaitResult=WaitForSingleObject(mu,INFINITE);
		Heure *captured=_current_time;
		ReleaseMutex(mu);
		return captured;
	};

	UINT UpdateCurrentTime(LPVOID pParam){
		Chronometre *c=(Chronometre *)pParam;
		do{
			DWORD dwWaitResult=WaitForSingleObject(c->mu,INFINITE);
			switch (dwWaitResult) {
				case WAIT_OBJECT_0:
					// lorsque le chronometre est RESET
					if ( c->_state == RESET ) {
						c->_tick_count_start = 0;
						c->_tick_count_stop = 0;
						c->_current_time->importTicCount(0,0);
					}

					// lorsque le chronometre est ON
					if ( c->_state == ON ) {
						// cas d'initialisation
						if(c->_tick_count_start == 0){
							c->_tick_count_start = GetTickCount();
						}
						// cas d'une reprise 
						if(c->_tick_count_stop > 0){
							DWORD elapse =  GetTickCount() - c->_tick_count_stop;
							c->_tick_count_start += elapse;
							c->_tick_count_stop = 0;
						}
						DWORD tick_count_current = GetTickCount();
						c->_current_time->importTicCount(c->_tick_count_start, tick_count_current);
					} 
					
					// lorque le chronometre est OFF
					if ( c->_state == OFF ) {
						// premier passage
						if(c->_tick_count_stop == 0){
							c->_tick_count_stop = GetTickCount();
						}
						c->_current_time->importTicCount(c->_tick_count_start, c->_tick_count_stop);
					}
					ReleaseMutex(c->mu); 
					break; 
				case WAIT_ABANDONED: 
					c->_current_time->importTicCount(0,0);
					break;
			}
			Sleep(FREQUENCE_RAF);
		} while ( TRUE );
		return 0;
	};

	// méthode qui va être executée par le thread
	void Chronometre::start(){
		changeState(ON);
	};

	void Chronometre::stop(){
		changeState(OFF);
	};

	void Chronometre::initChronometre(){
		AfxBeginThread(UpdateCurrentTime,this);
	}

	void Chronometre::restart(){
		changeState(RESET);
	}; 

	void Chronometre::changeState(etat newState){
		DWORD dwWaitResult=WaitForSingleObject(mu,INFINITE);
		_state = newState;
		ReleaseMutex(mu); 
	}