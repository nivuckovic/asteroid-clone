#include "Game.h"

#include "LevelScreen.h"
#include "MenuScreen.h"
#include "Player.h" 
#include "Enemy.h"
#include <memory>
#include "LTimer.h"

Game::Game()
{
	m_LWindow = new LWindow();
	
	//test
	/*
	Level* level1 = new Level();
	LevelScreen * levelScreen = new LevelScreen(level1);
	level1->setScreen(levelScreen);
	level1->onEnter();
	*/

	MenuScreen* m_menuScreen = new MenuScreen();
	m_menuScreen->onEnter();

	m_screenManager = new ScreenManager(m_menuScreen);

	m_inputController = InputController::getInstance();

	m_isRunning = true;
}

void Game::run()
{
	while (m_isRunning) {
		m_inputController->update();
		pollEvents();

		m_screenManager->update();
		if (m_screenManager->isQuitRequested()) {
			m_isRunning = false;
		}

		SDL_RenderClear(LWindow::getRenderer());
		m_screenManager->render();
		SDL_RenderPresent(LWindow::getRenderer());
	}
}

Game::~Game()
{
	delete m_screenManager;
	delete m_LWindow;
}

void Game::pollEvents()
{
	SDL_Event m_event;

	while (SDL_PollEvent(&m_event) != 0) {
		if (m_event.type == SDL_QUIT) {
			m_screenManager->requestQuit();
		}
	}
}
