#include "windows.h"
#include "iostream"
#include "sstream"
#include "string"
using namespace std;

class Heure{
private: 

	int heure;
	int minute;
	int seconde;
	int milliseconde;

public:

	Heure();
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
	virtual string format();

	// fonctions metier
	virtual Heure diff(Heure h);

};