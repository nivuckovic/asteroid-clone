#pragma once

#include "Screen.h"
#include "InputController.h"

class MenuScreen : public Screen
{
public:
	MenuScreen();

	void update() override;
	void render() override;

	void onEnter() override;
	void onExit();
	void onNewGame();

	~MenuScreen();

private:
	InputController * m_inputController;
};

