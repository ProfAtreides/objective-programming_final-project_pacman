#pragma once
#include <iostream>
class Gracz
{
private:
	int x, y;
	int ost_x, ost_y;
	int kierunek = -1;
	bool Zjedzony = false;
	int numer;//1,2
	int punkty;
	int iniemamocny = 0;
	bool wzmocniony = false;
	int nastepny_kierunek = -1;
public:
	//0-gora,1-prawo,2-dol,3-lewo
	bool wGrze();
	void Porazka();
	void zmienKierunek(char znak, bool Mapa[22][19]);
	void Ruch(bool Mapa[22][19]);
	int getY();
	int getX();
	int getOstY();
	int getOstX();
	void dodajGracza(int x_set, int y_set, int numerGracza);
	void dodajPunkty();
	std::string pokazPunktyString();
	int pokazPunktyInt();
	void zjedzDucha();
	bool zjedzonyPrzezGracza(Gracz zjadany);
	void wzmocnijGracza();
	bool czyWzmocniony();
	void skrocWzmocnienieORunde();
	int zwrocKierunek();
};
