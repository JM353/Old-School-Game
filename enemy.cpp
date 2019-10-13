#include "pch.h"
#include "enemy.h"
#include "Game.h"
#include "Windows.h"

int ex_axis = 5;
int ey_axis = 5;

enemy::enemy()
{
}


enemy::~enemy()
{
}

void enemy::movement(int vertical, int horizontal)
{
	/*Function takes two integer inputs. Funtion is used to control enemy functionality i.e. movement*/
	int ex2_axis = ex_axis + horizontal;
	int ey2_axis = ey_axis + vertical;

	if (map[ey2_axis][ex2_axis] == 'G')
	{
		health -= 10;
	}

	//moves right or left
	if (map[ey_axis][ex2_axis] == ' ' || map[ey_axis][ex2_axis] == 'G')
	{
		map[ey_axis][ex_axis] = ' ';
		ex_axis += horizontal;
		map[ey_axis][ex_axis] = minion;
	}

	//moves up or down
	if (map[ey2_axis][ex_axis] == ' ' || map[ey_axis][ex2_axis] == 'G')
	{
		map[ey_axis][ex_axis] = ' ';
		ey_axis += vertical;
		map[ey_axis][ex_axis] = minion;
	}
}


int enemy::init(int vertical, int horizontal)
{
    /*Function takes two integer inputs. Funtion is used to control enemy functionality i.e. locating player and moving towards it for attack*/
	map[vertical][horizontal] = minion;
	//sets location of enemy when initialised 
	if (!setLocal)
	{
		ex_axis = horizontal;
		ey_axis = vertical;
		map[ey_axis][ex_axis] = minion;
		setLocal = true;
	}

	//distance from which player is recognised
	if (ex_axis + x_axis > 15
		&& ey_axis + y_axis > 15
		&& ex_axis - x_axis < 15
		&& ey_axis - y_axis < 15)
	{
		sightedLetterG = true;
	}

	//enemy moves towards player
	if (sightedLetterG)
	{
		if (x_axis > ex_axis)
		{
			enemy::movement(0, 1);
		}

		else if (y_axis > ey_axis)
		{
			enemy::movement(1, 0);
		}

		else if (x_axis < ex_axis)
		{
			enemy::movement(0, -1);
		}

		else if (y_axis < ey_axis)
		{
			enemy::movement(-1, 0);
		}
	}
	return 0;
}