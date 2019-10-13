#ifndef GAME_H
#define GAME_H
#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Game
{
public:
	Game();
	~Game();
	void movement(int vertical, int horizontal);

	char pickRandomLetter()
	{
    /*The Funtion takes no inputs. The aim of the function is to select a random element from a given vector*/
		srand(time(NULL)); //initialize the random seed
		const char arrayNum[5] = { 'C', 'P', 'L', 'T', 'H' };
		int RandIndex = rand() % 6; //generates a random number between 0 and 5
		return arrayNum[RandIndex];
	}
};

extern char map[49][108];
extern int x_axis, y_axis;


extern int health, levelUp, coinCount, potion;
extern string script;
extern bool scriptShowed;
#endif