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
		board.PrintMap();
		board.UpdateMap(keyboard);
		Sleep(120);
	}

	std::cout << "Game end" << std::endl;
	system("pause");
}