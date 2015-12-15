// ChronometreMFCDlg.cpp : fichier d'impl�mentation
//

#include "stdafx.h"
#include "ChronometreMFC.h"
#include "ChronometreMFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Bo�te de dialogue CChronometreMFCDlg

CChronometreMFCDlg::CChronometreMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChronometreMFCDlg::IDD, pParent)
	, v_chrono(NULL)
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
	DDX_Text(pDX, IDC_EDIT5, v_heure);
	DDX_Text(pDX, IDC_EDIT4, v_minute);
	DDX_Text(pDX, IDC_EDIT3, v_seconde);
	DDX_Text(pDX, IDC_EDIT6, v_ms);
	DDV_MinMaxInt(pDX, v_minute, 0, 60);
	DDV_MinMaxInt(pDX, v_heure, 0, 24);
	DDV_MinMaxInt(pDX, v_seconde, 0, 60);
	DDV_MinMaxInt(pDX, v_ms, 0, 1000);
}

BEGIN_MESSAGE_MAP(CChronometreMFCDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_EDIT4, &CChronometreMFCDlg::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON1, &CChronometreMFCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CChronometreMFCDlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT5, &CChronometreMFCDlg::OnEnChangeEdit5)
	ON_BN_CLICKED(IDC_BUTTON2, &CChronometreMFCDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CChronometreMFCDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// Gestionnaires de messages pour CChronometreMFCDlg

BOOL CChronometreMFCDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// D�finir l'ic�ne de cette bo�te de dialogue. L'infrastructure effectue cela automatiquement
	//  lorsque la fen�tre principale de l'application n'est pas une bo�te de dialogue
	SetIcon(m_hIcon, TRUE);			// D�finir une grande ic�ne
	SetIcon(m_hIcon, FALSE);		// D�finir une petite ic�ne

	// TODO�: ajoutez ici une initialisation suppl�mentaire
	
	return TRUE;  // retourne TRUE, sauf si vous avez d�fini le focus sur un contr�le
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


void CChronometreMFCDlg::OnEnChangeEdit4()
{
	// TODO:  S'il s'agit d'un contr�le RICHEDIT, le contr�le ne
	// envoyez cette notification sauf si vous substituez CDialog::OnInitDialog()
	// fonction et appelle CRichEditCtrl().SetEventMask()
	// avec l'indicateur ENM_CHANGE ajout� au masque gr�ce � l'op�rateur OR.

	// TODO:  Ajoutez ici le code de votre gestionnaire de notification de contr�le
}




void CChronometreMFCDlg::OnEnChangeEdit5()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

// Boutton restart
void CChronometreMFCDlg::OnBnClickedButton1()
{
	// TODO : ajoutez ici le code de votre gestionnaire de notification de contr�le
	
	v_chrono=new Chronometre();
	doUpdate();
	v_chrono->start();
	UpdateData(FALSE);
}


// Boutton STOP
void CChronometreMFCDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	if (v_chrono!=NULL) {
		v_chrono->stop();

		// on hide le boutton restart
		CWnd *pWnd = GetDlgItem( IDC_BUTTON1 );
		pWnd->ShowWindow(SW_SHOW);
	}
	doUpdate();
	UpdateData(FALSE);
}

// Boutton START
void CChronometreMFCDlg::OnBnClickedButton3()
{
	// TODO : ajoutez ici le code de votre gestionnaire de notification de contr�le
	
	// creer le thread chronom�tre initilialis� aux valeurs 
	if (v_chrono != NULL){
		v_chrono->start();
	}
	else{
		v_chrono=new Chronometre();
		v_chrono->start();
	}


	// on affiche le boutton restart
	CWnd *pWnd = GetDlgItem( IDC_BUTTON1 );
	pWnd->ShowWindow(SW_SHOW);
	doUpdate();
	UpdateData(FALSE);
}

void CChronometreMFCDlg::doUpdate()
{
	if (v_chrono!=NULL) {
		Heure* tmp_heure=v_chrono->getCurrentTime();
		v_heure=tmp_heure->getHeure();
		v_minute=tmp_heure->getMinute();
		v_seconde=tmp_heure->getSeconde();
		v_ms=tmp_heure->getMilliseconde();
	} 
}

void CChronometreMFCDlg::OnBnClickedButton4()
{
	doUpdate();
	UpdateData(FALSE);
}
