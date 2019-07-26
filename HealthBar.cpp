#include "HealthBar.h"

#include "LWindow.h"

HealthBar::HealthBar()
{
	setGameObjectType(GameObjectType::_GUI);
	m_barWidth = 300;
	m_barHeight = 25;
	m_bar = { 0 + 25, LWindow::SCREEN_HEIGHT - m_barHeight - 25, m_barWidth, m_barHeight};
}

void HealthBar::drawDebugBox()
{
}

void HealthBar::render()
{
	SDL_SetRenderDrawColor(LWindow::getRenderer(), 0xDD, 0x00, 0x00, 1);

	SDL_RenderFillRect(LWindow::getRenderer(), &m_bar);

	SDL_SetRenderDrawColor(LWindow::getRenderer(), 0x00, 0x00, 0x00, 1);
}

void HealthBar::update()
{
	updateHealthBar();
}

void HealthBar::updateHealthBar()
{
	m_bar.w = static_cast<int>(m_barWidth * static_cast<float>(m_currentHP) / m_maxHP);
}

void HealthBar::startTimers()
{
}

void HealthBar::pauseTimers()
{
}

void HealthBar::setCurrentHP(int hp)
{
	m_currentHP = hp;
}

void HealthBar::setmaxHP(int hp)
{
	m_maxHP = hp;
}


HealthBar::~HealthBar()
{
}
