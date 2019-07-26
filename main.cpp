#include "global.h"
#include <iostream>
#include <SDL.h>
#include "InputController.h"
#include "Game.h"
#include <time.h>

using namespace std;

int main(int argc, char * argv[])
{
	srand(time(NULL));

	Game* m_game = new Game();
	m_game->run();
	delete m_game;

	return 0;
}