#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include "Game.h"
#include "MenuFile.h"
#include "enemy.h"
#include <Windows.h>
using namespace std;

bool is_game_running = true;
Game game;

//objects
enemy minion1;
enemy minion2;

int main()
{
    /*Main function runs the game, displays stats, controls portals, makes use of keys and draws the map*/
	mainMenu();
	while (is_game_running)
	{
		system("cls");
		stringstream forCoin;
		forCoin << coinCount;
		string coin = "Coin: ";
		coin += forCoin.str();

		stringstream forLevel;
		forLevel << levelUp;
		string level = "Level: ";
		level += forLevel.str();

		stringstream forHealth;
		forHealth << health;
		string health_str = "Health: ";
		health_str += forHealth.str();

		//locates portals and ending 
		map[12][25] = '>';
		map[13][31] = '<';
		map[13][52] = '>';
		map[12][58] = '<';
		map[4][58] = '<';
		map[5][37] = '>';
		map[3][42] = '>';
		map[12][80] = '>';
		map[13][86] = '<';
		map[1][105] = 'F';

		for (int i = 0; i < 49; i++)
		{
			cout << map[i] << endl; // draws map
		}

		//Displays stats
		for (int i = 0; i < 1; i++)
		{
			cout << health_str << endl;
		}

		for (int i = 0; i < 1; i++)
		{
			cout << coin << endl;
		}

		for (int i = 0; i < 1; i++)
		{
			cout << level << endl;
		}

		for (int i = 0; i < 1; i++)
		{
			cout << script << endl;
		}

		system("pause>nul");

		//initialise location of enemies on map 
		minion1.init(10, 60);
		minion2.init(7, 87);

		//enables keys to be used to contyrol player movement
		if (GetAsyncKeyState(VK_UP))
		{
			game.movement(-1, 0);
		}


		if (GetAsyncKeyState(VK_RIGHT))
		{
			game.movement(0, 1);
		}

		if (GetAsyncKeyState(VK_LEFT))
		{
			game.movement(0, -1);
		}

		if (GetAsyncKeyState(VK_DOWN))
		{
			game.movement(1, 0);
		}

		//removes text 
		if (GetAsyncKeyState(VK_BACK) && scriptShowed)
		{
			script = "";
		}
        
        //Control portals
		if (y_axis == 12 && x_axis == 25)
		{
			y_axis = 12;
			x_axis = 31;
		}

		if (y_axis == 13 && x_axis == 31)
		{
			y_axis = 13;
			x_axis = 25;
		}

		if (y_axis == 13 && x_axis == 52)
		{
			y_axis = 13;
			x_axis = 58;
		}

		if (y_axis == 12 && x_axis == 58)
		{
			y_axis = 12;
			x_axis = 52;
		}

		if (y_axis == 4 && x_axis == 58)
		{
			y_axis = 4;
			x_axis = 48;
		}

		if (y_axis == 5 && x_axis == 37)
		{
			y_axis = 5;
			x_axis = 39;
		}

		if (y_axis == 3 && x_axis == 42)
		{
			y_axis = 2;
			x_axis = 60;
		}

		if (y_axis == 12 && x_axis == 80)
		{
			y_axis = 12;
			x_axis = 86;
		}

		if (y_axis == 13 && x_axis == 86)
		{
			y_axis = 13;
			x_axis = 80;
		}
        

		if (y_axis == 1 && x_axis == 105)
		{
			mainMenu();
		}

		if (health == 0)
		{
			mainMenu();
		}
	}
	system("pause");
}