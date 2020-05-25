#pragma once
#include <chrono>
#include <ctime>
#include <Windows.h>
#include "Types.h"
#include "Player.h"
#include "InputManager.h"

struct Map
{
private:
	char** m_map;
	Player* m_players;
	int width;
	int height;
	const int numPlayers = 2;
	bool gameEnd;
	//bomb vars
	bool bomb1 = false;
	bool bomb2 = false;
	int bombTimeP1 = 500000;
	int bombTimeP2 = 500000;
	Vec2 bomb1pos;
	Vec2 bomb2pos;
	int timeToSpawn = 2;
	int timeToDespawn = 3;
	//Dmgp1
	bool pl1gotdmgP1 = false;
	bool pl2gotdmgP1 = false;
	//Dmgp2
	bool pl1gotdmgP2 = false;
	bool pl2gotdmgP2 = false;
public:
	void InitializeMap();
	void UpdateMap(InputData keyboard, int timer); ///Check colisions i rebre la nova pos
	void PrintMap();
	bool GetGameEnd();
	int GetPlayerNumScore(int player);
};