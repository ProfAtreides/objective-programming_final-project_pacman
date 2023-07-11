//
// Created by paro on 7/11/23.
//

#include "WindowHandler.h"
#include <thread>

WindowHandler::WindowHandler() {
    this->mVideoMode.height = HEIGHT;
    this->mVideoMode.width = WIDTH;
    this->mWindow =  new RenderWindow(this->mVideoMode,"Dual of Pacs", Style::Titlebar | Style::Close);
    this->mFont.loadFromFile("../resources/arial.ttf");
    this->mText.setFillColor(sf::Color::White);
    this->mText.setFont(mFont);
    this->mText.setCharacterSize(20);
}

void WindowHandler::showMainMenu() {
    mWindow->clear(sf::Color::Black);
    mText.setString("Press S for single-player and M for multi-player");
    mText.setPosition(0, 400);
    mWindow->draw(mText);
    mWindow->display();
}

const bool WindowHandler::getWindowIsOpen() const {
    return mWindow->isOpen();
}

void WindowHandler::drawGameMap(Map *map) {

    Vector2f smallGrid(5, 5);
    RectangleShape point(smallGrid);
    sf::Vector2f largeGrid(30, 30);
    sf::RectangleShape wall(largeGrid);
    wall.setTexture(&(map->getMTextureWall()));
    point.setTexture(&(map->getMTexturePoint()));

    for(int i = 0; i < 22;i++)
    {
        for(int j = 0; j < 19;j++)
        {
            if(map->wallAtPosition(std::make_pair(i,j)))
            {
                wall.setPosition(i * 30, j * 30);
                this->mWindow->draw(wall);
                continue;
            }
            if(map->pointAtPosition(std::make_pair(i,j)))
            {
                point.setPosition((i * 30) + 14, (j * 30) + 14);
                this->mWindow->draw(point);
            }
        }
    }
}

void WindowHandler::render(Map* map) {
    mWindow->clear(Color::Black);
    drawGameMap(map);
    mWindow->display();
}


