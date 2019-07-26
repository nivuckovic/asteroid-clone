#pragma once

#include "global.h"
#include "KeyboardController.h"

class InputController : public KeyboardController
{
public:
	static InputController* getInstance();

	void update() override;

	bool isKeyActive(Key key);

	~InputController();

protected:
	void init();

private:
	InputController(); // sprjecava instanciranje -> new InputController() van klase
	static InputController* m_instance;

	std::map<Key, bool> m_keyboardKeyActiveMap;

	bool checkKeyActive(Key key);
};
