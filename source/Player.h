#pragma once
#include <iostream>
#include <utility>
#include "Direction.h"
#include "Enhancement.h"

class Player
{
private:
	std::pair<int,int> mPosition;
    std::pair<int,int> mLastPosition;
;
	int mNumber; // TODO determine if actually needed
	int mPoints;

    Direction mDirection;
	Direction mNextDirection;

    Enhancement *pEnhancement;

public:
    Player(std::pair <int,int> startPosition, int playerNumber);

	void changeDirections(Direction direction, bool Map[22][19]);

    std::pair<int,int> getPosition();
    std::pair<int,int> getLastPosition();

    void assignEnhancement(Enhancement* enhancement); // TODO implement in next commit
    bool getEnhancementStatus(); // TODO implement in next commit

	void addPoints(int amount);
	std::string pointsToString();
	int getPoints(); // TODO remove if not used later

    Direction getDirection();
};
