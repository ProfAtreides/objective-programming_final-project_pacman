#include "Gra.h"
void Gra::inicjalizacjaZmiennych()
{
	this->window = nullptr;
}

void Gra::inicjzalizacjaOkna()
{
	this->videoMode.height = 800;
	this->videoMode.width = 660;
	this->window = new sf::RenderWindow(this->videoMode, "Dual of Pacs", sf::Style::Titlebar | sf::Style::Close);
	font.loadFromFile("arial.ttf");
	text.setFillColor(sf::Color::White);
	text.setFont(font);
	text.setCharacterSize(20);
	gracz1Gora.loadFromFile("Gracz1_gora.png");
	gracz1Prawo.loadFromFile("Gracz1_prawo.png");
	gracz1Dol.loadFromFile("Gracz1_dol.png");
	gracz1Lewo.loadFromFile("Gracz1_lewo.png");
	gracz2Gora.loadFromFile("Gracz2_gora.png");
	gracz2Prawo.loadFromFile("Gracz2_prawo.png");
	gracz2Dol.loadFromFile("Gracz2_dol.png");
	gracz2Lewo.loadFromFile("Gracz2_lewo.png");
	wzmocnienieTexture.loadFromFile("wzmocnienie.png");
	sciana.loadFromFile("sciana.png");
	punktTexture.loadFromFile("punkt.png");
	gracz1WzmocnienieGora.loadFromFile("Gracz1_wzmocniony_gora.png");
	gracz1WzmocnieniePrawo.loadFromFile("Gracz1_wzmocniony_prawo.png");
	gracz1WzmocnienieDol.loadFromFile("Gracz1_wzmocniony_dol.png");
	gracz1WzmocnienieLewo.loadFromFile("Gracz1_wzmocniony_lewo.png");
	gracz2WzmocnienieGora.loadFromFile("Gracz2_wzmocniony_gora.png");
	gracz2WzmocnieniePrawo.loadFromFile("Gracz2_wzmocniony_prawo.png");
	gracz2WzmocnienieDol.loadFromFile("Gracz2_wzmocniony_dol.png");
	gracz2WzmocnienieLewo.loadFromFile("Gracz2_wzmocniony_lewo.png");
	duchTexture.loadFromFile("Ghost.png");
}

void Gra::createGraph()
{
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (i - 1 >= 0)
			{
				if (Mapa[i][j] == Mapa[i - 1][j] && Mapa[i][j] == 0)
				{
					Krawedzie[i][j].push_back(std::make_pair(i - 1, j));
				}
			}
			if (j + 1 < 19)
			{
				if (Mapa[i][j] == Mapa[i][j + 1] && Mapa[i][j] == 0)
				{
					Krawedzie[i][j].push_back(std::make_pair(i, j + 1));
				}
			}
			if (i + 1 < 22)
			{
				if (Mapa[i][j] == Mapa[i + 1][j] && Mapa[i][j] == 0)
				{
					Krawedzie[i][j].push_back(std::make_pair(i + 1, j));
				}
			}
			if (j - 1 >= 0)
			{
				if (Mapa[i][j] == Mapa[i][j - 1] && Mapa[i][j] == 0)
				{
					Krawedzie[i][j].push_back(std::make_pair(i, j - 1));
				}
			}
		}
	}
}

Gra::Gra()
{
	this->inicjalizacjaZmiennych();
	this->inicjzalizacjaOkna();
}
Gra::~Gra()
{
	delete this->window;
}

void Gra::update()
{
	this->pollEvents();
	sf::sleep(sf::milliseconds(250));
	if (iloscGraczy == 1)
	{
		if (duch1.czyZjedzony())
		{
			duch1.zmniejszRundyDoRegenracji();
		}
		if (duch2.czyZjedzony())
		{
			duch2.zmniejszRundyDoRegenracji();
		}
		if (duch3.czyZjedzony())
		{
			duch3.zmniejszRundyDoRegenracji();
		}
		if (Gracz1.czyWzmocniony())
		{
			Gracz1.skrocWzmocnienieORunde();
		}
		Gracz1.Ruch(Mapa);
		if (punktyWGrze[Gracz1.getX()][Gracz1.getY()] == 0)
		{
			Gracz1.dodajPunkty();
			punktyWGrze[Gracz1.getX()][Gracz1.getY()] = 1;
			ilePunktowDoZdobycia--;
		}
		if (wzmocnienie1Cords.first == Gracz1.getX() && wzmocnienie1Cords.second == Gracz1.getY() && wzmocnienie1)
		{
			Gracz1.wzmocnijGracza();
			wzmocnienie1 = false;
		}
		if (wzmocnienie2Cords.first == Gracz1.getX() && wzmocnienie2Cords.second == Gracz1.getY() && wzmocnienie2)
		{
			Gracz1.wzmocnijGracza();
			wzmocnienie2 = false;
		}
		if (wzmocnienie3Cords.first == Gracz1.getX() && wzmocnienie3Cords.second == Gracz1.getY() && wzmocnienie3)
		{
			Gracz1.wzmocnijGracza();
			wzmocnienie3 = false;
		}
		if (wzmocnienie4Cords.first == Gracz1.getX() && wzmocnienie4Cords.second == Gracz1.getY() && wzmocnienie4)
		{
			Gracz1.wzmocnijGracza();
			wzmocnienie4 = false;
		}
		if ((duch1.getX() - Gracz1.getX()) * (duch1.getX() - Gracz1.getX()) < 9 && (duch1.getY() - Gracz1.getY()) * (duch1.getY() - Gracz1.getY()) < 9)
		{
			duch1.poscig(Krawedzie, Gracz1);
		}
		else
		{
			duch1.ruch(Krawedzie, Gracz1);
		}
		if ((duch2.getX() - Gracz1.getX()) * (duch2.getX() - Gracz1.getX()) < 9 && (duch2.getY() - Gracz1.getY()) * (duch2.getY() - Gracz1.getY()) < 9)
		{
			duch2.poscig(Krawedzie, Gracz1);
		}
		else
		{
			duch2.ruch(Krawedzie, Gracz1);
		}
		if ((duch3.getX() - Gracz1.getX()) * (duch3.getX() - Gracz1.getX()) < 9 && (duch3.getY() - Gracz1.getY()) * (duch3.getY() - Gracz1.getY()) < 9)
		{
			duch3.poscig(Krawedzie, Gracz1);
		}
		else
		{
			duch3.ruch(Krawedzie, Gracz1);
		}
		if (duch1.zjedzGracza(Gracz1) == true)
		{
			if (Gracz1.czyWzmocniony() == true && duch1.czyZjedzonyPrzezGracza() == false)
			{
				duch1.zjedzonyPrzezGracza();
				Gracz1.zjedzDucha();
			}
			if (Gracz1.czyWzmocniony() == false)
			{
				Gracz1.Porazka();
			}
		}
		if (duch2.zjedzGracza(Gracz1) == true)
		{
			if (Gracz1.czyWzmocniony() == true && duch2.czyZjedzonyPrzezGracza() == false)
			{
				duch2.zjedzonyPrzezGracza();
				Gracz1.zjedzDucha();
			}
			if (Gracz1.czyWzmocniony() == false)
			{
				Gracz1.Porazka();
			}
		}
		if (duch3.zjedzGracza(Gracz1) == true)
		{
			if (Gracz1.czyWzmocniony() == true && duch3.czyZjedzonyPrzezGracza() == false)
			{
				duch3.zjedzonyPrzezGracza();
				Gracz1.zjedzDucha();
			}
			if (Gracz1.czyWzmocniony() == false)
			{
				Gracz1.Porazka();
			}
		}
	}
	if (iloscGraczy == 2)
	{
		if (Gracz1.czyWzmocniony())
		{
			Gracz1.skrocWzmocnienieORunde();
		}
		if (Gracz2.czyWzmocniony())
		{
			Gracz2.skrocWzmocnienieORunde();
		}
		if (duch1.czyZjedzony())
		{
			duch1.zmniejszRundyDoRegenracji();
		}
		if (duch2.czyZjedzony())
		{
			duch2.zmniejszRundyDoRegenracji();
		}
		if (duch3.czyZjedzony())
		{
			duch3.zmniejszRundyDoRegenracji();
		}
		Gracz1.Ruch(Mapa);
		Gracz2.Ruch(Mapa);
		if (wzmocnienie1Cords.first == Gracz1.getX() && wzmocnienie1Cords.second == Gracz1.getY() && wzmocnienie1)
		{
			Gracz1.wzmocnijGracza();
			wzmocnienie1 = false;
		}
		if (wzmocnienie2Cords.first == Gracz1.getX() && wzmocnienie2Cords.second == Gracz1.getY() && wzmocnienie2)
		{
			Gracz1.wzmocnijGracza();
			wzmocnienie2 = false;
		}
		if (wzmocnienie3Cords.first == Gracz1.getX() && wzmocnienie3Cords.second == Gracz1.getY() && wzmocnienie3)
		{
			Gracz1.wzmocnijGracza();
			wzmocnienie3 = false;
		}
		if (wzmocnienie4Cords.first == Gracz1.getX() && wzmocnienie4Cords.second == Gracz1.getY() && wzmocnienie4)
		{
			Gracz1.wzmocnijGracza();
			wzmocnienie4 = false;
		}
		if (punktyWGrze[Gracz1.getX()][Gracz1.getY()] == 0)
		{
			Gracz1.dodajPunkty();
			punktyWGrze[Gracz1.getX()][Gracz1.getY()] = 1;
			ilePunktowDoZdobycia--;
		}

		if (punktyWGrze[Gracz2.getX()][Gracz2.getY()] == 0)
		{
			Gracz2.dodajPunkty();
			punktyWGrze[Gracz2.getX()][Gracz2.getY()] = 1;
			ilePunktowDoZdobycia--;
		}
		if (wzmocnienie1Cords.first == Gracz2.getX() && wzmocnienie1Cords.second == Gracz2.getY() && wzmocnienie1)
		{
			Gracz2.wzmocnijGracza();
			wzmocnienie1 = false;
		}
		if (wzmocnienie2Cords.first == Gracz2.getX() && wzmocnienie2Cords.second == Gracz2.getY() && wzmocnienie2)
		{
			Gracz2.wzmocnijGracza();
			wzmocnienie2 = false;
		}
		if (wzmocnienie3Cords.first == Gracz2.getX() && wzmocnienie3Cords.second == Gracz2.getY() && wzmocnienie3)
		{
			Gracz2.wzmocnijGracza();
			wzmocnienie3 = false;
		}
		if (wzmocnienie4Cords.first == Gracz2.getX() && wzmocnienie4Cords.second == Gracz2.getY() && wzmocnienie4)
		{
			Gracz2.wzmocnijGracza();
			wzmocnienie4 = false;
		}
		srand(time(NULL));
		movementSeed = rand() % 2;
		if (movementSeed == 0)
		{
			duch1.ruch(Krawedzie, Gracz1);
			duch2.ruch(Krawedzie, Gracz1);
			duch3.ruch(Krawedzie, Gracz1);
		}
		else
		{
			duch1.ruch(Krawedzie, Gracz2);
			duch2.ruch(Krawedzie, Gracz2);
			duch3.ruch(Krawedzie, Gracz2);
		}
		if (duch1.zjedzGracza(Gracz1) == true)
		{
			if (Gracz1.czyWzmocniony() == true && duch1.czyZjedzonyPrzezGracza() == false)
			{
				duch1.zjedzonyPrzezGracza();
				Gracz1.zjedzDucha();
			}
			if (Gracz1.czyWzmocniony() == false)
			{
				Gracz1.Porazka();
			}
		}
		if (duch2.zjedzGracza(Gracz1) == true)
		{
			if (Gracz1.czyWzmocniony() == true && duch2.czyZjedzonyPrzezGracza() == false)
			{
				duch2.zjedzonyPrzezGracza();
				Gracz1.zjedzDucha();
			}
			if (Gracz1.czyWzmocniony() == false)
			{
				Gracz1.Porazka();
			}
		}
		if (duch3.zjedzGracza(Gracz1) == true)
		{
			if (Gracz1.czyWzmocniony() == true && duch3.czyZjedzonyPrzezGracza() == false)
			{
				duch3.zjedzonyPrzezGracza();
				Gracz1.zjedzDucha();
			}
			if (Gracz1.czyWzmocniony() == false)
			{
				Gracz1.Porazka();
			}
		}
		if (duch1.zjedzGracza(Gracz2) == true || duch2.zjedzGracza(Gracz2) == true || duch3.zjedzGracza(Gracz2) == true)
		{
			if (Gracz2.czyWzmocniony() == true)
			{
				if (duch1.zjedzGracza(Gracz2) == true && duch1.czyZjedzonyPrzezGracza() == false)
				{
					duch1.zjedzonyPrzezGracza();
					Gracz2.zjedzDucha();
				}
				if (duch2.zjedzGracza(Gracz2) == true && duch2.czyZjedzonyPrzezGracza() == false)
				{
					duch2.zjedzonyPrzezGracza();
					Gracz2.zjedzDucha();
				}
				if (duch3.zjedzGracza(Gracz2) == true && duch3.czyZjedzonyPrzezGracza() == false)
				{
					duch3.zjedzonyPrzezGracza();
					Gracz2.zjedzDucha();
				}
			}
			if (Gracz2.czyWzmocniony() == false)
			{
				Gracz2.Porazka();
			}
		}
		if (Gracz1.getX() == Gracz2.getX() && Gracz1.getY() == Gracz2.getY())
		{
			walka = walkaPacmanow();//0-remis 1-pierwszy wygrywa 2-drugi wygrywa
		}
	}
}

void Gra::render()
{
	this->window->clear(sf::Color::Black);
	drawMap();
	this->window->display();
}

const bool Gra::getWindowIsOpen() const
{
	return this->window->isOpen();
}
void Gra::drawMap()
{
	sf::Vector2f littleGrid(5, 5);
	sf::Vector2f mediumGrid(5, 5);
	sf::RectangleShape wzmocnienie(mediumGrid);
	sf::RectangleShape punkt(littleGrid);
	sf::Vector2f grid_size(30, 30);
	sf::RectangleShape blok(grid_size);
	sf::RectangleShape gracz(grid_size);
	sf::RectangleShape duch(grid_size);
	duch.setTexture(&duchTexture);
	blok.setTexture(&sciana);
	punkt.setTexture(&punktTexture);
	wzmocnienie.setTexture(&wzmocnienieTexture);
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (wzmocnienie1 == true && wzmocnienie1Cords.first == i && wzmocnienie1Cords.second == j)
			{
				wzmocnienie.setPosition(i * 30 + 14, j * 30 + 14);
				this->window->draw(wzmocnienie);
			}
			if (wzmocnienie2 == true && wzmocnienie2Cords.first == i && wzmocnienie2Cords.second == j)
			{
				wzmocnienie.setPosition(i * 30 + 14, j * 30 + 14);
				this->window->draw(wzmocnienie);
			}
			if (wzmocnienie3 == true && wzmocnienie3Cords.first == i && wzmocnienie3Cords.second == j)
			{
				wzmocnienie.setPosition(i * 30 + 14, j * 30 + 14);
				this->window->draw(wzmocnienie);
			}
			if (wzmocnienie4 == true && wzmocnienie4Cords.first == i && wzmocnienie4Cords.second == j)
			{
				wzmocnienie.setPosition(i * 30 + 14, j * 30 + 14);
				this->window->draw(wzmocnienie);
			}
			if (punktyWGrze[i][j] == 0)
			{
				punkt.setPosition((i * 30) + 14, (j * 30) + 14);
				this->window->draw(punkt);
			}
			if (Gracz1.getX() == i && Gracz1.getY() == j)
			{
				if (Gracz1.czyWzmocniony())
				{
					if (Gracz1.zwrocKierunek() == 0)
					{
						gracz.setTexture(&gracz1WzmocnienieGora);
					}
					if (Gracz1.zwrocKierunek() == 1 || Gracz1.zwrocKierunek() == -1)
					{
						gracz.setTexture(&gracz1WzmocnieniePrawo);
					}
					if (Gracz1.zwrocKierunek() == 2)
					{
						gracz.setTexture(&gracz1WzmocnienieDol);
					}
					if (Gracz1.zwrocKierunek() == 3)
					{
						gracz.setTexture(&gracz1WzmocnienieLewo);
					}
					gracz.setPosition(i * 30, j * 30);
					this->window->draw(gracz);
					continue;
				}
				else
				{
					if (Gracz1.zwrocKierunek() == 0)
					{
						gracz.setTexture(&gracz1Gora);
					}
					if (Gracz1.zwrocKierunek() == 1 || Gracz1.zwrocKierunek() == -1)
					{
						gracz.setTexture(&gracz1Prawo);
					}
					if (Gracz1.zwrocKierunek() == 2)
					{
						gracz.setTexture(&gracz1Dol);
					}
					if (Gracz1.zwrocKierunek() == 3)
					{
						gracz.setTexture(&gracz1Lewo);
					}
					gracz.setPosition(i * 30, j * 30);
					this->window->draw(gracz);
					continue;
				}
			}
			if (iloscGraczy == 2)
			{
				if (Gracz2.getX() == i && Gracz2.getY() == j)
				{
					if (Gracz2.czyWzmocniony())
					{
						if (Gracz2.zwrocKierunek() == 0)
						{
							gracz.setTexture(&gracz2WzmocnienieGora);
						}
						if (Gracz2.zwrocKierunek() == 1 || Gracz2.zwrocKierunek() == -1)
						{
							gracz.setTexture(&gracz2WzmocnieniePrawo);
						}
						if (Gracz2.zwrocKierunek() == 2)
						{
							gracz.setTexture(&gracz2WzmocnienieDol);
						}
						if (Gracz2.zwrocKierunek() == 3)
						{
							gracz.setTexture(&gracz2WzmocnienieLewo);
						}
						gracz.setPosition(i * 30, j * 30);
						this->window->draw(gracz);
						continue;
					}
					else
					{
						if (Gracz2.zwrocKierunek() == 0)
						{
							gracz.setTexture(&gracz2Gora);
						}
						if (Gracz2.zwrocKierunek() == 1 || Gracz2.zwrocKierunek() == -1)
						{
							gracz.setTexture(&gracz2Prawo);
						}
						if (Gracz2.zwrocKierunek() == 2)
						{
							gracz.setTexture(&gracz2Dol);
						}
						if (Gracz2.zwrocKierunek() == 3)
						{
							gracz.setTexture(&gracz2Lewo);
						}
						gracz.setPosition(i * 30, j * 30);
						this->window->draw(gracz);
						continue;
					}
				}
			}
			if (duch1.getX() == i && duch1.getY() == j)
			{
				duch.setPosition(i * 30, j * 30);
				this->window->draw(duch);
				continue;
			}
			if (duch2.getX() == i && duch2.getY() == j)
			{
				duch.setPosition(i * 30, j * 30);
				this->window->draw(duch);
				continue;
			}
			if (duch3.getX() == i && duch3.getY() == j)
			{
				duch.setPosition(i * 30, j * 30);
				this->window->draw(duch);
				continue;
			}
			if (Mapa[i][j] == 1)
			{
				blok.setPosition(i * 30, j * 30);
				this->window->draw(blok);
			}
		}
	}
	text.setPosition(0, 19 * 30);
	text.setString("Gracz1:" + Gracz1.pokazPunktyString());
	this->window->draw(text);
	if (iloscGraczy == 2)
	{
		text.setString("Gracz2:" + Gracz2.pokazPunktyString());
		text.setPosition(528, 30 * 19);
		this->window->draw(text);
	}
}
void Gra::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::D)
			{
				Gracz1.zmienKierunek('d', Mapa);
				//	std::cout << "d" << " ";
			}
			if (ev.key.code == sf::Keyboard::A)
			{
				Gracz1.zmienKierunek('a', Mapa);
				//	std::cout << "a" << " ";
			}
			if (ev.key.code == sf::Keyboard::W)
			{
				Gracz1.zmienKierunek('w', Mapa);
				//	std::cout << "w" << " ";
			}
			if (ev.key.code == sf::Keyboard::S)
			{
				Gracz1.zmienKierunek('s', Mapa);
				//	std::cout << "s" << " ";
			}
			if (ev.key.code == sf::Keyboard::Right)
			{
				Gracz2.zmienKierunek('d', Mapa);
				//	std::cout << "RIGHT" << " ";
			}
			if (ev.key.code == sf::Keyboard::Left)
			{
				Gracz2.zmienKierunek('a', Mapa);
				//	std::cout << "LEFT" << " ";
			}
			if (ev.key.code == sf::Keyboard::Up)
			{
				Gracz2.zmienKierunek('w', Mapa);
				//	std::cout << "UP" << " ";
			}
			if (ev.key.code == sf::Keyboard::Down)
			{
				Gracz2.zmienKierunek('s', Mapa);
				//	std::cout << "DOWN" << " ";
			}
		}
	}
}

void Gra::wyborIlosciGraczy()
{
	iloscGraczy = 0;
	this->window->clear(sf::Color::Black);
	text.setString("Aby zagrac samemu wcisnij S,aby zmierzyc sie z przyjacielem wcisnij M");
	text.setPosition(0, 400);
	window->draw(text);
	this->window->display();
	while (iloscGraczy == 0)
	{
		while (this->window->pollEvent(ev))
		{
			switch (this->ev.type)
			{
			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::S)
				{
					this->iloscGraczy = 1;
				}
				if (ev.key.code == sf::Keyboard::M)
				{
					this->iloscGraczy = 2;
				}
			}
		}
	}
}

void Gra::utworzGre()
{
	wzmocnienie1 = true;
	wzmocnienie2 = true;
	wzmocnienie3 = true;
	wzmocnienie4 = true;
	ilePunktowDoZdobycia = 0;
	walka = -1;
	if (iloscGraczy == 2)
	{
		punkty[10][17] = 1;
		Gracz1.dodajGracza(10, 1, 1);
		Gracz2.dodajGracza(10, 17, 2);
		duch1.dodajDucha(10, 10);
		duch2.dodajDucha(10, 9);
		duch3.dodajDucha(10, 8);
	}
	else
	{
		Gracz1.dodajGracza(10, 1, 1);
		punkty[10][17] = 0;
		duch1.dodajDucha(10, 10);
		duch2.dodajDucha(10, 9);
		duch3.dodajDucha(10, 8);
	}
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (punkty[i][j] == 0)
			{
				ilePunktowDoZdobycia++;
			}

			punktyWGrze[i][j] = punkty[i][j];
		}
	}
}

bool Gra::koniecGry()
{
	if (walka != -1)
	{
		if (walka == 0)
		{
			text.setPosition(264, 30 * 19);
			text.setString("Duchy wygraly");
			this->window->draw(text);
			this->window->display();
			return 1;
		}
		if (walka == 1)
		{
			text.setPosition(253, 30 * 19);
			text.setString("Gracz 1 wygral");
			this->window->draw(text);
			this->window->display();
			return 1;
		}
		if (walka == 2)
		{
			text.setPosition(253, 30 * 19);
			text.setString("Gracz 2 wygral");
			this->window->draw(text);
			this->window->display();
			return 1;
		}
	}
	if (ilePunktowDoZdobycia == 0)
	{
		if (iloscGraczy == 1)
		{
			text.setPosition(286, 30 * 19);
			text.setString("Wygrales");
			this->window->draw(text);
			this->window->display();
			return 1;
		}
		else
		{
			if (Gracz1.pokazPunktyInt() > Gracz2.pokazPunktyInt())
			{
				text.setPosition(253, 30 * 19);
				text.setString("Gracz 1 wygral");
				this->window->draw(text);
				this->window->display();
				return 1;
			}
			else if (Gracz2.pokazPunktyInt() > Gracz1.pokazPunktyInt())
			{
				text.setPosition(253, 30 * 19);
				text.setString("Gracz 2 wygral");
				this->window->draw(text);
				this->window->display();
				return 1;
			}
			else
			{
				text.setPosition(308, 30 * 19);
				text.setString("Remis");
				this->window->draw(text);
				this->window->display();
				return 1;
			}
		}
	}
	if (iloscGraczy == 1)
	{
		if (Gracz1.wGrze() == 0)
		{
			text.setPosition(275, 30 * 19);
			text.setString("Przegrales");
			this->window->draw(text);
			this->window->display();
			return 1;
		}
	}
	else
	{
		if (Gracz1.wGrze() == 0)
		{
			text.setPosition(253, 30 * 19);
			text.setString("Gracz 2 wygral");
			this->window->draw(text);
			this->window->display();
			return true;
		}
		if (Gracz2.wGrze() == 0)
		{
			text.setPosition(253, 30 * 19);
			text.setString("Gracz 1 wygral");
			this->window->draw(text);
			this->window->display();
			return true;
		}
	}

	return false;
}
int Gra::walkaPacmanow()//0-dwojka graczy przegrywa//1-gracz pierwszy wygrywa//2-gracz drugi wygyrwa
{
	if (Gracz1.czyWzmocniony() == Gracz2.czyWzmocniony())
	{
		return 0;
	}
	if (Gracz1.czyWzmocniony() == true)
	{
		return 1;
	}
	return 2;
}