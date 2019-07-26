#include "KeyboardController.h"

KeyboardController::KeyboardController()
{
	m_mainKeyMap.insert({ Key::Move_Forward, SDLK_UP });
	m_mainKeyMap.insert({ Key::Move_Backward, SDLK_DOWN });
	m_mainKeyMap.insert({ Key::Rotate_Left, SDLK_LEFT });
	m_mainKeyMap.insert({ Key::Rotate_Right, SDLK_RIGHT });
	m_mainKeyMap.insert({ Key::Menu, SDLK_ESCAPE });
	m_mainKeyMap.insert({ Key::Fire, SDLK_SPACE });

	m_alternativeKeyMap.insert({ Key::Move_Forward, SDLK_w });
	m_alternativeKeyMap.insert({ Key::Move_Backward, SDLK_s });
	m_alternativeKeyMap.insert({ Key::Rotate_Left, SDLK_a });
	m_alternativeKeyMap.insert({ Key::Rotate_Right, SDLK_d });
	m_alternativeKeyMap.insert({ Key::Menu, SDLK_ESCAPE });
	m_alternativeKeyMap.insert({ Key::Fire, SDLK_SPACE });
}

void KeyboardController::update()
{
	//m_lastpressedkey ...
}


KeyboardController::~KeyboardController()
{
}

bool KeyboardController::isKeyboardKeyPressed(Key key)
{
	auto it = m_mainKeyMap.find(key);
	auto it2 = m_alternativeKeyMap.find(key);
	if (it == m_mainKeyMap.end() && it2 == m_alternativeKeyMap.end()) {
		return false;
	}

	return isKeyboardKeyPressed(it->second) || isKeyboardKeyPressed(it2->second);
}

bool KeyboardController::isKeyboardKeyPressed(SDL_Keycode key)
{
	const Uint8 *state = SDL_GetKeyboardState(NULL);

	return state[SDL_GetScancodeFromKey(key)];
}
