
// ChessCube.h : главный файл заголовка для приложения ChessCube
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CChessCubeApp:
// О реализации данного класса см. ChessCube.cpp
//

class CChessCubeApp : public CWinApp
{
public:
	CChessCubeApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CChessCubeApp theApp;
