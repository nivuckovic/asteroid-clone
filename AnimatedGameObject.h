#pragma once

#include "GameObject.h"
#include "LTexture.h"

class AnimatedGameObject : public GameObject
{
public:
	AnimatedGameObject();
	~AnimatedGameObject();

	virtual void render() override;
	virtual void update() override;

	void drawDebugBox() override;

	virtual void rotate(float angle = 0);
	void rotateDirection(float angle);

	void setRotation(float angle);
	float getRotation();

	void setDirection(Point direction);
	void setDirection(float x, float y);

	void startBlinking();
	void stopBlinking();
	bool isBlinking();

	void setAlpha(int alpha);

	float getAngle();
	int getAlpha();

	void updateAlpha();

	void setTexture(std::string path);
	Point getDirection();

protected:
	LTexture * getTexture();
private:
	LTexture m_texture;

	float m_angle;
	Point m_direction;

	bool m_blinking;

	int m_alpha;
	int m_alphaIncrement;
};

