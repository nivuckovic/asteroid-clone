#pragma once

#include "Screen.h"
#include "Level.h"

class LevelScreen : public Screen
{
public:
	LevelScreen(Level* level);

	void update() override;
	void render() override;

	void onEnter() override;
	void onExit();

	void setGameOver(bool gameOver);
	void checkGameOver();

	~LevelScreen();

private:
	Level * m_currentLevel;

	bool m_isGameOver;
};

