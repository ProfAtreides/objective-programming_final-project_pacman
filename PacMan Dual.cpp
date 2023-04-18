#include <vector>
#include <iostream>
#include "Gracz.h"
#include "Gra.h"
int main()
{
	Gra gra;
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
		Sleep(3000);
	}
}