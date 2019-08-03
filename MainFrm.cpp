
// MainFrm.cpp : реализация класса CMainFrame
//
#pragma once 

#include "stdafx.h"
#include "ChessCube.h"
#include "CMenuButton.cpp"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define  FACT  120

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_PAINT()
	ON_BN_CLICKED(ID_BT0, OnControlButtonDown)
	ON_COMMAND_RANGE(ID_BT1, ID_BT25, OnButtonDown)
	ON_COMMAND_RANGE(ID_YELLOW, ID_NO, OnMenuItemSelect)
END_MESSAGE_MAP()

// создание/уничтожение CMainFrame

CMainFrame::CMainFrame()
{
	m_menu.CreatePopupMenu();
	m_menu.AppendMenu(MF_STRING, ID_YELLOW, L"Желтый");
	m_menu.AppendMenu(MF_STRING, ID_GREEN, L"Зеленый");
	m_menu.AppendMenu(MF_STRING, ID_WHITE, L"Белый");
	m_menu.AppendMenu(MF_STRING, ID_VIOLET, L"Фиолетовый");
	m_menu.AppendMenu(MF_STRING, ID_BLUE, L"Синий");
	m_menu.AppendMenu(MF_STRING, ID_NO, L"[нет]");
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	this->buttID = 0;

	CRect* rct = new CRect();
	GetWindowRect(rct);
	SetWindowPos(&wndTopMost, rct->right/2, rct->bottom/2, 249, 326, NULL);
	SIZE btn_size;
	btn_size.cx = btn_size.cy = 40;

	m_ctrl.Create(L"Рассчитать", WS_CHILD | WS_VISIBLE | BS_FLAT, CRect(CPoint(1, 240), CSize(228,44)), this, ID_BT0);

	m_bt[0].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(5, 5), btn_size), this, ID_BT1);
	m_bt[1].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(50, 5), btn_size), this, ID_BT2);
	m_bt[2].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(95, 5), btn_size), this, ID_BT3);
	m_bt[3].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(140, 5), btn_size), this, ID_BT4);
	m_bt[4].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(185, 5), btn_size), this, ID_BT5);
	
	m_bt[5].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(5, 50), btn_size), this, ID_BT6);
	m_bt[6].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(50, 50), btn_size), this, ID_BT7);
	m_bt[7].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(95, 50), btn_size), this, ID_BT8);
	m_bt[8].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(140, 50), btn_size), this, ID_BT9);
	m_bt[9].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(185, 50), btn_size), this, ID_BT10);

	m_bt[10].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(5, 95), btn_size), this, ID_BT11);
	m_bt[11].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(50, 95), btn_size), this, ID_BT12);
	m_bt[12].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(95, 95), btn_size), this, ID_BT13);
	m_bt[13].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(140, 95), btn_size), this, ID_BT14);
	m_bt[14].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(185, 95), btn_size), this, ID_BT15);

	m_bt[15].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(5, 140), btn_size), this, ID_BT16);
	m_bt[16].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(50, 140), btn_size), this, ID_BT17);
	m_bt[17].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(95, 140), btn_size), this, ID_BT18);
	m_bt[18].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(140, 140), btn_size), this, ID_BT19);
	m_bt[19].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(185, 140), btn_size), this, ID_BT20);

	m_bt[20].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(5, 185), btn_size), this, ID_BT21);
	m_bt[21].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(50, 185), btn_size), this, ID_BT22);
	m_bt[22].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(95, 185), btn_size), this, ID_BT23);
	m_bt[23].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(140, 185), btn_size), this, ID_BT24);
	m_bt[24].Create(NULL, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP | BS_FLAT, CRect(CPoint(185, 185), btn_size), this, ID_BT25);

	for (int i = 0; i < 25; i++)
	{
		m_bt[i].SetFaceColor(RGB(220, 220, 220), false);
		m_bt[i].m_color = ID_NO;
		m_bt[i].SetWindowText(L"?");
	}
	this->UpdateWindow();
	return 0;
}

void CMainFrame::OMG(UINT i, UINT j)
{
	UINT a = 5 * j + i;
	if (this->m_bt[a].m_color == ID_NO)
	{
		UINT count_i = 0;
		UINT notFACT = 1;
		for (int mi = 0; mi < 5; mi++)
			if (this->m_bt[5 * j + mi].m_color == ID_NO)
				count_i++;
			else
				notFACT *= this->m_bt[5 * j + mi].m_color;
		if (count_i == 1)
			for (int mi = 0; mi < 5; mi++)
				if (this->m_bt[5 * j + mi].m_color == ID_NO)
				{
					this->buttID = a;
					OnMenuItemSelect((FACT / notFACT));
					break;
				}
				else
					continue;
		else if (count_i == 2)
		{
			UINT c1 = 0, c2 = 0;
			CPoint p1, p2;
			p1.SetPoint(-1, -1);
			p2.SetPoint(-1, -1);
			for (int mi = 0; mi < 5; mi++)
				if (this->m_bt[5 * j + mi].m_color == ID_NO)
				{
					if (p1.x != -1)
						p2 = CPoint(mi, j);
					else
						p1 = CPoint(mi, j);
				}
			for (int icol = 1; icol < 6; icol++)
			{
				BOOL be = FALSE;
				for (int mi = 0; mi < 5; mi++)
					if (this->m_bt[5 * j + mi].m_color == icol)
					{
						be = TRUE;
						break;
					}
				if (!be)
					if (c1 != 0)
						c2 = icol;
					else
						c1 = icol;
			}
			UINT count_j = 0;
			BOOL rly = FALSE;
			for (int mj = 0; mj < 5; mj++)
				if (this->m_bt[5 * mj + p1.x].m_color == ID_NO)
					count_j++;
			for (int mj = 0; mj < 5; mj++)
			{
				if (this->m_bt[5 * mj + p1.x].m_color == c1)
				{
					this->buttID = 5 * p1.y + p1.x;
					OnMenuItemSelect(c2);
					rly = TRUE;
					this->buttID = 5 * p2.y + p2.x;
					OnMenuItemSelect(c1);
				}
				if (this->m_bt[5 * mj + p1.x].m_color == c2)
				{
					this->buttID = 5 * p1.y + p1.x;
					OnMenuItemSelect(c1);
					rly = TRUE;
					this->buttID = 5 * p2.y + p2.x;
					OnMenuItemSelect(c2);
				}
			}
			for (int mj = 0; mj < 5; mj++)
			{
				if (rly)
					break;
				if (this->m_bt[5 * mj + p2.x].m_color == c1)
				{
					this->buttID = 5 * p2.y + p2.x;
					OnMenuItemSelect(c2);
					rly = TRUE;
					this->buttID = 5 * p1.y + p1.x;
					OnMenuItemSelect(c1);
				}
				if (this->m_bt[5 * mj + p2.x].m_color == c2)
				{
					this->buttID = 5 * p2.y + p2.x;
					OnMenuItemSelect(c1);
					rly = TRUE;
					this->buttID = 5 * p1.y + p1.x;
					OnMenuItemSelect(c2);
				}
			}
		}
		else
		{
			UINT count_j = 0;
			UINT notFACT = 1;
			for (int mj = 0; mj < 5; mj++)
				if (this->m_bt[5 * mj + i].m_color == ID_NO)
					count_j++;
				else
					notFACT *= this->m_bt[5 * mj + i].m_color;
			if (count_j == 1)
				for (int mj = 0; mj < 5; mj++)
					if (this->m_bt[5 * mj + i].m_color == ID_NO)
					{
						this->buttID = a;
						OnMenuItemSelect((FACT / notFACT));
						break;
					}
					else
						continue;
			else if (count_j == 2)
			{
				UINT c1 = 0, c2 = 0;
				CPoint p1, p2;
				p1.SetPoint(-1, -1);
				p2.SetPoint(-1, -1);
				for (int mj = 0; mj < 5; mj++)
					if (this->m_bt[5 * mj + i].m_color == ID_NO)
					{
						if (p1.x != -1)
							p2 = CPoint(i, mj);
						else
							p1 = CPoint(i, mj);
					}
				for (int icol = 1; icol < 6; icol++)
				{
					BOOL be = FALSE;
					for (int mj = 0; mj < 5; mj++)
						if (this->m_bt[5 * mj + i].m_color == icol)
						{
							be = TRUE;
							break;
						}
					if (!be)
						if (c1 != 0)
							c2 = icol;
						else
							c1 = icol;
				}
				UINT count_i2 = 0;
				BOOL rly = FALSE;
				for (int mi = 0; mi < 5; mi++)
					if (this->m_bt[5 * p1.y + mi].m_color == ID_NO)
						count_i2++;
				for (int mi = 0; mi < 5; mi++)
				{
					if (this->m_bt[5 * p1.y + mi].m_color == c1)
					{
						this->buttID = 5 * p1.y + p1.x;
						OnMenuItemSelect(c2);
						rly = TRUE;
						this->buttID = 5 * p2.y + p2.x;
						OnMenuItemSelect(c1);
					}
					if (this->m_bt[5 * p1.y + mi].m_color == c2)
					{
						this->buttID = 5 * p1.y + p1.x;
						OnMenuItemSelect(c1);
						rly = TRUE;
						this->buttID = 5 * p2.y + p2.x;
						OnMenuItemSelect(c2);
					}
				}
				for (int mi = 0; mi < 5; mi++)
				{
					if (rly)
						break;
					if (this->m_bt[5 * p2.y + mi].m_color == c1)
					{
						this->buttID = 5 * p2.y + p2.x;
						OnMenuItemSelect(c2);
						rly = TRUE;
						this->buttID = 5 * p1.y + p1.x;
						OnMenuItemSelect(c1);
					}
					if (this->m_bt[5 * p2.y + mi].m_color == c2)
					{
						this->buttID = 5 * p2.y + p2.x;
						OnMenuItemSelect(c1);
						rly = TRUE;
						this->buttID = 5 * p1.y + p1.x;
						OnMenuItemSelect(c2);
					}
				}
			}
		}
	}
}

void CMainFrame::OnControlButtonDown()
{
	try
	{
		UINT debug = 0;
		for (int i = 0; i < 25; i++)
			if (this->m_bt[i].m_color == ID_NO)
				debug++;
		if (debug > 12)
			throw 1;
		INT i = 0, j = 0, prev_i = -1, prev_j = 0;
		OMG(i, j);
		INT min_i = 0, max_i = 4, min_j = 0, max_j = 4;
		for (int u = 0; u < 24; u++)
		{
			INT bpi = i, bpj = j;
			if (i - prev_i != 0 && j - prev_j == 0)
				if ((i - prev_i == 1 && i != max_i) || (i - prev_i == -1 && i != min_i))
					i += i - prev_i;
				else
				{
					j == min_j ? j++ : j--;
					i == max_i ? min_j++ : max_j--;
				}
			else if (i - prev_i == 0 && j - prev_j !=0)
				if ((j - prev_j == 1 && j != max_j) || (j - prev_j == -1 && j != min_j))
					j += j - prev_j;
				else
				{
					i == min_i ? i++ : i--;
					j == max_j ? max_i-- : min_i++;
				}
			prev_i = bpi;
			prev_j = bpj;
			OMG(i, j);
		}
	}
	catch(...)
	{
		MessageBox(L"Недостаточно сведений для заполнения поля!",L"ОШИБКА");
	}
}

void CMainFrame::OnButtonDown(UINT uId)
{
	uId %= 3001;
	this->buttID = uId;
	POINT current_point;
	GetCursorPos(&current_point);
	m_menu.TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, current_point.x, current_point.y, this);
}

void CMainFrame::OnMenuItemSelect(UINT uId)
{
	m_bt[this->buttID].SetWindowText(L"");
	switch (uId)
	{
	case ID_YELLOW :
		m_bt[this->buttID].SetFaceColor(RGB(255, 216, 0), true);
		m_bt[this->buttID].m_color = ID_YELLOW;	break;
	case ID_GREEN :
		m_bt[this->buttID].SetFaceColor(RGB(76, 255, 0), true);
		m_bt[this->buttID].m_color = ID_GREEN;	break;
	case ID_WHITE:
		m_bt[this->buttID].SetFaceColor(RGB(255, 255, 255), true);
		m_bt[this->buttID].m_color = ID_WHITE;	break;
	case ID_VIOLET:
		m_bt[this->buttID].SetFaceColor(RGB(178, 0, 255), true);
		m_bt[this->buttID].m_color = ID_VIOLET; break;
	case ID_BLUE:
		m_bt[this->buttID].SetFaceColor(RGB(0, 148, 255), true);
		m_bt[this->buttID].m_color = ID_BLUE; break;
	case ID_NO:
		m_bt[this->buttID].SetFaceColor(RGB(220, 220, 220), true);
		m_bt[this->buttID].m_color = ID_NO;
		m_bt[this->buttID].SetWindowText(L"?");	break;
	}
	
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		 | WS_SYSMENU;
	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);
	//cs.lpszClass = AfxRegisterWndClass(0);
	if (cs.hMenu != NULL)
	{
		DestroyMenu(cs.hMenu);
		cs.hMenu = NULL;
	}
	return TRUE;
}

// диагностика CMainFrame

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// обработчики сообщений CMainFrame

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// передача фокуса окну представления

}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	
	// в противном случае выполняется обработка по умолчанию
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);}



void CMainFrame::OnPaint()
{
	CPaintDC dc(this);
}