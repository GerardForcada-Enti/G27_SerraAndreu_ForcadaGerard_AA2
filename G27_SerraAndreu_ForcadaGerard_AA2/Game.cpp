#include "Game.h"

Game::Game()
{
	state = GameState::INIT;
	board.InitializeMap();
}

void Game::Play()
{
	int timer = 600;
	float secondsPassed = 0.0f;
	while (!keyboard.keys[(int)InputKey::ESC])
	{
		switch (state)
		{
		case GameState::INIT:
		{
			keyboard.UpdateKeys();
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 185);
			std::cout << "-*-*-INIT-*-*-" << std::endl;
			std::cout << "Press the Spacebar to start the game." << std::endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			if (keyboard.keys[(int)InputKey::SPACEBAR])  state = GameState::PLAY;
		}
			break;
		case GameState::PLAY:
		{	
			keyboard.UpdateKeys();
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 185);
			std::cout << "-*-*-GAME-*-*-" << std::endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			std::cout << "Time: " << timer/10 << 's';
			board.PrintMap();
			board.UpdateMap(keyboard);
			if (keyboard.keys[(int)InputKey::PAUSE])  state = GameState::PAUSE; 
			if(board.GetGameEnd()) state = GameState::GAMEOVER;
			Sleep(60);
			secondsPassed += 0.1f;
			if ((int)secondsPassed == 10)secondsPassed = 0.0f; timer--;
		}
			break;
		case GameState::PAUSE:
		{
			keyboard.UpdateKeys();
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 185);
			std::cout << "-*-*-PAUSE-*-*-" << std::endl << "Press the Spacebar to go to the game." << std::endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			if (keyboard.keys[(int)InputKey::SPACEBAR])  state = GameState::PLAY;
		}
			break;
		case GameState::GAMEOVER:
		{
			keyboard.UpdateKeys();
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 185);
			std::cout << "-*-*-GAMEOVER-*-*-" << std::endl << "Press the ESC to exit the game." << std::endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
			break;
		case GameState::COUNT:
		default:
			break;
		}



		

	}

	std::cout << "Game end" << std::endl;
	system("pause");
}
