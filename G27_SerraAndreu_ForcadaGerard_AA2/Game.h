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
