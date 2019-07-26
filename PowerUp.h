#pragma once

#include "AnimatedGameObject.h"
#include "LTimer.h"


class Player;

class PowerUp : public AnimatedGameObject
{
public:
	PowerUp();

	void update() override;

	virtual void onPickUp(Player * player);

	void startTimers() override;
	void pauseTimers() override;

	int getAliveCooldown();
	void setAliveCooldown(int aliveCooldown);

	~PowerUp();
private:
	LTimer m_aliveTimer;
	int m_aliveCooldown;

};

