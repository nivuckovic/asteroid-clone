#pragma once

#include "PowerUp.h"

class Player;

class HealthPowerUp : public PowerUp
{
public:
	HealthPowerUp();

	void onPickUp(Player * player) override;

	~HealthPowerUp();
};

