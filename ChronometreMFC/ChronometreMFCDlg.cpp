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
	, v_heure(0)
	, v_minute(0)
	, v_seconde(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChronometreMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT5, v_heure);
	DDX_Text(pDX, IDC_EDIT4, v_minute);
	DDV_MinMaxInt(pDX, v_minute, 0, 60);
	DDV_MinMaxInt(pDX, v_heure, 0, 24);
	DDX_Text(pDX, IDC_EDIT3, v_seconde);
	DDV_MinMaxInt(pDX, v_seconde, 0, 60);
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


void CChronometreMFCDlg::OnEnChangeEdit4()
{
	// TODO:  S'il s'agit d'un contrôle RICHEDIT, le contrôle ne
	// envoyez cette notification sauf si vous substituez CDialog::OnInitDialog()
	// fonction et appelle CRichEditCtrl().SetEventMask()
	// avec l'indicateur ENM_CHANGE ajouté au masque grâce à l'opérateur OR.

	// TODO:  Ajoutez ici le code de votre gestionnaire de notification de contrôle
}

void CChronometreMFCDlg::OnBnClickedButton1()
{
	// TODO : ajoutez ici le code de votre gestionnaire de notification de contrôle
	v_heure=0;
	v_minute=50;
	v_seconde=0;
	UpdateData(FALSE);
}

void CChronometreMFCDlg::OnBnClickedButton3()
{
	// TODO : ajoutez ici le code de votre gestionnaire de notification de contrôle
	
	// creer le thread chronomètre initilialisé aux valeurs 

}

void CChronometreMFCDlg::OnEnChangeEdit5()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
