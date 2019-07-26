#pragma once
#include "GameObject.h"

class HealthBar : public GameObject
{
public:
	HealthBar();

	void drawDebugBox() override;

	void render() override;
	void update() override;

	void updateHealthBar();

	void startTimers() override;
	void pauseTimers() override;

	void setCurrentHP(int hp);
	void setmaxHP(int hp);

	~HealthBar();
private:
	int m_currentHP;
	int m_maxHP;

	SDL_Rect m_bar;
	int m_barWidth;
	int m_barHeight;
};

