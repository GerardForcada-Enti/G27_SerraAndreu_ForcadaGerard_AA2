#pragma once
#include <iostream>
#include <Windows.h>

enum class InputKey {UP1, DOWN1, LEFT1, RIGHT1, UP2, DOWN2, LEFT2, RIGHT2, SPACEBAR, RCTL, PAUSE, ESC, COUNT};

struct InputData {
public:
	bool keys[(int)InputKey::COUNT] = {};

	void UpdateKeys();
};