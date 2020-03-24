#pragma once
#include <iostream>
#include <fstream>
#include <string>


struct Vec2
{
public:
	Vec2() { x = y = 0; }
	Vec2(int a, int b) { x = a; y = b; }
	int x;
	int y;
};

enum MOVEMENT{ UP, DOWN, RIGHT, LEFT, COUNT };