// ChronometreMFCDlg.h : fichier d'en-tête
//
#include "stdafx.h"
#include "ChronometreMFC.h"
#include "windows.h"
#include "Parcours.h"
#include "Chronometre.h"
#include "Heure.h"
#include <string>
#include <Afxmt.h>

using namespace std;
#pragma once

// Boîte de dialogue CChronometreMFCDlg
class CChronometreMFCDlg : public CDialog
{
// Construction
public:
	CChronometreMFCDlg(CWnd* pParent = NULL);	// constructeur standard

// Données de boîte de dialogue
	enum { IDD = IDD_CHRONOMETREMFC_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Prise en charge de DDX/DDV

// Implémentation
protected:
	HICON m_hIcon;

	// Fonctions générées de la table des messages
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif
	DECLARE_MESSAGE_MAP()
public:
	CWnd m_sText;
	CWnd m_bRestart;
	CWnd m_bStop;
	CWnd m_bStart;
	CWnd m_bTour;
    CListBox m_listBox;
	Parcours *v_parcours;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnStartRefresh();
	afx_msg void OnBnClickedButton2();
	void doUpdate();
	afx_msg void OnLbnSelchangeList3();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnStnClickedStatic0();
};

