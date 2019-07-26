#include "BaseController.h"

BaseController::BaseController()
{
}

void BaseController::update()
{
	//m_isWindowFocusd = window->isfocused()?
}

bool BaseController::isWindowFocused()
{
	return m_isWindowFocused;
}

bool BaseController::isActionLocked()
{
	return m_isActionLocked;
}


BaseController::~BaseController()
{
}
