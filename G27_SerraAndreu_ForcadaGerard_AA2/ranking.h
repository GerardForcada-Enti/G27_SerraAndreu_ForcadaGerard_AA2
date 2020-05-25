#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>


class Ranking
{
public:
	Ranking();
	~Ranking();
	
	void Print();
	void Read();
	void Update(int, std::string);


private:
	class Scores
	{
	public:
		Scores();
		Scores(int i, std::string s) {
			score = i;
			name = s;
		}
		int score;
		std::string name;

	};

	Scores rank[5];

};




