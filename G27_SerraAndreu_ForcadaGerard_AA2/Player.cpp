#include "Player.h"

void Player::MovePlayer(MOVEMENT mov)
{
	switch (mov)
	{
	case UP:
		pos.x--;
		break;
	case DOWN:
		pos.x++;
		break;
	case RIGHT:
		pos.y++;
		break;
	case LEFT:
		pos.y--;
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
