#include "InputManager.h"
#include "Constants.h"

void InputData::UpdateKeys() {
	keys[(int)InputKey::ESC] = GetAsyncKeyState(VK_ESCAPE);
	//Player 1 keys
	keys[(int)InputKey::UP1] = GetAsyncKeyState(VK_UP);
	keys[(int)InputKey::DOWN1] = GetAsyncKeyState(VK_DOWN);
	keys[(int)InputKey::LEFT1] = GetAsyncKeyState(VK_LEFT);
	keys[(int)InputKey::RIGHT1] = GetAsyncKeyState(VK_RIGHT);	
	//Player 2 keys
	keys[(int)InputKey::UP2] = GetAsyncKeyState(KEY_W);
	keys[(int)InputKey::DOWN2] = GetAsyncKeyState(KEY_S);
	keys[(int)InputKey::LEFT2] = GetAsyncKeyState(KEY_A);
	keys[(int)InputKey::RIGHT2] = GetAsyncKeyState(KEY_D);
	
}
