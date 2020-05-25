#pragma once
#include "Map.h"
#include "InputManager.h"
#include "ranking.h"

class Game
{
public:
	Game();

	void Play();
private:
	enum GameState { SPLASHSCREEN, MENU , PLAY, PAUSE, GAMEOVER, RANKING , COUNT };
	GameState state;
	Map board;
	InputData keyboard;
	Ranking ranking;
};
