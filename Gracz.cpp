#include "Gracz.h"
int Gracz::getX()
{
	return x;
}
int Gracz::getY()
{
	return y;
}
int Gracz::getOstX()
{
	return ost_x;
}
int Gracz::getOstY()
{
	return ost_y;
}

void Gracz::Porazka()
{
	Zjedzony = true;
}
void Gracz::zmienKierunek(char znak, bool Mapa[22][19])
{
	switch (znak)
	{
	case 'w':
		if (Mapa[x][y - 1] == false)
		{
			kierunek = 0;
		}
		else
		{
			nastepny_kierunek = 0;
		}
		break;
	case 'd':
		if (Mapa[x + 1][y] == false)
		{
			kierunek = 1;
		}
		else
		{
			nastepny_kierunek = 1;
		}
		break;
	case 's':
		if (Mapa[x][y + 1] == false)
		{
			kierunek = 2;
		}
		else
		{
			nastepny_kierunek = 2;
		}
		break;
	case 'a':
		if (Mapa[x - 1][y] == false)
		{
			kierunek = 3;
		}
		else
		{
			nastepny_kierunek = 3;
		}
		break;
	}
}
bool Gracz::wGrze()
{
	if (Zjedzony == false)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void Gracz::Ruch(bool Mapa[22][19])
{
	if (kierunek == 0)
	{
		if (Mapa[x][y - 1] == false)
		{
			y--;
		}
		if (nastepny_kierunek == 1 && Mapa[x + 1][y] == false)
		{
			kierunek = 1;
			nastepny_kierunek = -1;
		}
		if (nastepny_kierunek == 2 && Mapa[x][y + 1] == false)
		{
			kierunek = 2;
			nastepny_kierunek = -1;
		}
		if (nastepny_kierunek == 3 && Mapa[x - 1][y] == false)
		{
			kierunek = 3;
			nastepny_kierunek = -1;
		}
	}
	else if (kierunek == 1)
	{
		if (Mapa[x + 1][y] == false)
		{
			x++;
		}
		if (nastepny_kierunek == 0 && Mapa[x][y - 1] == false)
		{
			kierunek = 0;
			nastepny_kierunek = -1;
		}
		if (nastepny_kierunek == 2 && Mapa[x][y + 1] == false)
		{
			kierunek = 2;
			nastepny_kierunek = -1;
		}
		if (nastepny_kierunek == 3 && Mapa[x - 1][y] == false)
		{
			kierunek = 3;
			nastepny_kierunek = -1;
		}
	}
	else if (kierunek == 2)
	{
		if (Mapa[x][y + 1] == false)
		{
			y++;
		}
		if (nastepny_kierunek == 0 && Mapa[x][y - 1] == false)
		{
			kierunek = 0;
			nastepny_kierunek = -1;
		}
		if (nastepny_kierunek == 1 && Mapa[x + 1][y] == false)
		{
			kierunek = 1;
			nastepny_kierunek = -1;
		}
		if (nastepny_kierunek == 3 && Mapa[x - 1][y] == false)
		{
			kierunek = 3;
			nastepny_kierunek = -1;
		}
	}
	else if (kierunek == 3)
	{
		if (Mapa[x - 1][y] == false)
		{
			x--;
		}
		if (nastepny_kierunek == 0 && Mapa[x][y - 1] == false)
		{
			kierunek = 0;
			nastepny_kierunek = -1;
		}
		if (nastepny_kierunek == 1 && Mapa[x + 1][y] == false)
		{
			kierunek = 1;
			nastepny_kierunek = -1;
		}
		if (nastepny_kierunek == 2 && Mapa[x][y + 1] == false)
		{
			kierunek = 2;
			nastepny_kierunek = -1;
		}
	}
}
void Gracz::dodajGracza(int x_set, int y_set, int numerGracza)
{
	x = x_set;
	y = y_set;
	kierunek = -1;
	numer = numerGracza;
	Zjedzony = false;
	punkty = 0;
}
void Gracz::dodajPunkty()
{
	punkty += 100;
}
std::string Gracz::pokazPunktyString()
{
	bool zeraUzupelnione = false;
	std::string punktyNapis = "";
	std::string punktyNapisOdwrocony = "";
	int punktyPom = punkty;
	while (punktyPom > 0)
	{
		punktyNapis += punktyPom % 10 + 48;
		punktyPom /= 10;
	}
	if (punkty == 0)
	{
		punktyNapisOdwrocony = "0000";
		zeraUzupelnione = true;
	}
	if (punkty < 100 && zeraUzupelnione == false)
	{
		punktyNapisOdwrocony = "00";
		zeraUzupelnione = true;
	}
	if (punkty < 1000 && zeraUzupelnione == false)
	{
		punktyNapisOdwrocony = "0";
	}
	for (int i = 0; i < punktyNapis.length(); i++)
	{
		punktyNapisOdwrocony += punktyNapis[punktyNapis.length() - 1 - i];
	}
	return punktyNapisOdwrocony;
}
int Gracz::pokazPunktyInt()
{
	return punkty;
}
void Gracz::zjedzDucha()
{
	punkty += 200;
}
bool Gracz::czyWzmocniony()
{
	return wzmocniony;
}
void Gracz::wzmocnijGracza()
{
	wzmocniony = true;
	iniemamocny = 12;
}
void Gracz::skrocWzmocnienieORunde()
{
	if (iniemamocny == 0)
	{
		wzmocniony = false;
	}
	else
	{
		iniemamocny--;
	}
}
int Gracz::zwrocKierunek()
{
	return kierunek;
}