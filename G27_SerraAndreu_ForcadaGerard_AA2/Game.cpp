#include "Game.h"

Game::Game()
{
	state = GameState::PLAY;
	board.InitializeMap();
}

void Game::Play()
{
	std::chrono::steady_clock::time_point timerChrono;
	std::chrono::seconds timer(60);
	bool enterPlay = true;
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
			if (enterPlay)
			{
				timerChrono = std::chrono::high_resolution_clock::now();
				enterPlay = false;
			}
			keyboard.UpdateKeys();
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 185);
			std::cout << "-*-*-GAME-*-*-" << std::endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			std::cout << "Time: " << (int)(timer - std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - timerChrono)) << 's';
			board.PrintMap();
			board.UpdateMap(keyboard);
			if (keyboard.keys[(int)InputKey::PAUSE])  state = GameState::PAUSE; enterPlay = true;
			if (board.GetGameEnd()) state = GameState::GAMEOVER; enterPlay = true;
			Sleep(60);
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
