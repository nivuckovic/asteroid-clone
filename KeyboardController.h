#pragma once

#include "global.h"
#include "BaseController.h"
#include <map>
#include "Key.h"

class KeyboardController : public virtual BaseController 
{
public:
	KeyboardController();

	void update() override;

	~KeyboardController();

protected:
	bool isKeyboardKeyPressed(Key key);

private:
	std::map<Key, SDL_Keycode> m_mainKeyMap;
	std::map<Key, SDL_Keycode> m_alternativeKeyMap;

	bool isKeyboardKeyPressed(SDL_Keycode key);
};

