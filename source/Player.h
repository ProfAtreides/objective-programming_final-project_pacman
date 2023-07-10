#pragma once
#include <iostream>
#include <utility>
#include "Direction.h"
#include "Enhancement.h"
#include <SFML/Graphics.hpp>

class Player
{
public:
    Player(std::pair <int,int> startPosition, int playerNumber, std::string path);

	void changeDirections(Direction direction, bool Map[22][19]);

    std::pair<int,int> getPosition();
    std::pair<int,int> getLastPosition();

    void assignEnhancement(Enhancement* enhancement);
    bool getEnhancementStatus();

	void addPoints(int amount);
	std::string pointsToString();
	int getPoints(); // TODO remove if not used later

    Direction getDirection();

    void loadTexture(std::string path);

private:
    std::pair<int,int> mPosition;
    std::pair<int,int> mLastPosition;

    int mNumber; // TODO determine if actually needed
    int mPoints;

    Direction mDirection;
    Direction mNextDirection;

    Enhancement *pEnhancement;

    Texture mTexture;
};
