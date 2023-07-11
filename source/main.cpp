#include "WindowHandler.h"

int main()
{
    WindowHandler windowHandler;
    while(windowHandler.getWindowIsOpen())
    {
        windowHandler.showMainMenu();
        sleep(milliseconds(1000));
    }

}