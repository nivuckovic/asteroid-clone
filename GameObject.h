#pragma once

#include <SDL.h>
#include "global.h"
#include "GameObjectType.h"

class Screen;

class GameObject
{
public:
	GameObject();

	virtual void update() = 0;
	virtual void render() = 0;

	virtual void drawDebugBox() = 0;

	virtual void setPosition(Point position);
	virtual void setPosition(float x, float y);
	virtual void setPositionX(float positionX);
	virtual void setPositionY(float positionY);
	virtual void setDisposed();

	float getRadius();
	void setRadius(float radius);

	void setSize(float width, float height);
	virtual void setScreen(Screen * screen);
	void setGameObjectType(GameObjectType type);

	virtual void startTimers();
	virtual void pauseTimers();

	virtual ~GameObject();

	Point getPosition();
	Point getSize();
	GameObjectType getGameObjectType();
	bool isDisposed();

protected:
	Screen * m_screen;
	Screen * getScreen();

private:
	Point m_position;
	Point m_size;
	GameObjectType m_gameObjectType;

	float m_radius;

	bool m_isDisposed = false;
};

