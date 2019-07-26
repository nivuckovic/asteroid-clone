#include "PowerUp.h"

PowerUp::PowerUp()
{
	startTimers();
	setGameObjectType(GameObjectType::_PowerUp);
	setPosition(randomPointOnScreen());
}

void PowerUp::update()
{
	if (m_aliveTimer.getTicks() >= m_aliveCooldown - 1000 && !isBlinking()) {
		startBlinking();
	}

	if (m_aliveTimer.getTicks() >= m_aliveCooldown) {
		setDisposed();
	}
	
	AnimatedGameObject::update();
}

void PowerUp::onPickUp(Player * player)
{
	setDisposed();
}

void PowerUp::startTimers()
{
	m_aliveTimer.start();
}

void PowerUp::pauseTimers()
{
	m_aliveTimer.stop();
}

int PowerUp::getAliveCooldown()
{
	return m_aliveCooldown;
}

void PowerUp::setAliveCooldown(int aliveCooldown)
{
	m_aliveCooldown = aliveCooldown;
}

PowerUp::~PowerUp()
{
}
