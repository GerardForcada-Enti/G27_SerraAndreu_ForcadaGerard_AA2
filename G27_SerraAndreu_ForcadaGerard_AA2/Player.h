#pragma once
#include "Types.h"

struct Player
{
private:
	Vec2 pos;
	int score;
	int lives;
public:
	Player() { pos.x = pos.y = score = 0; lives = 3; }
	Player(int a, int b) { pos.x = a; pos.y = b; score = 0; lives = 3; }
	void MovePlayer(MOVEMENT mov);
	/*void AddPoints();
	void Explode();*/
	void PrintScore();
	Vec2 GetPos();
	void SetLives(int val);
	int GetLives();
};