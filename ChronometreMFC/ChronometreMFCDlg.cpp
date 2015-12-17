// ChronometreMFCDlg.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "ChronometreMFC.h"
#include "ChronometreMFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Boîte de dialogue CChronometreMFCDlg

CChronometreMFCDlg::CChronometreMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChronometreMFCDlg::IDD, pParent)
	, v_parcours(NULL)
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChronometreMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST3, m_listBox);
    DDX_Control(pDX, IDC_STATIC0, m_sText);
    DDX_Control(pDX, IDC_BUTTON1, m_bRestart);
    DDX_Control(pDX, IDC_BUTTON2, m_bStop);
    DDX_Control(pDX, IDC_BUTTON3, m_bStart);
    DDX_Control(pDX, IDC_BUTTON4, m_bTour);
}

BEGIN_MESSAGE_MAP(CChronometreMFCDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CChronometreMFCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CChronometreMFCDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CChronometreMFCDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CChronometreMFCDlg::OnBnClickedButton4)
	ON_WM_TIMER()
	ON_STN_CLICKED(IDC_STATIC0, &CChronometreMFCDlg::OnStnClickedStatic0)
END_MESSAGE_MAP()


// Gestionnaires de messages pour CChronometreMFCDlg

BOOL CChronometreMFCDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Définir l'icône de cette boîte de dialogue. L'infrastructure effectue cela automatiquement
	//  lorsque la fenêtre principale de l'application n'est pas une boîte de dialogue
	SetIcon(m_hIcon, TRUE);			// Définir une grande icône
	SetIcon(m_hIcon, FALSE);		// Définir une petite icône

	// TODO : ajoutez ici une initialisation supplémentaire
	
	//Le timer se déclenche toutes les 10ms voir onTimer pour le catch de l'event
	SetTimer(1, 10, NULL);

	return TRUE;  // retourne TRUE, sauf si vous avez défini le focus sur un contrôle
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CChronometreMFCDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	DRA::RelayoutDialog(
		AfxGetResourceHandle(), 
		this->m_hWnd, 
		DRA::GetDisplayMode() != DRA::Portrait ? 
		MAKEINTRESOURCE(IDD_CHRONOMETREMFC_DIALOG_WIDE) : 
		MAKEINTRESOURCE(IDD_CHRONOMETREMFC_DIALOG));
}
#endif



// Bouton Restart
void CChronometreMFCDlg::OnBnClickedButton1()
{
	v_parcours->stop();
	v_parcours = new Parcours();
	m_listBox.ResetContent();

	
	// on affiche le boutton restart
	m_bRestart.ShowWindow(FALSE);
	
	// on blocker le bouton start
	m_bStart.EnableWindow(TRUE);
	
	// on deblocker le bouton stop
	m_bStop.EnableWindow(FALSE);

	
	// on deblocker le bouton tour
	m_bTour.EnableWindow(FALSE);
	
	doUpdate();
	UpdateData(FALSE);
	//TODO affiache h dans 1 champ avec conditionnel
}


// Boutton STOP
void CChronometreMFCDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	if(v_parcours == NULL)
		v_parcours = new Parcours();
	v_parcours->stop();

	
	m_bRestart.ShowWindow(SW_SHOW);
	m_bRestart.EnableWindow(TRUE);

	// on deblocker le bouton start
	m_bStart.EnableWindow(TRUE);
	
	// on blocker le bouton stop
	m_bStop.EnableWindow(FALSE);
	
	// on blocker le bouton tour
	m_bTour.EnableWindow(FALSE);
	
	doUpdate();
	UpdateData(FALSE);
}

// Boutton START
void CChronometreMFCDlg::OnBnClickedButton3()
{
	// TODO : ajoutez ici le code de votre gestionnaire de notification de contrôle
	
	// creer le thread chronomètre initilialisé aux valeurs 
	if(v_parcours == NULL)
		v_parcours = new Parcours();
	v_parcours->start();


	// on affiche le boutton restart
	m_bRestart.ShowWindow(FALSE);
	m_bRestart.EnableWindow(FALSE);
	
	// on blocker le bouton start
	m_bStart.EnableWindow(FALSE);
	
	// on deblocker le bouton stop
	m_bStop.EnableWindow(TRUE);

	
	// on deblocker le bouton tour
	m_bTour.EnableWindow(TRUE);
	doUpdate();
	UpdateData(FALSE);
}

void CChronometreMFCDlg::doUpdate()
{
	Chronometre* v_chrono = v_parcours->getChronometre();
	if (v_chrono!=NULL) {	
		wstring str;
		string time = v_chrono->getCurrentTime()->formatShort();
		str.assign(time.begin(), time.end());
		m_sText.SetWindowText(str.c_str());
	} 
}
//Bouton tour
void CChronometreMFCDlg::OnBnClickedButton4()
{
	doUpdate();
	v_parcours->tour();
	wstring str;
	string etape = v_parcours->getLastEtape();
	str.assign(etape.begin(), etape.end());
	m_listBox.InsertString(0,str.c_str());
	UpdateData(FALSE);
}

void CChronometreMFCDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	CDialog::OnTimer(nIDEvent);
	UpdateData(FALSE);
	if(v_parcours != NULL){
		doUpdate();
	}
}

void CChronometreMFCDlg::OnStnClickedStatic0()
{
	// TODO: Add your control notification handler code here
}
