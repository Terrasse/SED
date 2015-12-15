#include "stdafx.h"
#include "Heure.h"

//Constructeur de la classe heure 
Heure::Heure(DWORD start, DWORD stop){
		int diff = stop - start;

		if(diff > 0){
			milliseconde = (int) diff % 1000;
			diff = (int) diff / 1000;
			seconde = (int) diff % 60;
			diff = (int) diff / 60;
			minute = (int) diff % 60;
			heure = (int) diff / 60;
		}
	};

//Getters
int Heure::getHeure(){
		return Heure::heure;
	};

int Heure::getMinute(){
		return Heure::minute;
	};

int Heure::getSeconde(){
		return Heure::seconde;
	};

int Heure::getMilliseconde(){
		return Heure::milliseconde;
	};

//Setters
void Heure::setHeure(int new_heure){
	Heure::heure = new_heure;
};

void Heure::setMinute(int new_minute){
	Heure::minute = new_minute;
};

void Heure::setSeconde(int new_seconde){
	Heure::seconde = new_seconde;
};

void Heure::setMilliseconde(int new_milliseconde){
	Heure::milliseconde = new_milliseconde;
};

char* Heure::toString(){
	return "MA BITE";
};

int Heure::diff(Heure h){
	return 0;
}