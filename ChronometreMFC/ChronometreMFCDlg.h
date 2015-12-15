// ChronometreMFCDlg.h : fichier d'en-t�te
//

#pragma once

// Bo�te de dialogue CChronometreMFCDlg
class CChronometreMFCDlg : public CDialog
{
// Construction
public:
	CChronometreMFCDlg(CWnd* pParent = NULL);	// constructeur standard

// Donn�es de bo�te de dialogue
	enum { IDD = IDD_CHRONOMETREMFC_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Prise en charge de DDX/DDV

// Impl�mentation
protected:
	HICON m_hIcon;

	// Fonctions g�n�r�es de la table des messages
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit4();
	int v_heure;
	int v_minute;
	int v_seconde;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnEnChangeEdit5();
};

