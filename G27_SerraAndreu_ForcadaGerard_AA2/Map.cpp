#include "Map.h"

void Map::InitializeMap()
{
	m_players = new Player[numPlayers];
	std::ifstream configFile;
	configFile.open("config.txt", std::ios::out);
	if (configFile.is_open())
	{
		char aux;
		std::string aux2;
		configFile >> width >> aux >> height;
		m_map = new char*[width];
		std::getline(configFile, aux2, '\n');
		for (int i = 0; i < width; i++)
		{
			m_map[i] = new char[height];
			std::getline(configFile, aux2, '\n');
			for (int j = 0; j < height; j++)
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

void Map::PrintMap()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			std::cout<< m_map[i][j];
		}
		std::cout << std::endl;
	}

}
