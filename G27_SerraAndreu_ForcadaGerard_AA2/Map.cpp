#include "Map.h"

void Map::InitializeMap()
{
	m_players = new Player[this->numPlayers];
	std::ifstream configFile;
	configFile.open("config.txt", std::ios::out);
	if (configFile.is_open())
	{
		char aux;
		std::string aux2;
		configFile >> this->width >> aux >> this->height;
		m_map = new char*[this->width];
		std::getline(configFile, aux2, '\n');
		for (int i = 0; i < this->width; i++)
		{
			m_map[i] = new char[this->height];
			std::getline(configFile, aux2, '\n');
			for (int j = 0; j < this->height; j++)
			{
				m_map[i][j] = aux2[j];
				if(aux2[j]=='1')//Pasar pos Player1
				{
					m_players[0] = Player(i, j);
				}
				if(aux2[j]=='2')//Pasar pos Player2
				{
					m_players[1] = Player(i, j);
				}
			}
			
		}
		
	}
	configFile.close();
}

void Map::UpdateMap(InputData keyboard)
{
	if (keyboard.keys[(int)InputKey::UP1]) 
	{ 
		if (this->m_map[m_players[0].GetPos().x][m_players[0].GetPos().y - 1] != 'X' || this->m_map[m_players[0].GetPos().x][m_players[0].GetPos().y - 1] != '*')
		{
			this->m_map[m_players[0].GetPos().x][m_players[0].GetPos().y] = ' ';
			m_players[0].MovePlayer(MOVEMENT::UP);
			this->m_map[m_players[0].GetPos().x][m_players[0].GetPos().y] = '1';
		}
	}
	else if (keyboard.keys[(int)InputKey::UP2]) 
	{
		if (this->m_map[m_players[1].GetPos().x][m_players[1].GetPos().y - 1] != 'X' || this->m_map[m_players[1].GetPos().x][m_players[1].GetPos().y - 1] != '*')
		{
			this->m_map[m_players[1].GetPos().x][m_players[1].GetPos().y] = ' ';
			m_players[1].MovePlayer(MOVEMENT::UP);
			this->m_map[m_players[1].GetPos().x][m_players[1].GetPos().y] = '2';
		}	
	}
	else if (keyboard.keys[(int)InputKey::DOWN1])
	{
		if (this->m_map[m_players[0].GetPos().x][m_players[0].GetPos().y + 1] != 'X' || this->m_map[m_players[0].GetPos().x][m_players[0].GetPos().y + 1] != '*')
		{
			this->m_map[m_players[0].GetPos().x][m_players[0].GetPos().y] = ' ';
			m_players[0].MovePlayer(MOVEMENT::DOWN);
			this->m_map[m_players[0].GetPos().x][m_players[0].GetPos().y] = '1';
		}	
	}
	else if (keyboard.keys[(int)InputKey::DOWN2])
	{
		if (this->m_map[m_players[1].GetPos().x][m_players[1].GetPos().y + 1] != 'X' || this->m_map[m_players[1].GetPos().x][m_players[1].GetPos().y + 1] != '*')
		{
			this->m_map[m_players[1].GetPos().x][m_players[1].GetPos().y] = ' ';
			m_players[1].MovePlayer(MOVEMENT::DOWN);
			this->m_map[m_players[1].GetPos().x][m_players[1].GetPos().y] = '2';
		}
	}
	else if (keyboard.keys[(int)InputKey::RIGHT1])
	{
		if (this->m_map[m_players[0].GetPos().x + 1][m_players[0].GetPos().y] != 'X' || this->m_map[m_players[0].GetPos().x + 1][m_players[0].GetPos().y] != '*')
		{
			this->m_map[m_players[0].GetPos().x][m_players[0].GetPos().y] = ' ';
			m_players[0].MovePlayer(MOVEMENT::RIGHT);
			this->m_map[m_players[0].GetPos().x][m_players[0].GetPos().y] = '1';
		}
	}
	else if (keyboard.keys[(int)InputKey::RIGHT2])
	{
		if (this->m_map[m_players[1].GetPos().x + 1][m_players[1].GetPos().y] != 'X' || this->m_map[m_players[1].GetPos().x + 1][m_players[1].GetPos().y] != '*')
		{
			this->m_map[m_players[1].GetPos().x][m_players[1].GetPos().y] = ' ';
			m_players[1].MovePlayer(MOVEMENT::RIGHT);
			this->m_map[m_players[1].GetPos().x][m_players[1].GetPos().y] = '2';
		}
	}
	else if (keyboard.keys[(int)InputKey::LEFT1])
	{
		if (this->m_map[m_players[0].GetPos().x - 1][m_players[0].GetPos().y] != 'X' || this->m_map[m_players[0].GetPos().x - 1][m_players[0].GetPos().y] != '*')
		{
			this->m_map[m_players[0].GetPos().x][m_players[0].GetPos().y] = ' ';
			m_players[0].MovePlayer(MOVEMENT::LEFT);
			this->m_map[m_players[0].GetPos().x][m_players[0].GetPos().y] = '1';
		}
	}
	else if (keyboard.keys[(int)InputKey::LEFT2])
	{
		if (this->m_map[m_players[1].GetPos().x - 1][m_players[1].GetPos().y] != 'X' || this->m_map[m_players[1].GetPos().x - 1][m_players[1].GetPos().y] != '*')
		{
			this->m_map[m_players[1].GetPos().x][m_players[1].GetPos().y] = ' ';
			m_players[1].MovePlayer(MOVEMENT::LEFT);
			this->m_map[m_players[1].GetPos().x][m_players[1].GetPos().y] = '2';
		}
	}
	
}

void Map::PrintMap()
{
	for (int i = 0; i < this->width; i++)
	{
		for (int j = 0; j < this->height; j++)
		{

			if(m_map[i][j]=='1')SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 170);//player 1
			else if (m_map[i][j] == '2')SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 221);//player 2
			else if (m_map[i][j] == 'X')SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 136);//muros x
			else if (m_map[i][j] == '*')SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 119);//minas *
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
	std::cout<< std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
}
   