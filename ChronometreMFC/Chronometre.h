// class permettant de g�rer le chronom�tre
#ifndef Chrono_H
#define Chrono_H

class Chronometre{
public:
	virtual char* getHeure();
	virtual char* getMinute();
	virtual char* getSeconde();
	virtual void start();
	virtual void stop();
};

#endif
