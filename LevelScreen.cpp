#include "LevelScreen.h"

#include "MenuScreen.h"
#include "ScreenManager.h"

LevelScreen::LevelScreen(Level* level)
{
	m_currentLevel = level;
}

void LevelScreen::update()
{
	updateObjects(GameObjectType::_Player);
	updateObjects(GameObjectType::_Enemy);
	updateObjects(GameObjectType::_Projectile);
	updateObjects(GameObjectType::_PowerUp);
	updateObjects(GameObjectType::_Spawner);
	updateObjects(GameObjectType::_GUI);

	checkGameOver();

	Screen::update();
}

void LevelScreen::render()
{
	//trebas ovo promjeniti ako zelis da imas mogucnost odredivanja render layera
	for (auto vec : *getObjects()) {
		for (auto obj : vec) {
			obj->render();
		}
	}
}

void LevelScreen::onEnter()
{
	Screen::onEnter();
}

void LevelScreen::onExit()
{
	Screen::onExit();
}

void LevelScreen::setGameOver(bool gameOver)
{
	m_isGameOver = gameOver;
}

void LevelScreen::checkGameOver()
{
	if (m_isGameOver) {
		MenuScreen * menuScreen = new MenuScreen();
		menuScreen->setScreenManager(m_screenManager);

		m_screenManager->setNextScreen(menuScreen, false);
	}
}


LevelScreen::~LevelScreen()
{
}
