#include "HealthPowerUp.h"
#include "Player.h"

HealthPowerUp::HealthPowerUp()
{
	setTexture("Sprite/PNG/Power-ups/pill_red.png");
	setSize(getTexture()->getWidth(), getTexture()->getHeight());
	setAliveCooldown(3000);
	setRadius(15);
	PowerUp::PowerUp();
}

void HealthPowerUp::onPickUp(Player * player)
{
	player->addLife(50);
	PowerUp::onPickUp(player);
}


HealthPowerUp::~HealthPowerUp()
{
}
