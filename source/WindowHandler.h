//
// Created by paro on 7/11/23.
//

#ifndef PROGRAM_WINDOW_H
#include "Map.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#define PROGRAM_WINDOW_H

using namespace sf;

class WindowHandler {
public:
    WindowHandler();
    const bool getWindowIsOpen() const;

    void showMainMenu();

    void drawGameMap(Map* map); // TODO will be implemented alongside Map class
    void render(Map* map);
private:
    const int WIDTH = 800;
    const int HEIGHT = 660;
    Font mFont;
    Color mBackGroundColor;
    Text mText;
    RenderWindow* mWindow;
    VideoMode mVideoMode;
};


#endif //PROGRAM_WINDOW_H
