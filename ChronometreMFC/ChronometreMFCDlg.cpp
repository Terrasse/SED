// ChronometreMFCDlg.cpp : fichier d'implémentation
#include "stdafx.h"
#include "ChronometreMFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Boîte de dialogue CChronometreMFCDlg

CChronometreMFCDlg::CChronometreMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChronometreMFCDlg::IDD, pParent)
	, v_parcours(NULL)
	, v_heure(0)
	, v_minute(0)
	, v_seconde(0)
	, v_ms(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChronometreMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Text(pDX, IDC_EDIT5, v_heure); -> IDC_STATIC5
	//DDX_Text(pDX, IDC_EDIT4, v_minute); -> IDC_STATIC6
	//DDX_Text(pDX, IDC_EDIT3, v_seconde); -> IDC_STATIC7
	//DDX_Text(pDX, IDC_EDIT6, v_ms); -> IDC_STATIC8
	DDX_Text(pDX, IDC_STATIC5, v_heure);
	DDX_Text(pDX, IDC_STATIC6, v_minute);
	DDX_Text(pDX, IDC_STATIC7, v_seconde);
	DDX_Text(pDX, IDC_STATIC8, v_ms);
	DDV_MinMaxInt(pDX, v_minute, 0, 60);
	DDV_MinMaxInt(pDX, v_heure, 0, 24);
	DDV_MinMaxInt(pDX, v_seconde, 0, 60);
	DDV_MinMaxInt(pDX, v_ms, 0, 1000);
    DDX_Control(pDX, IDC_LIST3, m_listBox);
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
	ON_STN_CLICKED(IDC_STATIC8, &CChronometreMFCDlg::OnStnClickedStatic8)
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
	Chronometre *c= new Chronometre();
	c->initThread();
	v_parcours = new Parcours(c);

	return TRUE;  // retourne TRUE, sauf si vous avez défini le focus sur un contrôle
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CChronometreMFCDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_CHRONOMETREMFC_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_CHRONOMETREMFC_DIALOG));
	}
}
#endif
// Boutton RESTART
void CChronometreMFCDlg::OnBnClickedButton1(){
	v_parcours->reset();
}
// Boutton STOP
void CChronometreMFCDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	v_parcours->stop();

		//// on hide le boutton restart
		//CWnd *pWnd = GetDlgItem( IDC_BUTTON1 );
		//pWnd->ShowWindow(SW_SHOW);
	
	doUpdate();
	UpdateData(FALSE);
}

// Boutton START
void CChronometreMFCDlg::OnBnClickedButton3()
{
	// TODO : ajoutez ici le code de votre gestionnaire de notification de contrôle
	
	v_parcours->start();

	// on affiche le boutton restart
	CWnd *pWnd = GetDlgItem( IDC_BUTTON1 );
	pWnd->ShowWindow(SW_SHOW);
	doUpdate();
	UpdateData(FALSE);
}

void CChronometreMFCDlg::doUpdate()
{
	Chronometre* v_chrono = v_parcours->getChronometre();
	if (v_chrono!=NULL) {
		Heure* tmp_heure=v_chrono->getCurrentTime();
		v_heure=tmp_heure->getHeure();
		v_minute=tmp_heure->getMinute();
		v_seconde=tmp_heure->getSeconde();
		v_ms=tmp_heure->getMilliseconde();
	} 
}

// Méthode tour
void CChronometreMFCDlg::OnBnClickedButton4()
{
	doUpdate();
	//v_parcours->tour();
	//string etape = v_parcours->getLastEtape();
	//wstring str;
	//str.assign(etape.begin(), etape.end());
	//m_listBox.InsertString(0,str.c_str());
	UpdateData(FALSE);
}

void CChronometreMFCDlg::OnStnClickedStatic8()
{
	// TODO: Add your control notification handler code here
}

