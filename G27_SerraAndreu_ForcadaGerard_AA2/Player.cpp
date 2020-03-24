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

int Player::GetScore()
{
	return score;
}
