#include "InputManager.h"
#include "Constants.h"

void InputData::UpdateKeys() {
	keys[(int)InputKey::ESC] = GetAsyncKeyState(VK_ESCAPE);
	//Player 1 keys
	keys[(int)InputKey::LEFT1] = GetAsyncKeyState(KEY_A);
	keys[(int)InputKey::RIGHT1] = GetAsyncKeyState(KEY_D);
	keys[(int)InputKey::UP1] = GetAsyncKeyState(KEY_W);
	keys[(int)InputKey::DOWN1] = GetAsyncKeyState(KEY_S);
	//Player 2 keys
	keys[(int)InputKey::UP2] = GetAsyncKeyState(VK_UP);
	keys[(int)InputKey::DOWN2] = GetAsyncKeyState(VK_DOWN);
	keys[(int)InputKey::LEFT2] = GetAsyncKeyState(VK_LEFT);
	keys[(int)InputKey::RIGHT2] = GetAsyncKeyState(VK_RIGHT);
	
	keys[(int)InputKey::SPACEBAR] = GetAsyncKeyState(VK_SPACE); //Exit GAMESTATE::PAUSE/INIT and bomb player 2
	keys[(int)InputKey::RCTL] = GetAsyncKeyState(VK_RCONTROL);	//Bomb player 1
	keys[(int)InputKey::PAUSE] = GetAsyncKeyState(KEY_P);

}
