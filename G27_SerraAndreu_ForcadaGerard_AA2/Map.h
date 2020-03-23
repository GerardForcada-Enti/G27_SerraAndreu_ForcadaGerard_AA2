#pragma once
#include "Types.h"
#include "Player.h"

struct Map
{
private:
	char** m_map;
	Player* m_players;
	int width;
	int height;
	const int numPlayers = 2;
public:
	void InitializeMap();
	void UpdateMap();
	void PrintMap();
	void PrintScore();
};