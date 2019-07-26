#include "GameObject.h"

GameObject::GameObject()
{

}

void GameObject::update()
{
	//if mouseOver
}

void GameObject::render()
{
}

void GameObject::setPosition(Point position)
{
	m_position = position;
}

void GameObject::setPosition(float x, float y)
{
	Point position;
	position.x = x;
	position.y = y;

	setPosition(position);
}

void GameObject::setPositionX(float positionX)
{
}

void GameObject::setPositionY(float positionY)
{
}

void GameObject::setDisposed()
{
	m_isDisposed = true;
}

void GameObject::setSize(float width, float height)
{
	m_size.x = width;
	m_size.y = height;
}

void GameObject::setScreen(Screen * screen)
{
	m_screen = screen;
}

void GameObject::setGameObjectType(GameObjectType type)
{
	m_gameObjectType = type;
}

void GameObject::startTimers()
{
}

void GameObject::pauseTimers()
{
}


GameObjectType GameObject::getGameObjectType()
{
	return m_gameObjectType;
}

bool GameObject::isDisposed()
{
	return m_isDisposed;
}

Screen * GameObject::getScreen()
{
	return m_screen;
}

GameObject::~GameObject()
{
}

Point GameObject::getPosition()
{
	return m_position;
}

Point GameObject::getSize()
{
	return m_size;
}

void GameObject::setRadius(float radius)
{
	m_radius = radius;
}

float GameObject::getRadius()
{
	return m_radius;
}