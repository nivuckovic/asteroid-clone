#include "FirePowerUp.h"

#include "Player.h"

FirePowerUp::FirePowerUp()
{
	setTexture("Sprite/PNG/Power-ups/powerupBlue_bolt.png");
	setSize(getTexture()->getWidth(), getTexture()->getHeight());
	setAliveCooldown(2500);
	setRadius(20);
	PowerUp::PowerUp();
}

void FirePowerUp::onPickUp(Player * player)
{
	player->powerUpAttack();
	PowerUp::onPickUp(player);
}


FirePowerUp::~FirePowerUp()
{
}
