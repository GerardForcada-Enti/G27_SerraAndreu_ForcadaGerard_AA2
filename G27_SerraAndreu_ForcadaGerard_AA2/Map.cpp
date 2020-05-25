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
					m_players[0] = Player(i,j);
				}
				if (aux2[j] == '2')//Pasar pos Player2
				{
					m_players[1] = Player(i, j);
				}
			}

		}

	}
	configFile.close();
}

void Map::UpdateMap(InputData keyboard, int timer)
{
	
	//Set player 1 position
	Vec2 plPos = m_players[0].GetPos();
	Vec2 newPos = m_players[0].GetPos();

	if (keyboard.keys[(int)InputKey::UP1])
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
	else if (keyboard.keys[(int)InputKey::DOWN1])
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
	else if (keyboard.keys[(int)InputKey::RIGHT1])
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
	else if (keyboard.keys[(int)InputKey::LEFT1])
	{
		newPos = Vec2(plPos.x, plPos.y - 1);
		//char cell = m_map[newPos.x][newPos.y];
		if ((m_map[newPos.x][newPos.y] != 'X') && (m_map[newPos.x][newPos.y] != '*') && (newPos.y >= 0))
		{
			if (bomb1)
				m_map[plPos.x][plPos.y] = '+';
			else
				m_map[plPos.x][plPos.y] = ' ';
			m_players[0].MovePlayer(MOVEMENT::UP);
			m_map[newPos.x][newPos.y] = '1';
		}
	}

	//Set player 2 position			-----
	plPos = m_players[1].GetPos();
	newPos = m_players[1].GetPos();
	if (keyboard.keys[(int)InputKey::UP2])
	{
		newPos = Vec2(plPos.x - 1, plPos.y);
		if ((m_map[newPos.x][newPos.y] != 'X') && (m_map[newPos.x][newPos.y] != '*') && (newPos.x >= 0))
		{
			m_map[plPos.x][plPos.y] = ' ';
			m_players[1].MovePlayer(MOVEMENT::LEFT);
			m_map[newPos.x][newPos.y] = '2';
		}
	}
	else if (keyboard.keys[(int)InputKey::DOWN2])
	{
		newPos = Vec2(plPos.x + 1, plPos.y);
		if ((m_map[newPos.x][newPos.y] != 'X') && (m_map[newPos.x][newPos.y] != '*') && (newPos.x <= width))
		{
			m_map[plPos.x][plPos.y] = ' ';
			m_players[1].MovePlayer(MOVEMENT::RIGHT);
			m_map[newPos.x][newPos.y] = '2';
		}
	}
	else if (keyboard.keys[(int)InputKey::RIGHT2])
	{
		newPos = Vec2(plPos.x, plPos.y + 1);
		if ((m_map[newPos.x][newPos.y] != 'X') && (m_map[newPos.x][newPos.y] != '*') && (newPos.y <= height)) {
			m_map[plPos.x][plPos.y] = ' ';
			m_players[1].MovePlayer(MOVEMENT::DOWN);
			m_map[newPos.x][newPos.y] = '2';
		}
	}
	else if (keyboard.keys[(int)InputKey::LEFT2])
	{
		newPos = Vec2(plPos.x, plPos.y - 1);
		if ((m_map[newPos.x][newPos.y] != 'X') && (m_map[newPos.x][newPos.y] != '*') && (newPos.y > 0))
		{
			m_map[plPos.x][plPos.y] = ' ';
			m_players[1].MovePlayer(MOVEMENT::UP);
			m_map[newPos.x][newPos.y] = '2';
		}
	}
	
#pragma region
	//Bombs p1
		

		if (keyboard.keys[(int)InputKey::SPACEBAR] && !bomb1)
		{
			bomb1pos = m_players[0].GetPos();
			//spawn bomb
			this->m_map[bomb1pos.x][bomb1pos.y] = '+';
			bombTimeP1 = timer;
			bomb1 = true;
		}

		if (bomb1)
		{
			if (bombTimeP1 - timer == timeToSpawn)
			{
				if (this->m_map[bomb1pos.x - 1][bomb1pos.y] != 'X')
				{
					if (this->m_map[bomb1pos.x - 2][bomb1pos.y] != 'X' && this->m_map[bomb1pos.x - 1][bomb1pos.y] != '*')
					{
						if (this->m_map[bomb1pos.x - 2][bomb1pos.y] == '*')
							this->m_players[0].IncrScore(15);
						this->m_map[bomb1pos.x - 2][bomb1pos.y] = '-';
						if (bomb1pos.x == m_players[1].GetPos().x && bomb1pos.y == m_players[1].GetPos().y && !pl2gotdmgP1)
						{
							pl2gotdmgP1 = true;
							//this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
							//this->m_players[0].IncrScore(100);
						}
						if (bomb1pos.x == m_players[0].GetPos().x && bomb1pos.y == m_players[0].GetPos().y && !pl1gotdmgP1)
							pl1gotdmgP1 = true;//this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
					}
					if (this->m_map[bomb1pos.x - 1][bomb1pos.y] == '*')
						this->m_players[0].IncrScore(15);
					if (bomb1pos.x == m_players[1].GetPos().x && bomb1pos.y == m_players[1].GetPos().y && !pl2gotdmgP1)
					{
						pl2gotdmgP1 = true;
						//this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
						//this->m_players[0].IncrScore(100);
					}
					if (bomb1pos.x == m_players[0].GetPos().x && bomb1pos.y == m_players[0].GetPos().y && !pl1gotdmgP1)
						pl1gotdmgP1 = true;//this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
					this->m_map[bomb1pos.x - 1][bomb1pos.y] = '-';

				}
				if (this->m_map[bomb1pos.x + 1][bomb1pos.y] != 'X')
				{
					if (this->m_map[bomb1pos.x + 2][bomb1pos.y] != 'X' && this->m_map[bomb1pos.x + 1][bomb1pos.y] != '*')
					{
						if (this->m_map[bomb1pos.x + 2][bomb1pos.y] == '*')
							this->m_players[0].IncrScore(15);
						if (bomb1pos.x == m_players[1].GetPos().x && bomb1pos.y == m_players[1].GetPos().y && !pl2gotdmgP1)
						{
							pl2gotdmgP1 = true;
							//this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
							//this->m_players[0].IncrScore(100);
						}
						if (bomb1pos.x == m_players[0].GetPos().x && bomb1pos.y == m_players[0].GetPos().y && !pl1gotdmgP1)
							pl1gotdmgP1 = true;//this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
						this->m_map[bomb1pos.x + 2][bomb1pos.y] = '-';
					}
					if (this->m_map[bomb1pos.x + 1][bomb1pos.y] == '*')
						this->m_players[0].IncrScore(15);
					if (bomb1pos.x == m_players[1].GetPos().x && bomb1pos.y == m_players[1].GetPos().y && !pl2gotdmgP1)
					{
						pl2gotdmgP1 = true;
						//this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
						//this->m_players[0].IncrScore(100);
					}
					if (bomb1pos.x == m_players[0].GetPos().x && bomb1pos.y == m_players[0].GetPos().y && !pl1gotdmgP1)
						pl1gotdmgP1 = true;//this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
					this->m_map[bomb1pos.x + 1][bomb1pos.y] = '-';

				}
				if (this->m_map[bomb1pos.x][bomb1pos.y - 1] != 'X')
				{
					if (this->m_map[bomb1pos.x][bomb1pos.y - 2] != 'X' && this->m_map[bomb1pos.x][bomb1pos.y - 1] != '*')
					{
						if (this->m_map[bomb1pos.x][bomb1pos.y - 2] == '*')
							this->m_players[0].IncrScore(15);
						if (bomb1pos.x == m_players[1].GetPos().x && bomb1pos.y == m_players[1].GetPos().y && !pl2gotdmgP1)
						{
							pl2gotdmgP1 = true;
							//this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
							//this->m_players[0].IncrScore(100);
						}
						if (bomb1pos.x == m_players[0].GetPos().x && bomb1pos.y == m_players[0].GetPos().y && !pl1gotdmgP1)
							pl1gotdmgP1 = true;//this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
						this->m_map[bomb1pos.x][bomb1pos.y - 2] = '-';
					}
					if (this->m_map[bomb1pos.x][bomb1pos.y - 1] == '*')
						this->m_players[0].IncrScore(15);
					if (bomb1pos.x == m_players[1].GetPos().x && bomb1pos.y == m_players[1].GetPos().y && !pl2gotdmgP1)
					{
						pl2gotdmgP1 = true;
						//this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
						//this->m_players[0].IncrScore(100);
					}
					if (bomb1pos.x == m_players[0].GetPos().x && bomb1pos.y == m_players[0].GetPos().y && !pl1gotdmgP1)
						pl1gotdmgP1 = true;//this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
					this->m_map[bomb1pos.x][bomb1pos.y - 1] = '-';
				}
				if (this->m_map[bomb1pos.x][bomb1pos.y + 1] != 'X')
				{
					if (this->m_map[bomb1pos.x][bomb1pos.y + 2] != 'X' && this->m_map[bomb1pos.x][bomb1pos.y + 1] != '*')
					{
						if (this->m_map[bomb1pos.x][bomb1pos.y + 2] == '*')
							this->m_players[0].IncrScore(15);
						if (bomb1pos.x == m_players[1].GetPos().x && bomb1pos.y == m_players[1].GetPos().y && !pl2gotdmgP1)
						{
							pl2gotdmgP1 = true;
							//this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
							//this->m_players[0].IncrScore(100);
						}
						if (bomb1pos.x == m_players[0].GetPos().x && bomb1pos.y == m_players[0].GetPos().y && !pl1gotdmgP1)
							pl1gotdmgP1 = true;//this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
						this->m_map[bomb1pos.x][bomb1pos.y + 2] = '-';
					}
					if (this->m_map[bomb1pos.x][bomb1pos.y + 1] == '*')
						this->m_players[0].IncrScore(15);
					if (bomb1pos.x == m_players[1].GetPos().x && bomb1pos.y == m_players[1].GetPos().y && !pl2gotdmgP1)
					{
						pl2gotdmgP1 = true;
						//this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
						//this->m_players[0].IncrScore(100);
					}
					if (bomb1pos.x == m_players[0].GetPos().x && bomb1pos.y == m_players[0].GetPos().y && !pl1gotdmgP1)
						pl1gotdmgP1 = true;// this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
					this->m_map[bomb1pos.x][bomb1pos.y + 1] = '-';
				}
			}
			if (bombTimeP1 - timer == timeToDespawn)
			{
				if (this->m_map[bomb1pos.x - 1][bomb1pos.y] == '-')
				{
					if (this->m_map[bomb1pos.x - 2][bomb1pos.y] == '-')
					{
						this->m_map[bomb1pos.x - 2][bomb1pos.y] = ' ';
					}
					this->m_map[bomb1pos.x - 1][bomb1pos.y] = ' ';
				}
				if (this->m_map[bomb1pos.x + 1][bomb1pos.y] == '-')
				{
					if (this->m_map[bomb1pos.x + 2][bomb1pos.y] == '-')
					{
						this->m_map[bomb1pos.x + 2][bomb1pos.y] = ' ';
					}
					this->m_map[bomb1pos.x + 1][bomb1pos.y] = ' ';
				}
				if (this->m_map[bomb1pos.x][bomb1pos.y - 1] == '-')
				{
					if (this->m_map[bomb1pos.x][bomb1pos.y - 2] == '-')
					{
						this->m_map[bomb1pos.x][bomb1pos.y - 2] = ' ';
					}
					this->m_map[bomb1pos.x][bomb1pos.y - 1] = ' ';
				}
				if (this->m_map[bomb1pos.x][bomb1pos.y + 1] == '-')
				{
					if (this->m_map[bomb1pos.x][bomb1pos.y + 2] == '-')
					{
						this->m_map[bomb1pos.x][bomb1pos.y + 2] = ' ';
					}
					this->m_map[bomb1pos.x][bomb1pos.y + 1] = ' ';
				}
				if (this->m_map[bomb1pos.x][bomb1pos.y] == '+')
					this->m_map[bomb1pos.x][bomb1pos.y + 1] = ' ';
				//dmg dealer
				if (pl2gotdmgP1)
				{
					this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
					this->m_players[1].IncrScore(100);
				}
				if (pl1gotdmgP1)
				{
					this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
				}
				pl1gotdmgP1 = false;
				pl2gotdmgP1 = false;
				bomb1 = false;
			}
		}
#pragma endregion

#pragma region 
	//Bombs p2
		
		if (keyboard.keys[(int)InputKey::RCTL] && !bomb2)
		{
			bomb2pos = m_players[1].GetPos();
			this->m_map[bomb2pos.x][bomb2pos.y] = '.';
			bombTimeP2 = timer;
			bomb2 = true;
		}
		if (bomb2)
		{
			if (bombTimeP2 - timer == timeToSpawn)
			{
				if (this->m_map[bomb2pos.x - 1][bomb2pos.y] != 'X')
				{
					if (this->m_map[bomb2pos.x - 2][bomb2pos.y] != 'X' && this->m_map[bomb2pos.x - 1][bomb2pos.y] != '*')
					{
						if (this->m_map[bomb2pos.x - 2][bomb2pos.y] == '*')
							this->m_players[1].IncrScore(15);
						this->m_map[bomb2pos.x - 2][bomb2pos.y] = '/';
						if (bomb2pos.x == m_players[0].GetPos().x && bomb2pos.y == m_players[0].GetPos().y && !pl1gotdmgP2)
						{
							//this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
							//this->m_players[1].IncrScore(100);
							pl1gotdmgP2 = true;
						}
						if (bomb2pos.x == m_players[1].GetPos().x && bomb2pos.y == m_players[1].GetPos().y && !pl2gotdmgP2)
							pl2gotdmgP2 = true;
							//this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
					}
					if (this->m_map[bomb2pos.x - 1][bomb2pos.y] == '*')
						this->m_players[1].IncrScore(15);
					if (bomb2pos.x == m_players[0].GetPos().x && bomb2pos.y == m_players[0].GetPos().y && !pl1gotdmgP2)
					{
						//this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
						//this->m_players[1].IncrScore(100);
						pl1gotdmgP2 = true;
					}
					if (bomb2pos.x == m_players[1].GetPos().x && bomb2pos.y == m_players[1].GetPos().y && !pl2gotdmgP2)
						pl2gotdmgP2 = true; //this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
					this->m_map[bomb2pos.x - 1][bomb2pos.y] = '/';

				}
				if (this->m_map[bomb2pos.x + 1][bomb2pos.y] != 'X')
				{
					if (this->m_map[bomb2pos.x + 2][bomb2pos.y] != 'X' && this->m_map[bomb2pos.x + 1][bomb2pos.y] != '*')
					{
						if (this->m_map[bomb2pos.x + 2][bomb2pos.y] == '*')
							this->m_players[1].IncrScore(15);
						if (bomb2pos.x == m_players[0].GetPos().x && bomb2pos.y == m_players[0].GetPos().y && !pl1gotdmgP2)
						{
							//this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
							//this->m_players[1].IncrScore(100);
							pl1gotdmgP2 = true;
						}
						if (bomb2pos.x == m_players[1].GetPos().x && bomb2pos.y == m_players[1].GetPos().y && !pl2gotdmgP2)
							pl2gotdmgP2 = true; //this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
						this->m_map[bomb2pos.x + 2][bomb2pos.y] = '/';
					}
					if (this->m_map[bomb2pos.x + 1][bomb2pos.y] == '*')
						this->m_players[1].IncrScore(15);
					if (bomb2pos.x == m_players[0].GetPos().x && bomb2pos.y == m_players[0].GetPos().y && !pl1gotdmgP2)
					{
						//this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
						//this->m_players[1].IncrScore(100);
						pl1gotdmgP2 = true;
					}
					if (bomb2pos.x == m_players[1].GetPos().x && bomb2pos.y == m_players[1].GetPos().y && !pl2gotdmgP2)
						pl2gotdmgP2 = true; //this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
					this->m_map[bomb2pos.x + 1][bomb2pos.y] = '/';

				}
				if (this->m_map[bomb2pos.x][bomb2pos.y - 1] != 'X')
				{
					if (this->m_map[bomb2pos.x][bomb2pos.y - 2] != 'X' && this->m_map[bomb2pos.x][bomb2pos.y - 1] != '*')
					{
						if (this->m_map[bomb2pos.x][bomb2pos.y - 2] == '*')
							this->m_players[1].IncrScore(15);
						if (bomb2pos.x == m_players[0].GetPos().x && bomb2pos.y == m_players[0].GetPos().y && !pl1gotdmgP2)
						{
							//this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
							//this->m_players[1].IncrScore(100);
							pl1gotdmgP2 = true;
						}
						if (bomb2pos.x == m_players[1].GetPos().x && bomb2pos.y == m_players[1].GetPos().y && !pl2gotdmgP2)
							pl2gotdmgP2 = true; //this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
						this->m_map[bomb2pos.x][bomb2pos.y - 2] = '/';
					}
					if (this->m_map[bomb2pos.x][bomb2pos.y - 1] == '*')
						this->m_players[1].IncrScore(15);
					if (bomb2pos.x == m_players[0].GetPos().x && bomb2pos.y == m_players[0].GetPos().y && !pl1gotdmgP2)
					{
						//this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
						//this->m_players[1].IncrScore(100);
						pl1gotdmgP2 = true;
					}
					if (bomb2pos.x == m_players[1].GetPos().x && bomb2pos.y == m_players[1].GetPos().y && !pl2gotdmgP2)
						pl2gotdmgP2 = true; //this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
					this->m_map[bomb2pos.x][bomb2pos.y - 1] = '/';
				}
				if (this->m_map[bomb2pos.x][bomb2pos.y + 1] != 'X')
				{
					if (this->m_map[bomb2pos.x][bomb2pos.y + 2] != 'X' && this->m_map[bomb2pos.x][bomb2pos.y + 1] != '*')
					{
						if (this->m_map[bomb2pos.x][bomb2pos.y + 2] == '*')
							this->m_players[1].IncrScore(15);
						if (bomb2pos.x == m_players[0].GetPos().x && bomb2pos.y == m_players[0].GetPos().y && !pl1gotdmgP2)
						{
							//this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
							//this->m_players[1].IncrScore(100);
							pl1gotdmgP2 = true;
						}
						if (bomb2pos.x == m_players[1].GetPos().x && bomb2pos.y == m_players[1].GetPos().y && !pl2gotdmgP2)
							pl2gotdmgP2 = true; //this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
						this->m_map[bomb2pos.x][bomb2pos.y + 2] = '/';
					}
					if (this->m_map[bomb2pos.x][bomb2pos.y + 1] == '*')
						this->m_players[1].IncrScore(15);
					if (bomb2pos.x == m_players[0].GetPos().x && bomb2pos.y == m_players[0].GetPos().y && !pl1gotdmgP2)
					{
						//this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
						//this->m_players[1].IncrScore(100);
						pl1gotdmgP2 = true;
					}
					if (bomb2pos.x == m_players[1].GetPos().x && bomb2pos.y == m_players[1].GetPos().y && !pl2gotdmgP2)
						pl2gotdmgP2 = true; //this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
					this->m_map[bomb2pos.x][bomb2pos.y + 1] = '/';
				}
					
			}
			if (bombTimeP2 - timer >= timeToDespawn)
			{
				if (this->m_map[bomb2pos.x - 1][bomb2pos.y] == '/')
				{
					if (this->m_map[bomb2pos.x - 2][bomb2pos.y] == '/')
					{
						this->m_map[bomb2pos.x - 2][bomb2pos.y] = ' ';
					}
					this->m_map[bomb2pos.x - 1][bomb2pos.y] = ' ';
				}
				if (this->m_map[bomb2pos.x + 1][bomb2pos.y] == '/')
				{
					if (this->m_map[bomb2pos.x + 2][bomb2pos.y] == '/')
					{
						this->m_map[bomb2pos.x + 2][bomb2pos.y] = ' ';
					}
					this->m_map[bomb2pos.x + 1][bomb2pos.y] = ' ';
				}
				if (this->m_map[bomb2pos.x][bomb2pos.y - 1] == '/')
				{
					if (this->m_map[bomb2pos.x][bomb2pos.y - 2] == '/')
					{
						this->m_map[bomb2pos.x][bomb2pos.y - 2] = ' ';
					}
					this->m_map[bomb2pos.x][bomb2pos.y - 1] = ' ';
				}
				if (this->m_map[bomb2pos.x][bomb2pos.y + 1] == '/')
				{
					if (this->m_map[bomb2pos.x][bomb2pos.y + 2] == '/')
					{
						this->m_map[bomb2pos.x][bomb2pos.y + 2] = ' ';
					}
					this->m_map[bomb2pos.x][bomb2pos.y + 1] = ' ';
				}
				if (this->m_map[bomb2pos.x][bomb2pos.y] == '+')
					this->m_map[bomb2pos.x][bomb2pos.y + 1] = ' ';
				
				//dmg dealer
				if (pl2gotdmgP2)
				{
					this->m_players[1].SetLives(this->m_players[1].GetLives() - 1);
				}
				if (pl1gotdmgP2)
				{
					this->m_players[0].SetLives(this->m_players[0].GetLives() - 1);
					this->m_players[1].IncrScore(100);
				}
				pl1gotdmgP2 = false;
				pl2gotdmgP2 = false;
				bomb2 = false;
			}
		}	
#pragma endregion

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
			else if (m_map[i][j] == '+')SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 204);//bomba * p1
			else if (m_map[i][j] == '-')SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);//bomba destruct * p1
			else if (m_map[i][j] == '.')SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 204);//bomba * p2
			else if (m_map[i][j] == '/')SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 238);//bomba destruct * p2
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

int Map::GetPlayerNumScore(int player)
{
	if(player == 0 || player == 1)
		return this->m_players[player].GetScore();
}
