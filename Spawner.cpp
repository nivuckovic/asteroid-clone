#include "Spawner.h"

#include "LWindow.h"
#include "Enemy.h"
#include "Screen.h"
#include "HealthPowerUp.h"
#include "FirePowerUp.h"

Spawner::Spawner()
{
	setPosition(0, 0);
	setGameObjectType(GameObjectType::_Spawner);

	m_enemySpawnCooldown = 1000;

	startTimers();
}

void Spawner::update()
{
	//promjeniti
	if (m_enemySpawnTimer.getTicks() > m_enemySpawnCooldown) {
		createNewEnemy();

		m_enemySpawnTimer.restart();
	}

	if (randomFloat(0, 1) < 0.001f) {
		createNewHealthPowerUp();
	}

	if (randomFloat(0, 1) < 0.001f) {
		createNewFirePowerUp();
	}
}

void Spawner::render()
{
	//drawDebugBox();
}

void Spawner::splitEnemy(int type, Point center, Point direction)
{
	Enemy * enemy = createNewEnemy(type);
	enemy->setPosition(center);
	enemy->setDirection(direction);
}

Enemy* Spawner::createNewEnemy(int type)
{
	Enemy * enemy = new Enemy(this, type);
	m_screen->addObject(enemy);
	enemy->setScreen(m_screen);

	return enemy;
}

void Spawner::createNewHealthPowerUp()
{
	HealthPowerUp * healthPowerUp = new HealthPowerUp();
	m_screen->addObject(healthPowerUp);
	healthPowerUp->setScreen(m_screen);
}

void Spawner::createNewFirePowerUp()
{
	FirePowerUp * firePowerUp = new FirePowerUp();
	m_screen->addObject(firePowerUp);
	firePowerUp->setScreen(m_screen);
}

void Spawner::drawDebugBox()
{
	SDL_SetRenderDrawColor(LWindow::getRenderer(), 0xFF, 0xFF, 0xFF, 1);
	SDL_Rect rect = { getPosition().x , getPosition().y , 10, 10 };
	SDL_RenderDrawRect(LWindow::getRenderer(), &rect);
	SDL_SetRenderDrawColor(LWindow::getRenderer(), 0x00, 0x00, 0x00, 1);
}

void Spawner::startTimers()
{
	m_enemySpawnTimer.start();
}

void Spawner::pauseTimers()
{
	m_enemySpawnTimer.start();
}


Spawner::~Spawner()
{
}
