#pragma once
#include <string>
#include "InputManager.h"
#include "Map.h"


int main()
{
	Map board;
	board.InitializeMap();
	board.PrintMap();
	system("pause");
}