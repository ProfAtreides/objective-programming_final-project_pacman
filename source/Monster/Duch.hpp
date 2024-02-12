#pragma once
#include <iostream>
#include <vector>
#include "../Player/Gracz.hpp"
class Duch
{
private:
	int x_start, y_start;
	int x_poprzednie, y_poprzednie;
	int x, y;
	bool zjedzony;
	int ileRundDoRegenracjiPoZjedzeniu;
	int predkosc;
public:
	void zmniejszRundyDoRegenracji();
	bool czyZjedzonyPrzezGracza();
	void dodajDucha(int x_pom, int y_pom);
	int getY();
	int getX();
	void ustawKordy(int x_set, int y_set);
	void poscig(std::vector < std::pair<int, int>>Krawedzie[22][19], Gracz scigany);
	void ruchLosowy(std::vector <std::pair<int, int >> listaRuchow);
	void ruch(std::vector<std::pair<int, int>>Krawedzie[22][19], Gracz scigany);
	void zjedzonyPrzezGracza();
	bool zjedzGracza(Gracz scigany);
	bool czyZjedzony();
};
