#pragma once

#include "InputController.h"
#include "LWindow.h"
#include "ScreenManager.h"

class Game
{
public:
	Game();

	void run();
	
	~Game();
private:
	LWindow * m_LWindow;
	ScreenManager * m_screenManager = nullptr;
	InputController * m_inputController;

	bool m_isRunning;

	void pollEvents();
};

