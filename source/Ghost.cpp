#include "Ghost.h"
void Ghost::zmniejszRundyDoRegenracji()
{
	if (ileRundDoRegenracjiPoZjedzeniu > 0)
	{
		ileRundDoRegenracjiPoZjedzeniu--;
	}
	else
	{
		zjedzony = false;
	}
}
bool Ghost::czyZjedzonyPrzezGracza()
{
	if (zjedzony)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Ghost::ustawKordy(int x_set, int y_set)
{
	x = x_set;
	y = y_set;
}

void Ghost::poscig(std::vector < std::pair<int, int>>Krawedzie[22][19], Player scigany)
{
	bool usedGrids[22][19] =
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
	std::vector<std::vector<std::pair<int, int>>> path;//contains all analyses paths to get to player
	std::vector <std::pair<int, int>> final_path;//first path to be found
	final_path.push_back(std::make_pair(x, y));
	path.push_back(final_path);
	final_path.pop_back();
	int player_x = scigany.getX();
	int player_y = scigany.getY();
	int temp_x = x, temp_y = y;//starts with monsters cords,during path fining temp cords will change while possible paths are analyses
	int paths_number = path.size();;//how many paths are the start of the loop
	bool player_found = false;

	while (player_found == false && path.size() > 0)
	{
		for (int i = 0; i < paths_number; i++)
		{
			if (player_found == true)
			{
				break;
			}
			temp_x = path[i].back().first;
			temp_y = path[i].back().second;
			usedGrids[temp_x][temp_y] = 1;
			for (int j = 0; j < Krawedzie[temp_x][temp_y].size(); j++)
			{
				if (usedGrids[Krawedzie[temp_x][temp_y][j].first][Krawedzie[temp_x][temp_y][j].second] == 0)
				{
					if (Krawedzie[temp_x][temp_y][j].first == player_x && Krawedzie[temp_x][temp_y][j].second == player_y)
					{
						player_found = true;
						path.push_back(path[i]);
						path.back().push_back(std::make_pair(player_x, player_y));
						usedGrids[Krawedzie[temp_x][temp_y][j].first][Krawedzie[temp_x][temp_y][j].second] = 1;
						final_path = path.back();
						break;
					}
					else
					{
						usedGrids[Krawedzie[temp_x][temp_y][j].first][Krawedzie[temp_x][temp_y][j].second] = 1;
						path.push_back(path[i]);
						path.back().push_back(Krawedzie[temp_x][temp_y][j]);
					}
				}
			}
		}
		path.erase(path.begin(), path.begin() + paths_number);
		paths_number = path.size();
	}

	if (final_path.size() > 1)
	{
		y = final_path[1].second;
		x = final_path[1].first;
	}
}

void Ghost::ruchLosowy(std::vector <std::pair<int, int >> mozliweRuchy)
{
	srand(time(NULL));
	int pom = rand();
	int seed = pom % mozliweRuchy.size();
	if (mozliweRuchy[seed].first == x_poprzednie && mozliweRuchy[seed].second == y_poprzednie && mozliweRuchy.size() > 1)
	{
		if (seed > 0)
		{
			seed--;
			x_poprzednie = x;
			y_poprzednie = y;
			x = mozliweRuchy[seed].first;
			y = mozliweRuchy[seed].second;
		}
		else
		{
			seed++;
			x_poprzednie = x;
			y_poprzednie = y;
			x = mozliweRuchy[seed].first;
			y = mozliweRuchy[seed].second;
		}
	}
	else
	{
		x_poprzednie = x;
		y_poprzednie = y;
		x = mozliweRuchy[seed].first;
		y = mozliweRuchy[seed].second;
	}
}
void Ghost::ruch(std::vector<std::pair<int, int>> Krawedzie[22][19], Player scigany)
{
	if (zjedzony == false)
	{
		if ((scigany.getX() - x) * (scigany.getX() - x) < 9)
		{
			srand(time(NULL));
			int szansaNaOdpuszczenieGonienia = rand() % 10;
			if (szansaNaOdpuszczenieGonienia != 0)
			{
				poscig(Krawedzie, scigany);
			}
			else
			{
				ruchLosowy(Krawedzie[x][y]);
			}
		}
		else
		{
			ruchLosowy(Krawedzie[x][y]);
		}
	}
}
int Ghost::getX()
{
	return x;
}
void Ghost::dodajDucha(int x_pom, int y_pom)
{
	x_start = x_pom;
	y_start = y_pom;
	y = y_start;
	x = x_start;
	zjedzony = false;
}
bool Ghost::zjedzGracza(Player scigany)
{
	if (scigany.getX() == x && scigany.getY() == y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int Ghost::getY()
{
	return y;
}

void Ghost::zjedzonyPrzezGracza()
{
	ileRundDoRegenracjiPoZjedzeniu = 8;
	ustawKordy(x_start, y_start);
	zjedzony = true;
}
bool Ghost::czyZjedzony()
{
	return zjedzony;
}