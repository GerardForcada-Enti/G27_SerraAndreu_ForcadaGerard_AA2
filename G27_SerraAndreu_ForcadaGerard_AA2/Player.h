#pragma once
#include "Types.h"

struct Player
{
private:
	Vec2 pos;
	int score;

public:
	Player() { pos.x = pos.y = score = 0; }
	Player(int a, int b) { pos.x = a; pos.y = b; score = 0; }
	void PrintPlayer();
	void MovePlayer();
	void CheckCollision();
	/*
	void AddPoints();
	void Explode();
	void Die();
	void GetScore();
	*/
};