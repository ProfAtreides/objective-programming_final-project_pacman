#include <vector>
#include <iostream>
#include "Player.h"
#include "Game.h"
#include <chrono>
#include <thread>

int main()
{
	Game gra;
	gra.createGraph();
	while (gra.getWindowIsOpen())
	{
		gra.wyborIlosciGraczy();
		gra.utworzGre();
		while (gra.koniecGry() == false)
		{
			//Akt
			gra.update();
			//Render
			gra.render();

		}
        sf::sleep(sf::milliseconds(10000));
	}
}