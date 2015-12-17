#include "stdafx.h"
#include "Heure.h"

//Constructeur de la classe heure 
Heure::Heure(){
	milliseconde = 0;
	seconde = 0;
	minute = 0;
	heure = 0;
};

Heure::Heure(DWORD start, DWORD stop){
	Heure();
	importTicCount(start,stop);
};

void Heure::importTicCount(DWORD start, DWORD stop) {
	int diff = stop - start;

	if(diff > 0){
		milliseconde = (int) diff % 1000;
		diff = (int) diff / 1000;
		seconde = (int) diff % 60;
		diff = (int) diff / 60;
		minute = (int) diff % 60;
		heure = (int) diff / 60;
	}
	else{
		milliseconde = 0;
		seconde = 0;
		minute = 0;
		heure = 0;
	}
}
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

//Affichage hh:mm:ss.msms
string Heure::format(){

	string h,m,s,ms,ret;
	{
		ostringstream oss;
		if(Heure::heure<10){
			oss << "0" << Heure::heure;
		}else{
			oss << Heure::heure;
		}
		h = oss.str();
	}

	{
		ostringstream oss;
		if(Heure::minute<10){
			oss << "0" << Heure::minute;
		}else{
			oss << Heure::minute;
		}
		m = oss.str();
	}

	{
	ostringstream oss;
	if(Heure::seconde<10){
		oss << "0" << Heure::seconde;
	}else{
		oss << Heure::seconde;
	}
	s = oss.str();
	}

	{
		ostringstream oss;
		if(Heure::milliseconde<10){
			oss << "00" << Heure::milliseconde;
		}else if(Heure::milliseconde<100){
			oss << "0" << Heure::milliseconde;
		}else{
			oss << Heure::milliseconde;
		}
		ms = oss.str();
	}

	ret = h + ":" + m + ":" + s + "." + ms;
	return ret;
};
//Affichage hh:mm:ss.msms
string Heure::formatShort(){

	string h,m,s,ms,ret;
	{
		ostringstream oss;
		if(Heure::heure<10){
			oss << "0" << Heure::heure;
		}else{
			oss << Heure::heure;
		}
		h = oss.str();
	}

	{
		ostringstream oss;
		if(Heure::minute<10){
			oss << "0" << Heure::minute;
		}else{
			oss << Heure::minute;
		}
		m = oss.str();
	}

	{
		ostringstream oss;
		if(Heure::seconde<10){
			oss << "0" << Heure::seconde;
		}else{
			oss << Heure::seconde;
		}
		s = oss.str();
	}

	{
		ostringstream oss;
		if(Heure::milliseconde<10){
			oss << "00" << Heure::milliseconde;
		}else if(Heure::milliseconde<100){
			oss << "0" << Heure::milliseconde;
		}else{
			oss << Heure::milliseconde;
		}
		ms = oss.str();
	}
	if(Heure::heure>0){
		ret = h + "h " + m + "m " + s + "s " + ms+"ms";
	}else if(Heure::minute>0){
		ret = m + "m " + s + "s " + ms+"ms";
	}else if(Heure::seconde>0){
		ret = s + "s " + ms+"ms";
	}else if(Heure::milliseconde>0){
		ret = ms+"ms";
	}else{
		ret = "00m 00s 000ms";
	}

	return ret;
};

Heure* Heure::diff(Heure* h){

	//Conversion des heures en millisecondes 
	int sec_h1 = Heure::heure * 3600000 + Heure::minute * 60000 + Heure::seconde * 1000 + Heure::milliseconde;
	int sec_h2 = h->getHeure() * 3600000 + h->getMinute() * 60000 + h->getSeconde() * 1000 + h->getMilliseconde();
	
	//Calcul de la différence
	int dif = (sec_h2 - sec_h1);
	//int dif_pos = dif * dif / dif;

	//Remise en forme de l'heure
	int milliseconde = (int) dif % 1000;
	dif = (int) dif / 1000;
	int seconde = (int) dif % 60;
	dif = (int) dif / 60;
	int minute = (int) dif % 60;
	int heure = (int) dif / 60;

	Heure* new_h = new Heure();

	new_h->setHeure(heure);
	new_h->setMinute(minute);
	new_h->setSeconde(seconde);
	new_h->setMilliseconde(milliseconde);

	return new_h;
}

