#pragma once
#include <vector>

enum class Key {
	VOID,
	Menu,
	Move_Forward,
	Move_Backward,
	Rotate_Left,
	Rotate_Right,
	Fire, 
	MAX
};

static const std::vector<Key> KEYBOARD_KEYS = {
	Key::Menu,
	Key::Move_Forward
};