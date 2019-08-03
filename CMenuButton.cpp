#pragma once

#include "stdafx.h"

enum COLORS
{
	ID_YELLOW = 1,
	ID_GREEN,
	ID_WHITE,
	ID_VIOLET,
	ID_BLUE,
	ID_NO
};

class CMenuButton : public CMFCButton
{
public:
	COLORS m_color = ID_NO;
};
