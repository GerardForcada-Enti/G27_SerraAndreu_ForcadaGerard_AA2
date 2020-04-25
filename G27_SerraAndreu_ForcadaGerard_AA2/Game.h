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
-bombes
	-vides
	-destruccio
	-punts
	-mapeig tecla control i space per bombes
	-colors bomba ( vermell-vermell 204 / groc-groc 238)

-Moviment player2
*/