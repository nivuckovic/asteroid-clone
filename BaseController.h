#pragma once

#include "global.h"
#include <SDL.h>

class BaseController
{
public:
	BaseController();

	virtual void update();

	bool isWindowFocused();
	bool isActionLocked();

	~BaseController();

private:
	bool m_isWindowFocused;
	bool m_isActionLocked;
};

