// class permettant de g�rer le chronom�tre
class Chronometre{
public:
	virtual char* getHeure();
	virtual char* getMinute();
	virtual char* getSeconde();
	virtual void start();
	virtual void stop();
};
