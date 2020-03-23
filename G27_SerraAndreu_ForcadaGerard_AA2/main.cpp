#pragma once
#include <string>
#include "input/input.h"


int main(int argc, char** argv)
{
	/// 1--CIN INPUT---
	/*char c = '0';

	while (c !='a' )
	{
		std::cin >> c;
		system("cls");
		std::cout << "Key:" << c;
	}*/

	/// 2--START GET KEYS
	/*bool up, down, left, right, esc;
	up = down = left = right = esc = false;

	while (!esc)
	{
		system("cls");
		up = GetAsyncKeyState(VK_UP);
		down = GetAsyncKeyState(VK_DOWN);
		left = GetAsyncKeyState(VK_LEFT);
		right = GetAsyncKeyState(VK_RIGHT);
		esc = GetAsyncKeyState(VK_ESCAPE);

		std::cout << "Up:" << up << std::endl;
		std::cout << "Down:" << down << std::endl;
		std::cout << "Left:" << left << std::endl;
		std::cout << "Right:" << right << std::endl;

	}*/

	/// 3--START MAPPING KEYBOARD
	//enum class InputKey{UP, DOWN, LEFT, RIGHT, ESC, COUNT};
	//bool keyboard[(int)keys::COUNT] = {false};

	//while (!keyboard[(int)keys::ESC])
	//{
	//	system("cls");
	//	keyboard[(int)InputKey::UP] = GetAsyncKeyState(VK_UP);
	//	keyboard[(int)InputKey::DOWN] = GetAsyncKeyState(VK_DOWN);
	//	keyboard[(int)InputKey::LEFT] = GetAsyncKeyState(VK_LEFT);
	//	keyboard[(int)InputKey::RIGHT] = GetAsyncKeyState(VK_RIGHT);
	//	keyboard[(int)InputKey::ESC] = GetAsyncKeyState(VK_ESCAPE);

	//	std::cout << "Up:"   << keyboard[(int)InputKey::UP] << std::endl;
	//	std::cout << "Down:" << keyboard[(int)InputKey::DOWN] << std::endl;
	//	std::cout << "Left:" << keyboard[(int)InputKey::LEFT] << std::endl;
	//	std::cout << "Right:" << keyboard[(int)InputKey::RIGHT] << std::endl;
	//}

	/// 4--INPUT STRUCT
	//InputData input;
	//input.Update();

	//while (!input.keys[(int)InputKey::ESC])
	//{
	//	input.Update();
	//	system("cls");
	//	input.keys[(int)InputKey::UP] = GetAsyncKeyState(VK_UP);
	//	input.keys[(int)InputKey::DOWN] = GetAsyncKeyState(VK_DOWN);
	//	input.keys[(int)InputKey::LEFT] = GetAsyncKeyState(VK_LEFT);
	//	input.keys[(int)InputKey::RIGHT] = GetAsyncKeyState(VK_RIGHT);
	//	input.keys[(int)InputKey::ESC] = GetAsyncKeyState(VK_ESCAPE);

	//	std::cout << "Up:"	 <<	input.keys[(int)InputKey::UP] << std::endl;
	//	std::cout << "Down:" << input.keys[(int)InputKey::DOWN] << std::endl;
	//	std::cout << "Left:" << input.keys[(int)InputKey::LEFT] << std::endl;
	//	std::cout << "Right:" << input.keys[(int)InputKey::RIGHT] << std::endl;
	//}

	/// 5--GAME LOOP improve
	InputData input;

	//GAME LOOP
	while (!input.keys[(int)InputKey::ESC])
	{
		//INPUT HANDLER
		input.Update();

		//UPDATE (do something...)
		std::string s = "";
		s += "UP: "		+ std::to_string(input.keys[(int)InputKey::UP]) + "\n";
		s += "DOWN: "	+ std::to_string(input.keys[(int)InputKey::DOWN]) + "\n";
		s += "LEFT: "	+ std::to_string(input.keys[(int)InputKey::LEFT]) + "\n";
		s += "RIGHT: "	+ std::to_string(input.keys[(int)InputKey::RIGHT]);
		std::string f = input.keys[(int)InputKey::FIRE] ? "-->BANG<--" : "   ____";


		//DRAW
		system("cls");
		std::cout << s.c_str() << std::endl;
		std::cout << f.c_str() << std::endl;
	}

	return 0;
}