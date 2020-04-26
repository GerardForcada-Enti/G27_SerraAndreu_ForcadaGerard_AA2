#include "Player.h"

void Player::MovePlayer(MOVEMENT mov)
{
	switch (mov)
	{
	case UP:
		pos.y--;
		break;
	case DOWN:
		pos.y++;
		break;
	case RIGHT:
		pos.x++;
		break;
	case LEFT:
		pos.x--;
	case COUNT:
	default:
		break;
	}
}

void Player::PrintScore()
{
	std::cout << score;
}

Vec2 Player::GetPos()
{
	return pos;
}

void Player::SetLives(int val)
{
	this->lives = val;
}

int Player::GetLives()
{
	return lives;
}

void Player::IncrScore(int val)
{
	this->score += val;
}
