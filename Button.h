#pragma once
#include "ButtonInterface.h"
#include <functional>
#include "InputController.h"

class Button : public ButtonInterface
{
public:
	Button(Key key, const std::function<void()>& agent);

	void render() override;
	void update() override;

	void drawDebugBox() override;

	void click() override;
	void setOnClick(const std::function<void()>& agent);

	Key getKey();

	~Button();

private:
	InputController * m_inputController;
	std::function<void()> m_executeOnClick;

	Key m_key;
};

