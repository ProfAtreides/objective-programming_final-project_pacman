#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include <iostream>
#include <time.h>
#include <vector>
#include "Ghost.h"

class Game
{
private:
	sf::Texture gracz1Gora;
	sf::Texture gracz1Prawo;
	sf::Texture gracz1Dol;
	sf::Texture gracz1Lewo;
	sf::Texture gracz2Gora;
	sf::Texture gracz2Prawo;
	sf::Texture gracz2Dol;
	sf::Texture gracz2Lewo;
	sf::Texture wzmocnienieTexture;
	sf::Texture sciana;
	sf::Texture punktTexture;
	sf::Texture duchTexture;
	sf::Texture gracz1WzmocnienieGora;
	sf::Texture gracz1WzmocnieniePrawo;
	sf::Texture gracz1WzmocnienieDol;
	sf::Texture gracz1WzmocnienieLewo;
	sf::Texture gracz2WzmocnienieGora;
	sf::Texture gracz2WzmocnieniePrawo;
	sf::Texture gracz2WzmocnienieDol;
	sf::Texture gracz2WzmocnienieLewo;
	sf::Font font;
	sf::Text text;
	bool Mapa[22][19] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,0,1},
		{1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,0,1},
		{1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1},
		{1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,0,1},
		{1,0,1,1,0,1,0,0,0,0,0,0,0,1,0,1,1,0,1},
		{1,0,1,1,0,1,0,1,1,0,1,1,0,1,0,1,1,0,1},
		{1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1},
		{1,0,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,0,1},
		{1,0,1,1,0,1,0,0,0,0,0,0,0,1,0,1,1,0,1},
		{1,0,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,0,1},
		{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
		{1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1},
		{1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1},
		{1,0,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};
	int PolaMapy[22][19];
	bool punkty[22][19] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1},
		{1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,0,1},
		{1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,0,1},
		{1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1},
		{1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,0,1},
		{1,0,1,1,0,1,0,0,0,0,0,0,0,1,0,1,1,0,1},
		{1,0,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,0,1},
		{1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1},
		{1,0,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,0,1},
		{1,0,1,1,0,1,0,0,0,0,0,0,0,1,0,1,1,0,1},
		{1,0,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,0,1},
		{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
		{1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1},
		{1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1},
		{1,0,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1},
		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};
	bool punktyWGrze[22][19];
	int ilePunktowDoZdobycia = 0;
	int movementSeed = 0;
	int walka = -1;
	std::vector <std::pair<int, int>> Krawedzie[22][19];
	int iloscGraczy = 0;
	Player Gracz1;
	Player Gracz2;
	Ghost duch1;
	Ghost duch2;
	Ghost duch3;
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	bool wzmocnienie1 = true;
	bool wzmocnienie2 = true;
	bool wzmocnienie3 = true;
	bool wzmocnienie4 = true;
	std::pair<int, int> wzmocnienie1Cords = std::make_pair(1, 1);
	std::pair<int, int> wzmocnienie2Cords = std::make_pair(1, 17);
	std::pair<int, int> wzmocnienie3Cords = std::make_pair(20, 1);
	std::pair<int, int> wzmocnienie4Cords = std::make_pair(20, 17);
	void inicjalizacjaZmiennych();
	void inicjzalizacjaOkna();

public:
	int walkaPacmanow();
	void wyborIlosciGraczy();
	void utworzGre();
	void createGraph();
	Game();
	virtual ~Game();
	void update();
	void render();
	void drawMap();
	const bool getWindowIsOpen() const;
	void pollEvents();
	bool koniecGry();
};
