#pragma once

#include "GameObject.h"
#include "LTimer.h"

class Enemy;

class Spawner : public GameObject
{
public:
	Spawner();

	void update() override;
	void render() override;

	void splitEnemy(int type, Point center, Point direction);
	Enemy* createNewEnemy(int type = 0);
	
	void createNewHealthPowerUp();
	void createNewFirePowerUp();

	void drawDebugBox();

	void startTimers() override;
	void pauseTimers() override;

	~Spawner();
private:
	LTimer m_enemySpawnTimer;
	float m_enemySpawnCooldown;
};

