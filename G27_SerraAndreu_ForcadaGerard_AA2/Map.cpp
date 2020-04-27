#include "Map.h"

void Map::InitializeMap()
{
	this->gameEnd = false;
	m_players = new Player[this->numPlayers];
	std::ifstream configFile;
	configFile.open("config.txt", std::ios::out);
	if (configFile.is_open())
	{
		char aux;
		std::string aux2;
		configFile >> this->height >> aux >> this->width;
		m_map = new char*[this->height];
		std::getline(configFile, aux2, '\n');
		for (int i = 0; i < this->height; i++)
		{
			m_map[i] = new char[this->width];
			std::getline(configFile, aux2, '\n');
			for (int j = 0; j < this->width; j++)
			{
				m_map[i][j] = aux2[j];
				if (aux2[j] == '1')//Pasar pos Player1
				{
					m_players[0] = Player(j, i);
				}
				if (aux2[j] == '2')//Pasar pos Player2
				{
					m_players[1] = Player(j, i);
				}
			}

		}

	}
	configFile.close();
}

void Map::UpdateMap(InputData keyboard)
{
	//bomb vars
	bool bomb1 = false;
	bool bombnegatiu = false;
	char prevposp1 = ' ';
	//Set player 1 position
	Vec2 plPos = m_players[0].GetPos();
	Vec2 newPos = m_players[0].GetPos();
	Vec2 bombPos = m_players[0].GetPos();


	//Bombs
	std::chrono::steady_clock::time_point bombTimep1;
	plPos = m_players[0].GetPos();

	if (keyboard.keys[(int)InputKey::RCTL])
	{
		//spawn bomb
		bombPos = plPos;
		this->m_map[plPos.x][plPos.y] = '+';
		bomb1 = true;
		//counter 2 sec 
		bombTimep1 = std::chrono::high_resolution_clock::now();
	}
	if (bomb1)
	{
		if (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - bombTimep1).count() >= 2)
		{
			if (this->m_map[plPos.x - 1][plPos.y] != 'X')
			{
				if (this->m_map[plPos.x - 2][plPos.y] != 'X' && this->m_map[plPos.x - 1][plPos.y] != '*')
				{
					if (this->m_map[plPos.x - 2][plPos.y] == '*')
						this->m_players[0].IncrScore(15);
					this->m_map[plPos.x - 2][plPos.y] = '-';
					if (this->m_map[plPos.x - 2][plPos.y] == '2')
					{
						this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
						this->m_players[0].IncrScore(100);
					}
					if (this->m_map[plPos.x - 2][plPos.y] == '1')
						this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
				}
				if (this->m_map[plPos.x - 1][plPos.y] == '*')
					this->m_players[0].IncrScore(15);
				if (this->m_map[plPos.x - 1][plPos.y] == '2')
				{
					this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
					this->m_players[0].IncrScore(100);
				}
				if (this->m_map[plPos.x - 1][plPos.y] == '1')
					this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
				this->m_map[plPos.x - 1][plPos.y] = '-';

			}
			if (this->m_map[plPos.x + 1][plPos.y] != 'X')
			{
				if (this->m_map[plPos.x + 2][plPos.y] != 'X' && this->m_map[plPos.x + 1][plPos.y] != '*')
				{
					if (this->m_map[plPos.x + 2][plPos.y] == '*')
						this->m_players[0].IncrScore(15);
					if (this->m_map[plPos.x + 2][plPos.y] == '2')
					{
						this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
						this->m_players[0].IncrScore(100);
					}
					if (this->m_map[plPos.x + 2][plPos.y] == '1')
						this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
					this->m_map[plPos.x + 2][plPos.y] = '-';
				}
				if (this->m_map[plPos.x + 1][plPos.y] == '*')
					this->m_players[0].IncrScore(15);
				if (this->m_map[plPos.x + 1][plPos.y] == '2')
				{
					this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
					this->m_players[0].IncrScore(100);
				}
				if (this->m_map[plPos.x + 1][plPos.y] == '1')
					this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
				this->m_map[plPos.x + 1][plPos.y] = '-';

			}
			if (this->m_map[plPos.x][plPos.y - 1] != 'X')
			{
				if (this->m_map[plPos.x][plPos.y - 2] != 'X' && this->m_map[plPos.x][plPos.y - 1] != '*')
				{
					if (this->m_map[plPos.x][plPos.y - 2] == '*')
						this->m_players[0].IncrScore(15);
					if (this->m_map[plPos.x][plPos.y - 2] == '2')
					{
						this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
						this->m_players[0].IncrScore(100);
					}
					if (this->m_map[plPos.x][plPos.y - 2] == '1')
						this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
					this->m_map[plPos.x][plPos.y - 2] = '-';
				}
				if (this->m_map[plPos.x][plPos.y - 1] == '*')
					this->m_players[0].IncrScore(15);
				if (this->m_map[plPos.x][plPos.y - 1] == '2')
				{
					this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
					this->m_players[0].IncrScore(100);
				}
				if (this->m_map[plPos.x][plPos.y - 1] == '1')
					this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
				this->m_map[plPos.x][plPos.y - 1] = '-';
			}
			if (this->m_map[plPos.x][plPos.y + 1] != 'X')
			{
				if (this->m_map[plPos.x][plPos.y + 2] != 'X' && this->m_map[plPos.x][plPos.y + 1] != '*')
				{
					if (this->m_map[plPos.x][plPos.y + 2] == '*')
						this->m_players[0].IncrScore(15);
					if (this->m_map[plPos.x][plPos.y + 2] == '2')
					{
						this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
						this->m_players[0].IncrScore(100);
					}
					if (this->m_map[plPos.x][plPos.y + 2] == '1')
						this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
					this->m_map[plPos.x][plPos.y + 2] = '-';
				}
				if (this->m_map[plPos.x][plPos.y + 1] == '*')
					this->m_players[0].IncrScore(15);
				if (this->m_map[plPos.x][plPos.y + 1] == '2')
				{
					this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
					this->m_players[0].IncrScore(100);
				}
				if (this->m_map[plPos.x][plPos.y + 1] == '1')
					this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
				this->m_map[plPos.x][plPos.y + 1] = '-';
			}
			bombnegatiu = true;
		}
		if (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - bombTimep1).count() >= 3)
		{
			if (this->m_map[plPos.x - 1][plPos.y] == '-')
			{
				if (this->m_map[plPos.x - 2][plPos.y] == '-')
				{
					this->m_map[plPos.x - 2][plPos.y] = ' ';
				}
				this->m_map[plPos.x - 1][plPos.y] = ' ';
			}
			if (this->m_map[plPos.x + 1][plPos.y] == '-')
			{
				if (this->m_map[plPos.x + 2][plPos.y] == '-')
				{
					this->m_map[plPos.x + 2][plPos.y] = ' ';
				}
				this->m_map[plPos.x + 1][plPos.y] = ' ';
			}
			if (this->m_map[plPos.x][plPos.y - 1] == '-')
			{
				if (this->m_map[plPos.x][plPos.y - 2] == '-')
				{
					this->m_map[plPos.x][plPos.y - 2] = ' ';
				}
				this->m_map[plPos.x][plPos.y - 1] = ' ';
			}
			if (this->m_map[plPos.x][plPos.y + 1] == '-')
			{
				if (this->m_map[plPos.x][plPos.y + 2] == '-')
				{
					this->m_map[plPos.x][plPos.y + 2] = ' ';
				}
				this->m_map[plPos.x][plPos.y + 1] = ' ';
			}
			bomb1 = false;
			bombnegatiu = false;
		}
	}


	if (keyboard.keys[(int)InputKey::UP1])
	{
		newPos = Vec2(plPos.x, plPos.y - 1);
		
		//char cell = m_map[newPos.x][newPos.y];
	if ((m_map[newPos.x][newPos.y] != 'X') && (m_map[newPos.x][newPos.y] != '*') &&	(newPos.y >= 0))
		{
		if (bomb1) {
			m_map[bombPos.x][bombPos.y] = '+';
			//prevposp1 = '+';
		}
		
		else
			m_map[plPos.x][plPos.y] = ' ';   //prevposp1;
			//prevposp1 = m_map[newPos.x][newPos.y];
			m_players[0].MovePlayer(MOVEMENT::UP);
			m_map[newPos.x][newPos.y] = '1';
		}
	}
	else if (keyboard.keys[(int)InputKey::DOWN1])
	{
		newPos = Vec2(plPos.x, plPos.y + 1);
		if ((m_map[newPos.x][newPos.y] != 'X') && (m_map[newPos.x][newPos.y] != '*') && (newPos.y <= height))
		{
			if (bomb1)
				m_map[plPos.x][plPos.y] = '+';
			else
				m_map[plPos.x][plPos.y] = ' ';
			m_players[0].MovePlayer(MOVEMENT::DOWN);
			m_map[newPos.x][newPos.y] = '1';

		}
	}
	else if (keyboard.keys[(int)InputKey::RIGHT1])
	{
		newPos = Vec2(plPos.x + 1, plPos.y);
		if ((m_map[newPos.x][newPos.y] != 'X') && (m_map[newPos.x][newPos.y] != '*') && (newPos.x <= width)) {
			if (bomb1)
				m_map[plPos.x][plPos.y] = '+';
			else
				m_map[plPos.x][plPos.y] = ' ';
			m_players[0].MovePlayer(MOVEMENT::RIGHT);
			m_map[newPos.x][newPos.y] = '1';
		}

	}
	else if (keyboard.keys[(int)InputKey::LEFT1])
	{
		newPos = Vec2(plPos.x - 1, plPos.y);
		if ((m_map[newPos.x][newPos.y] != 'X') && (m_map[newPos.x][newPos.y] != '*') && (newPos.x > 0))
		{
			if (bomb1)
				m_map[plPos.x][plPos.y] = '+';
			else
				m_map[plPos.x][plPos.y] = ' ';
			m_players[0].MovePlayer(MOVEMENT::LEFT);
			m_map[newPos.x][newPos.y] = '1';
		}
	}

	//Set player 2 position			-----
	Vec2 p2Pos = m_players[1].GetPos();
	Vec2 newPos2 = m_players[1].GetPos();

	//p2Pos = m_players[1].GetPos();
	//newPos2 = m_players[1].GetPos();
	if (keyboard.keys[(int)InputKey::UP2])
	{
		newPos2 = Vec2(p2Pos.x, p2Pos.y - 1);
		if ((m_map[newPos2.x][newPos2.y] != 'X') && (m_map[newPos2.x][newPos2.y] != '*') && (newPos2.x > 0))
		{
			m_map[p2Pos.x][p2Pos.y] = ' ';
			m_players[1].MovePlayer(MOVEMENT::UP);
			m_map[newPos2.x][newPos2.y] = '1';
		}
	}
	else if (keyboard.keys[(int)InputKey::DOWN2])
	{
		newPos2 = Vec2(p2Pos.x, p2Pos.y + 1);
		if ((m_map[newPos2.x][newPos2.y] != 'X') && (m_map[newPos2.x][newPos2.y] != '*') && (newPos2.x <= width - 1)) {
			m_map[p2Pos.x][p2Pos.y] = ' ';
			m_players[0].MovePlayer(MOVEMENT::DOWN);
			m_map[newPos2.x][newPos2.y] = '1';
		}
	}
	else if (keyboard.keys[(int)InputKey::RIGHT2])
	{
		newPos2 = Vec2(p2Pos.x + 1, p2Pos.y);
		if ((m_map[newPos2.x][newPos2.y] != 'X') && (m_map[newPos2.x][newPos2.y] != '*') && (newPos2.y <= height))
		{
			m_map[p2Pos.x][p2Pos.y] = ' ';
			m_players[0].MovePlayer(MOVEMENT::RIGHT);
			m_map[newPos2.x][newPos2.y] = '1';
		}
	}
	else if (keyboard.keys[(int)InputKey::LEFT2])
	{
		newPos2 = Vec2(p2Pos.x - 1, p2Pos.y);
		if ((m_map[newPos2.x][newPos2.y] != 'X') && (m_map[newPos2.x][newPos2.y] != '*') && (newPos2.y >= 0))
		{
			m_map[p2Pos.x][p2Pos.y] = ' ';
			m_players[1].MovePlayer(MOVEMENT::LEFT);
			m_map[newPos2.x][newPos2.y] = '1';
		}
	}
	
	//Game ended
	if (this->m_players[0].GetLives() == 0) gameEnd = true;
	if (this->m_players[1].GetLives() == 0) gameEnd = true;
}

void Map::PrintMap()
{
	//Print lives
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224);
	std::cout << std::endl << "---Lives---";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << std::endl << "Player 1: " << m_players[0].GetLives() << '\t';
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	std::cout << "Player 2: " << m_players[1].GetLives() << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			if (m_map[i][j] == '1')SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 170);//player 1
			else if (m_map[i][j] == '2')SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 221);//player 2
			else if (m_map[i][j] == 'X')SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 136);//muros x
			else if (m_map[i][j] == '*')SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 119);//muros destruct *
			else if (m_map[i][j] == '+')SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 204);//bomba *
			else if (m_map[i][j] == '-')SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);//bomba destruct *
			std::cout << m_map[i][j] << ' ';
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		}
		std::cout << std::endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224);
	std::cout << std::endl << "*------SCORE------* ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << std::endl << "Player 1: ";
	m_players[0].PrintScore();
	std::cout << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	std::cout << "Player 2: ";
	m_players[1].PrintScore();
	std::cout << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

bool Map::GetGameEnd()
{
	return this->gameEnd;
}
