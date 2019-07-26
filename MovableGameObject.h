#pragma once

#include "AnimatedGameObject.h"
#include "LTexture.h"
#include <string>
#include "global.h"


class MovableGameObject : public virtual AnimatedGameObject
{
public:
	MovableGameObject();

	virtual void update() override;

	void calculateNextPosition(Point& nextPosition);
	void calculateNextVelocity(Point& nextVelocity);
	void calculateUnboundVelocity(Point& nextVelocity);
	void boundVelocity(Point& nextVelocity);

	void setVelocity(Point velocity);
	void setVelocity(float x, float y);

	void setAcceleration(float acceleration);
	void addAcceleration(float acceleration);
	void setMaxVelocity(float maxVelocity);
	void setMaxAcceleration(float maxAcceleration);

	Point getVelocity();
	float getAcceleration();

	GameObject * checkCollisionByType(GameObjectType type);

	~MovableGameObject();
protected:

private:
	Point m_velocity;

	float m_acceleration;

	float m_maxVelocity;
	float m_maxAcceleration;
};

