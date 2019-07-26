#include "MenuScreen.h"
#include "ScreenManager.h"

#include "Level.h"
#include "Player.h"
#include "LevelScreen.h"
#include "Button.h"
#include "Background.h"

MenuScreen::MenuScreen()
{
	m_inputController = InputController::getInstance();
}

void MenuScreen::update()
{
	updateObjects(GameObjectType::_GUI);
}

void MenuScreen::render()
{
	for (auto vec : *getObjects()) {
		for (auto obj : vec) {
			obj->render();
		}
	}
}

void MenuScreen::onEnter()
{
	addObject(new Button(Key::Menu, std::bind(&MenuScreen::onExit, this)));
	addObject(new Button(Key::Fire, std::bind(&MenuScreen::onNewGame, this)));
	
	Background* background = new Background("Sprite/Backgrounds/background_main.png");
	addObject(background);
	background->setScreen(this);

	Screen::onEnter();
}

void MenuScreen::onExit()
{
	m_screenManager->requestQuit();
}

void MenuScreen::onNewGame()
{
	Level* level1 = new Level();
	LevelScreen * levelScreen = new LevelScreen(level1);
	level1->setScreen(levelScreen);
	level1->onEnter();

	m_screenManager->setNextScreen(levelScreen, false);
}


MenuScreen::~MenuScreen()
{
}
