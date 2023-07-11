#include "WindowHandler.h"
#include "Map.h"

int main()
{
    WindowHandler windowHandler;
    Map tempMap(nullptr,nullptr,nullptr);
    while(windowHandler.getWindowIsOpen())
    {
        windowHandler.showMainMenu();
        sleep(milliseconds(1000));
        windowHandler.render(&tempMap);
        sleep(milliseconds(10000));
    }

}