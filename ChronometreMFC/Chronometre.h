// class permettant de gérer le chronomètre
class CChronometreMFCDlg : public CDialog{
private: 
	int v_heure;
	int v_minute;
	int v_seconde;

public:
	virtual char* getHeure();
	virtual char* getMinute();
	virtual char* getSeconde();
	virtual void start();
	virtual void stop();
};
