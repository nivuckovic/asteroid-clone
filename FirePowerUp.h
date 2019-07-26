#pragma once

#include "PowerUp.h"

class Player;

class FirePowerUp : public PowerUp
{
public:
	FirePowerUp();

	void onPickUp(Player * player) override;

	~FirePowerUp();
};

