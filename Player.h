#pragma once

#include "MovableGameObject.h"
#include "InputController.h"
#include "LTimer.h"
#include "HealthBar.h"

class Player : public MovableGameObject
{
public:
	Player();

	void update() override;
	void render() override;

	void handleInput();

	void checkCollision(Point oldPosition);

	void fireProjectile();

	void startTimers() override;
	void pauseTimers() override;
	void updateTimers();

	void addDamage(int damage);
	
	void setLife(int life);
	int getLife();
	void addLife(int life);

	void setScreen(Screen * screen) override;

	void setInvulnerable();
	bool getInvulnerable();
	bool isInvulnerable();

	void setHealthBar(HealthBar * healthBar);
	
	void powerUpAttack();

	~Player();

private:
	InputController * m_inputController;

	int m_life;
	bool m_invulnerable;

	HealthBar* m_healthBar;

	std::vector<LTimer*> m_timers;

	LTimer m_fireCooldownTimer;
	int m_fireCooldown;

	LTimer m_invulnerableTimer;
	int m_invulnerableCooldown;
	
	LTimer m_firePowerUpTimer;
	int m_firePowerUpCooldown;
	bool m_firePowerUpBool;

	LTexture m_damageTexture[3];
};

