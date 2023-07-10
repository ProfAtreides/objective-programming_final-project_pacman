#include "Player.h"

Player::Player(std::pair <int,int> startPosition, int playerNumber)
{
    this->mPosition = startPosition;
    this->mLastPosition = startPosition;
    this->mDirection = STANDING;
    this->mNextDirection = STANDING;
    this->mNumber = playerNumber;
    this->mPoints = 0;
    this->pEnhancement = nullptr;
}

void Player::changeDirections(Direction tempDirection, bool Map[22][19])
{
	switch (tempDirection)
	{
	case UP:
		if (Map[mPosition.first][mPosition.second - 1] == false)
		{
            mDirection = UP;
		}
		else
		{
			mNextDirection = UP;
		}
		break;
	case RIGHT:
        if (Map[mPosition.first + 1][mPosition.second] == false)
        {
            mDirection = RIGHT;
        }
        else
        {
            mNextDirection = RIGHT;
        }
            break;
	case DOWN:
        if (Map[mPosition.first][mPosition.second + 1] == false)
        {
            mDirection = DOWN;
        }
        else
        {
            mNextDirection = DOWN;
        }
            break;
	case LEFT:
        if (Map[mPosition.first - 1][mPosition.second ] == false)
        {
            mDirection = LEFT;
        }
        else
        {
            mNextDirection = LEFT;
        }
            break;
	}
}

void Player::addPoints(int amount)
{
	mPoints += amount;
}

std::string Player::pointsToString()
{
	return std::to_string(mPoints);
}

int Player::getPoints()
{
	return mPoints;
}

void Player::assignEnhancement(Enhancement *enhancement) {

}

bool Player::getEnhancementStatus()
{

}

Direction Player::getDirection()
{
	return mDirection;
}

std::pair<int, int> Player::getPosition() {
    return mPosition;
}

std::pair<int, int> Player::getLastPosition() {
    return mLastPosition;
}
