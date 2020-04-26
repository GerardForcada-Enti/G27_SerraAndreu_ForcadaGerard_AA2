#pragma once
#include "Map.h"
#include "InputManager.h"

class Game
{
public:
	Game();

	void Play();
private:
	enum GameState { INIT, PLAY, PAUSE, GAMEOVER, COUNT };
	GameState state;
	Map board;
	InputData keyboard;
	
};


/*
-bombes (player 2) mes bugs

-Moviment player2
*/