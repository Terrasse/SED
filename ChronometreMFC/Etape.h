#include 'Heure.h'
#include 'Position.h'
struct Etape {
	Heure* heure;
	Position* position;
	bool pause;
};