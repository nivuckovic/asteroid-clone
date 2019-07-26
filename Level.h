#pragma once

#include "Screen.h"

class Level
{
public:
	Level();

	void setScreen(Screen * screen);
	void onEnter();

	~Level();

private:
	Screen * m_screen;
};

