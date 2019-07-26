#include "AnimatedGameObject.h"



AnimatedGameObject::AnimatedGameObject()
{
	setAlpha(255);
	m_alphaIncrement = -1;
}


AnimatedGameObject::~AnimatedGameObject()
{
}

void AnimatedGameObject::render()
{
	m_texture.render(getPosition().x - getSize().x / 2, getPosition().y - getSize().y / 2, nullptr, m_angle);

	drawDebugBox();
}

void AnimatedGameObject::update()
{
	if (!isBlinking()) {
		setAlpha(255);
	}
	else {
		updateAlpha();
	}

	getTexture()->setAlpha(getAlpha());
}

void AnimatedGameObject::drawDebugBox()
{
	SDL_SetRenderDrawColor(LWindow::getRenderer(), 0xFF, 0xFF, 0xFF, 1);
	//circle
	int amount = 50;
	float angle = 2 * M_PI / amount;
	for (int i = 0; i < amount; ++i) {

		SDL_RenderDrawPoint(LWindow::getRenderer(), getPosition().x + getRadius() * cos(angle * i), getPosition().y + getRadius() * sin(angle * i));
	}
	SDL_SetRenderDrawColor(LWindow::getRenderer(), 0x00, 0x00, 0x00, 1);
}

void AnimatedGameObject::setDirection(Point direction)
{
	m_direction = direction;
}

void AnimatedGameObject::setDirection(float x, float y)
{
	Point direction(x, y);

	setDirection(direction);
}

void AnimatedGameObject::startBlinking()
{
	m_blinking = true;
}

void AnimatedGameObject::stopBlinking()
{
	m_blinking = false;
}

bool AnimatedGameObject::isBlinking()
{
	return m_blinking;
}

void AnimatedGameObject::setAlpha(int alpha)
{
	m_alpha = alpha;
}

float AnimatedGameObject::getAngle()
{
	return m_angle;
}

int AnimatedGameObject::getAlpha()
{
	return m_alpha;
}

void AnimatedGameObject::updateAlpha()
{
	setAlpha(getAlpha() + 20 * m_alphaIncrement);
	if (getAlpha() < 127) {
		setAlpha(127);
		m_alphaIncrement = 1;
	}
	if (getAlpha() > 255) {
		setAlpha(255);
		m_alphaIncrement = -1;
	}
}

void AnimatedGameObject::rotate(float angle)
{
	m_angle += angle;
}

void AnimatedGameObject::setRotation(float angle)
{
	m_angle = angle;
}

void AnimatedGameObject::setTexture(std::string path)
{
	m_texture.loadFromFile(path);
}

Point AnimatedGameObject::getDirection()
{
	return m_direction;
}

float AnimatedGameObject::getRotation()
{
	return m_angle;
}

LTexture * AnimatedGameObject::getTexture()
{
	return &m_texture;
}

void AnimatedGameObject::rotateDirection(float angle)
{
	Point newDirection;

	//pretvaram u radijane
	angle *= M_PI / 180;

	newDirection.x = cos(angle) * m_direction.x - sin(angle) * m_direction.y;
	newDirection.y = sin(angle) * m_direction.x + cos(angle) * m_direction.y;

	m_direction = newDirection;
}
