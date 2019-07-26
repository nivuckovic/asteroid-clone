#include "InputController.h"

InputController* InputController::m_instance = nullptr;

InputController::InputController()
{
	init();
}

InputController * InputController::getInstance()
{
	if (m_instance == nullptr) {
		m_instance = new InputController();
	}

	return m_instance;;
}

void InputController::update()
{
	BaseController::update();
	KeyboardController::update();

	std::map<Key, bool>::iterator it;
	for (it = m_keyboardKeyActiveMap.begin(); it != m_keyboardKeyActiveMap.end(); ++it) {
		m_keyboardKeyActiveMap[it->first] = isKeyboardKeyPressed(it->first);
	}
}

bool InputController::isKeyActive(Key key)
{
	return checkKeyActive(key);
}


InputController::~InputController()
{
}

void InputController::init()
{
	for (int i = static_cast<int>(Key::VOID) + 1; i < static_cast<int>(Key::MAX); ++i) {
		m_keyboardKeyActiveMap.insert({ static_cast<Key>(i), false });
	}
}

bool InputController::checkKeyActive(Key key)
{
	return m_keyboardKeyActiveMap[key];
}
