#include "MovableGameObject.h"
#include <vector>
#include "Screen.h"

MovableGameObject::MovableGameObject()
{
}

void MovableGameObject::update()
{
	Point position;
	calculateNextPosition(position);
	setPosition(position);

	setVelocity(0, 0);
}

void MovableGameObject::calculateNextPosition(Point & nextPosition)
{
	Point nextVel;
	calculateNextVelocity(nextVel);
	Point currentPosition = getPosition();
	nextPosition.x = currentPosition.x + nextVel.x;
	nextPosition.y = currentPosition.y + nextVel.y;
}

void MovableGameObject::calculateNextVelocity(Point & nextVelocity)
{
	calculateUnboundVelocity(nextVelocity);
	boundVelocity(nextVelocity);
}

void MovableGameObject::calculateUnboundVelocity(Point & nextVelocity)
{
	
	nextVelocity.x = getVelocity().x + getAcceleration() * getDirection().x;
	nextVelocity.y = getVelocity().y + getAcceleration() * getDirection().y;
}

void MovableGameObject::boundVelocity(Point & nextVelocity)
{
	float length = vectorLength(nextVelocity);
	if (length > m_maxVelocity || length < -m_maxVelocity) {
		float coef = m_maxVelocity / length;
		nextVelocity.x *= coef;
		nextVelocity.y *= coef;
	}
}

void MovableGameObject::setVelocity(Point velocity)
{
	m_velocity = velocity;
}

void MovableGameObject::setVelocity(float x, float y)
{
	Point velocity(x, y);

	setVelocity(velocity);
}


void MovableGameObject::setAcceleration(float acceleration)
{
	m_acceleration = acceleration;
}

void MovableGameObject::addAcceleration(float acceleration)
{
	m_acceleration += acceleration;

	if (m_acceleration > m_maxAcceleration) {
		m_acceleration = m_maxAcceleration;
	}
	if (m_acceleration < -m_maxAcceleration) {
		m_acceleration = -m_maxAcceleration;
	}
}

void MovableGameObject::setMaxVelocity(float maxVelocity)
{
	m_maxVelocity = maxVelocity;
}

void MovableGameObject::setMaxAcceleration(float maxAcceleration)
{
	m_maxAcceleration = maxAcceleration;
}



Point MovableGameObject::getVelocity()
{
	return m_velocity;
}

float MovableGameObject::getAcceleration()
{
	return m_acceleration;
}

GameObject* MovableGameObject::checkCollisionByType(GameObjectType type)
{
	std::vector<GameObject*> * objects = m_screen->getObjectsByType(type);

	for (auto obj : *objects) {
		if (pointDistance(getPosition(), obj->getPosition()) < getRadius() + obj->getRadius()) {
			return obj;
		}
	}

	return nullptr;
}

MovableGameObject::~MovableGameObject()
{
	
}

