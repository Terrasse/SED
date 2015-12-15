#ifndef Heure_H
#define Heure_H
#include "windows.h"

class Heure{
private: 

	int heure;
	int minute;
	int seconde;
	int milliseconde;

public:
	Heure(DWORD start, DWORD stop);

	// modification des attributs
	// heure
	virtual int getHeure();
	virtual void setHeure(int new_heure);
	
	// minute
	virtual int getMinute();
	virtual void setMinute(int new_minute);

	// seconde
	virtual int getSeconde();
	virtual void setSeconde(int new_seconde);

	// milliseconde
	virtual int getMilliseconde();
	virtual void setMilliseconde(int new_milliseconde);

	// affichage 
	virtual char* toString();

	// fonctions metier
	virtual int diff(Heure h);
};
#endif
