#include "Button.h"



Button::Button(Key key, const std::function<void()>& agent)
{
	m_inputController = InputController::getInstance();
	m_key = key;
	setOnClick(agent);
	setGameObjectType(GameObjectType::_GUI);
}


void Button::render()
{
}

void Button::update()
{
	if (m_inputController->isKeyActive(getKey())) {
		click();
	}
}

void Button::drawDebugBox()
{
}

void Button::click()
{
	m_executeOnClick();
}

inline void Button::setOnClick(const std::function<void()>& agent)
{
	m_executeOnClick = agent;
}

Key Button::getKey()
{
	return m_key;
}

Button::~Button()
{
}
