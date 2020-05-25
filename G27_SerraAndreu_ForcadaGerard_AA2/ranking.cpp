#pragma once
#include "ranking.h"


Ranking::Ranking()
{
}

void Ranking::Print() {// 1. nom score
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 172);
	std::cout << "Ranking" << std::endl;
	for (int i = 0; i < 5; i++) 
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 51);
		std::cout << i << ". \t" << rank[i].name << '\t' << rank[i].score << std::endl;
		
	}
	
}

void Ranking::Read() {
	std::ifstream rankingFile;
	rankingFile.open("ranking.txt", std::ios::out);
	if (rankingFile.is_open())
	{
				// score nom
		for (int i = 0; i < 5 || rankingFile.eof(); ++i)
		{
			rankingFile >> rank[i].score;
			std::getline(rankingFile, rank[i].name, '\n');
		}

	}
	rankingFile.close();
}

void Ranking::Update(int score, std::string name) 
{
	std::ofstream rankingFile;
	rankingFile.open("ranking.txt", std::ios::in || std::ios::trunc);
	if (rankingFile.is_open())
	{
		for (int i = 0; i < 5; i++) 
		{
			rankingFile << rank[i].score << ' ' << rank[i].name;
		}
	

	}

}
