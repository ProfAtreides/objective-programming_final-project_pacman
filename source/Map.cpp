//
// Created by paro on 7/11/23.
//

#include "Map.h"

Map::Map(Enhancement enhancements[],Player players[], Ghost ghosts[]) {
    mTextureWall.loadFromFile("../resources/sciana.png");
    mTexturePoint.loadFromFile("../resources/punkt.png");
}

const bool Map::pointAtPosition(std::pair<int, int> position) {
    return !mPoints[position.first][position.second];
}

const bool Map::wallAtPosition(std::pair<int, int> position) {
    return WALLS[position.first][position.second];
}

void Map::update() {

}

const Texture &Map::getMTextureWall() const {
    return mTextureWall;
}

const Texture &Map::getMTexturePoint() const {
    return mTexturePoint;
}
