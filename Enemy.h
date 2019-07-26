#pragma once

#include "MovableGameObject.h"
#include "Spawner.h"

class Enemy : public MovableGameObject
{
public:
	Enemy(Spawner * spawner, int m_type = 0);

	void update() override;
	void render() override;

	void checkCollision();

	void setLife(int life);

	void addDamage(int damage);
	void setDamage(int damage);
	int getDamage();

	void split();

	void startTimers() override;
	void pauseTimers() override;

	void setSpawner(Spawner * spawner);
	
	//vjerojatno bolje virtual napraviti
	void setDead();

	~Enemy();

private:
	Spawner * m_spawner;

	int m_life;
	int m_type;
	int m_damage;

	void getConfig(int type);
	void setSpawnPosition(Point center, float radius);
};

