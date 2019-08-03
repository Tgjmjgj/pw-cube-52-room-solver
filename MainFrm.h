
// MainFrm.h : интерфейс класса CMainFrame
//

#pragma once

#include "stdafx.h"
#include "CMenuButton.cpp"



class CMainFrame : public CFrameWnd
{
	
public:
	CMainFrame();
protected: 
	DECLARE_DYNAMIC(CMainFrame)

// Атрибуты
public:
	CMenu m_menu;
	BOOL isMenuOpen = false;
	UINT buttID;
	CButton m_ctrl;

	CMenuButton m_bt[25];

	enum
	{
		ID_BT0 = 3000,
		ID_BT1,
		ID_BT2,
		ID_BT3,
		ID_BT4,
		ID_BT5,
		ID_BT6,
		ID_BT7,
		ID_BT8,
		ID_BT9,
		ID_BT10,
		ID_BT11,
		ID_BT12,
		ID_BT13,
		ID_BT14,
		ID_BT15,
		ID_BT16,
		ID_BT17,
		ID_BT18,
		ID_BT19,
		ID_BT20,
		ID_BT21,
		ID_BT22,
		ID_BT23,
		ID_BT24,
		ID_BT25
	};
	
// Операции
public:
	void OMG(UINT i, UINT j);
	void OnControlButtonDown();
	void OnButtonDown(UINT nId);
	void OnMenuItemSelect(UINT nId);
	afx_msg void OnPaint();
// Переопределение
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

// Реализация
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Созданные функции схемы сообщений
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	DECLARE_MESSAGE_MAP()

};


