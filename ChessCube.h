
// ChessCube.h : ������� ���� ��������� ��� ���������� ChessCube
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CChessCubeApp:
// � ���������� ������� ������ ��. ChessCube.cpp
//

class CChessCubeApp : public CWinApp
{
public:
	CChessCubeApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CChessCubeApp theApp;
