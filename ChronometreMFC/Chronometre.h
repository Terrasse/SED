// class permettant de g�rer le chronom�tre
class CChronometreMFCDlg : public CDialog{
private: 
	int v_heure;
	int v_minute;
	int v_seconde;

public:
	virtual void getHeure();
	virtual void getMinute();
	virtual void getSeconde();
	virtual void start();
	virtual void stop();
}
