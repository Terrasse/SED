// ChronometreMFC.h�: fichier d'en-t�te principal pour l'application PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#ifdef POCKETPC2003_UI_MODEL
#include "resourceppc.h"
#endif 

// CChronometreMFCApp:
// Consultez ChronometreMFC.cpp pour l'impl�mentation de cette classe
//

class CChronometreMFCApp : public CWinApp
{
public:
	CChronometreMFCApp();
	
// Substitutions
public:
	virtual BOOL InitInstance();

// Impl�mentation

	DECLARE_MESSAGE_MAP()
};

extern CChronometreMFCApp theApp;

