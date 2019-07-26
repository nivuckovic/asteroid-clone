#pragma once

#include "MovableGameObject.h"

class Projectile : public MovableGameObject
{
public:
	Projectile(Point position, Point direction, float rotation, int damage);

	void update() override;
	void render() override;

	void checkCollision();

	void startTimers() override;
	void pauseTimers() override;

	~Projectile();

private:
	int m_damage;
};

