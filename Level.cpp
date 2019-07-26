#include "Level.h"

#include "Player.h"
#include "Enemy.h"
#include "Spawner.h"
#include "Background.h"

Level::Level()
{

}

void Level::setScreen(Screen * screen)
{
	m_screen = screen;
}

void Level::onEnter()
{
	//test
	Player * player = new Player();
	m_screen->addObject(player);
	player->setScreen(m_screen);

	Spawner * spawner = new Spawner();
	m_screen->addObject(spawner);
	spawner->setScreen(m_screen);

	Background * background = new Background("Sprite/Backgrounds/background_purple.png");
	m_screen->addObject(background);
	background->setScreen(m_screen);
}


Level::~Level()
{
}
