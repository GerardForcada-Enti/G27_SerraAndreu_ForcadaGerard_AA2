#pragma once
#include <string>
#include "InputManager.h"
#include "Map.h"


int main()
{
	Map board;
	InputData keyboard;
	board.InitializeMap();

	while (!keyboard.keys[(int)InputKey::ESC])
	{
		keyboard.UpdateKeys();
		system("cls");
		//gameloop
		board.UpdateMap(keyboard);
		board.PrintMap();
		Sleep(60);
	}


	system("pause");
}