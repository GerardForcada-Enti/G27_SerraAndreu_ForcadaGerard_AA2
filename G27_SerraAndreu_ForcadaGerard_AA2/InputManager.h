#pragma once
#include <iostream>
#include <Windows.h>

enum class InputKey {UP, DOWN, LEFT, RIGHT, ESC, FIRE, COUNT};

struct InputData {
	bool keys[(int)InputKey::COUNT] = {};

	void Update() {
		keys[(int)InputKey::ESC] = GetAsyncKeyState(VK_ESCAPE);
		keys[(int)InputKey::UP] = GetAsyncKeyState(VK_UP);
		keys[(int)InputKey::DOWN] = GetAsyncKeyState(VK_DOWN);
		keys[(int)InputKey::LEFT] = GetAsyncKeyState(VK_LEFT);
		keys[(int)InputKey::RIGHT] = GetAsyncKeyState(VK_RIGHT);
		keys[(int)InputKey::FIRE] = GetAsyncKeyState(VK_SPACE);
	}
};