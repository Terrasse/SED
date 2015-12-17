#ifndef Etape_H
#define Etape_H

#include "Heure.h"
#include "Position.h"

struct Etape {
	Heure* heure;
	Position* position;
	Etape* terry;
	int tour;
};
					   
#endif
