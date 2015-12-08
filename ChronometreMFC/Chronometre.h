// class permettant de gérer le chronomètre
class Chronometre{
public:
	virtual char* getHeure();
	virtual char* getMinute();
	virtual char* getSeconde();
	virtual void start();
	virtual void stop();
};
