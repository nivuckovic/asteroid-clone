#include "ScreenManager.h"

ScreenManager::ScreenManager(Screen* initialScreen)
{
	m_currentScreen = initialScreen;
	m_currentScreen->setScreenManager(this);
	m_currentScreen->onEnter();
}

ScreenManager::~ScreenManager()
{
	if (m_currentScreen != nullptr) {
		m_currentScreen->onExit();
		delete m_currentScreen;
	}

	//..backup delete 
}

void ScreenManager::update()
{
	m_currentScreen->update();

	if (m_nextScreen != nullptr) {
		if (!m_isBackupRequested) {
			m_currentScreen->onExit();
			if (m_isResumeBackupScreen) {
				m_isResumeBackupScreen = false;
			}
			else {
				m_nextScreen->onEnter();
			}

			delete m_currentScreen;
		}
		else {
			delete m_backUpScreen;
			m_backUpScreen = m_currentScreen;
			m_nextScreen->onEnter();
		}
		
		m_currentScreen = m_nextScreen;
		m_nextScreen = nullptr;
	}
}

void ScreenManager::render()
{
	m_currentScreen->render();
}

void ScreenManager::setNextScreen(Screen* nextScreen, bool backupCurrentScreen)
{
	delete m_nextScreen;
	m_nextScreen = nextScreen;
	m_isBackupRequested = backupCurrentScreen;
	m_nextScreen->setScreenManager(this);
}

void ScreenManager::resumeBackupScreen()
{
	if (m_backUpScreen == nullptr) {
		if (m_currentScreen == nullptr) return;
		//...
		return;
	}

	setNextScreen(m_backUpScreen, false);
	m_backUpScreen = nullptr;
	m_isResumeBackupScreen = true;
}

void ScreenManager::requestQuit()
{
	m_requestQuit = true;
}

bool ScreenManager::isQuitRequested()
{
	return m_requestQuit;
}
