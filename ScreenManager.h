#pragma once

#include "Screen.h"

class ScreenManager
{
public:
	ScreenManager(Screen* initialScreen);
	~ScreenManager();

	void update();
	void render();
	void setNextScreen(Screen* nextScreen, bool backupCurrentScreen);
	void resumeBackupScreen();

	void requestQuit();
	bool isQuitRequested();

private:
	Screen * m_currentScreen = nullptr;
	Screen * m_nextScreen = nullptr;
	Screen * m_backUpScreen = nullptr;
	
	bool m_requestQuit;
	bool m_isBackupRequested;
	bool m_isResumeBackupScreen;
};

