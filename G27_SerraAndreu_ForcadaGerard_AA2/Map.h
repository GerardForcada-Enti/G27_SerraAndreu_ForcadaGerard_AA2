#pragma once
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
public:
	void InitializeMap();
	void UpdateMap(InputData keyboard); ///Check colisions i rebre la nova pos
	void PrintMap();
	bool GetGameEnd();
};