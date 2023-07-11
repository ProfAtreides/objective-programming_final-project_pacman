//
// Created by paro on 7/11/23.
//

#include "WindowHandler.h"
#include <thread>

WindowHandler::WindowHandler() {
    this->mVideoMode.height = HEIGHT;
    this->mVideoMode.width = WIDTH;
    this->mWindow =  new RenderWindow(this->mVideoMode,"Dual of Pacs", Style::Titlebar | Style::Close);
    this->mFont.loadFromFile("arial.ttf");
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

}

void WindowHandler::render(Map* map) {
    mWindow->clear(Color::Black);
    drawGameMap(map);
    mWindow->display();
}


