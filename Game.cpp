#include "pch.h"
#include "Game.h"

int x_axis = 25;
int y_axis = 1;
int health = 100;
int coinCount = 0;
int levelUp = 0;
string script = "";
bool scriptShowed = false;
bool key = false;

//map[rows][colomns]
char map[49][108] = {
	"###########################           ########           #########################   ######################",
	"#                         #          #   LP   #          #                       #   #    }              F#",
	"#              C          #         #    ##    #         #       ?        ?      #   #    #################",
	"#     #####################        #    #  #    #        #                       #   #    #                ",
	"#     #                           #    #    #    #       #     #####    #####    #   #    #                ",
	"#     #       #############      #    #  K   #    #      #     #   #    #   #    #   #    #                ",
	"#     #       #           #     #    ##########    #     #     #   #    #   #T   #   #    #################",
	"#  T  #       #     ?     #    #                    #    #     #   #    #   #   T#   #                    #",
	"#     #       #           #   ########################   #     #   #    #   #T   #   #    #################",
	"#     #       #######     #   #                      #   #     #   #    #   #   T#   #    #                ",
	"#     #             #     #   #   ################   #   #     #   #    #   #T   #   #    #                ",
	"#     ###############     #   #   #              #   #   #     #   #    #   #   T#   #    #                ",
	"#                         #   #   #              #   #   #     #   #    #   #T   #   #    #################",
	"#          C              #   #   #              #   #   #     #   #    #   #    #   #            H       #",
	"###########################   #####              #####   #######   ######   ######   ######################",
	"                                                                                                           ",
	"                                                                                                           ",
	"                                                                                                           ",
	"                               #                                        #                                  ",
	"                              # #                                      # #                                 ",
	"                             #   #                                    #   #                                ",
	"                            #     #                                  #     #                               ",
	"                           #  ###  #                #               #  ###  #                              ",
	"                           #  ###  #               # #              #  ###  #                              ",
	"                            #     #               #   #              #     #                               ",
	"                             #   #               #     #              #   #                                ",
	"                              # #               #       #              # #                                 ",
	"                               #               #  #####  #              #                                  ",
	"                                              #  #     #  #                                                ",
	"                                             #   #     #   #                                               ",
	"                                            #    #######    #                                              ",
	"                                           #                 #                                             ",
	"                                          #       #####       #                                            ",
	"                                         #       #     #       #                                           ",
	"                                          #     #       #     #                                            ",
	"                                           #####         #####                                             ",
	"                   																                        ",
	"                   																						",
	"                   #######                                                    #######						",
	"                   #     #                                                    #     #						",
	"                   #     #                                                    #     #					    ",
	"                   #     #                                                    #     #						",
	"                   #     #                                                    #     #						",
	"                    #     #                                                  #     #						",
	"                     #     #                                                #     #						",
	"                      #     #                                              #     #						    ",
	"                        #     #############################################     #							",
	"                         #                                                     #							",
	"                          #####################################################							" };

Game::Game()
{
}


Game::~Game()
{
}

void Game::movement(int vertical, int horizontal)
{
	/*Function takes Takes two inputs. Function controls player functionality*/
	int x2_axis = x_axis + horizontal;
	int y2_axis = y_axis + vertical;

	if (map[y2_axis][x2_axis] == 'C')
	{
		coinCount++;
	}

	if (map[y2_axis][x2_axis] == 'L')
	{
		levelUp++;
	}

	if (map[y2_axis][x2_axis] == '?')
	{
        //calls function pickRandomLetter from Game.h file
		map[y2_axis][x2_axis + 1] = pickRandomLetter();
		map[y2_axis][x2_axis - 1] = pickRandomLetter();
		map[y2_axis - 1][x2_axis] = pickRandomLetter();
		map[y2_axis + 1][x2_axis] = pickRandomLetter();
		map[y2_axis + 1][x2_axis - 1] = pickRandomLetter();
		map[y2_axis - 1][x2_axis - 1] = pickRandomLetter();
		map[y2_axis - 1][x2_axis + 1] = pickRandomLetter();
		map[y2_axis + 1][x2_axis + 1] = pickRandomLetter();
		script = "YOU OPENED A CHEST, ENJOY YOUR GOODIES";
		scriptShowed = true;
	}

	if (map[y2_axis][x2_axis] == 'L')
	{
		script = "YOUR LEVEL HAS BEEN INCREASED";
		scriptShowed = true;
	}

	if (map[y2_axis][x2_axis] == 'K')
	{
		key = true;
		script = "YOU HAVE AQUIRED THE KEY";
		scriptShowed = true;
	}

	if (map[y2_axis][x2_axis] == 'P')
	{
		script = "YOU GAINED A POTION";
		health += 20;
		scriptShowed = true;
	}

	if (map[y2_axis][x2_axis] == 'M')
	{
		script = "YOU ARE BEING ATTACKED\nHEALTH DECREASING...";
		scriptShowed = true;
	}

	if (map[y2_axis][x2_axis] == 'T')
	{
		script = "YOU ENTERED A TRAP";
		health = 0;
		scriptShowed = true;
	}

	if (map[y2_axis][x2_axis] == 'H')
	{
		script = "LUCKY YOU! YOUR HEALTH IS BACK TO FULL";
		health = 100;
		scriptShowed = true;
	}

	if (map[y2_axis][x2_axis] == '}' && !key)
	{
		script = "YOU NEED THE KEY TO PASS THE BARRIER";
		scriptShowed = true;
	}

	//moving into the object from right or left
	if (map[y_axis][x2_axis] == ' '
		|| map[y_axis][x2_axis] == 'C'
		|| map[y_axis][x2_axis] == 'P'
		|| map[y_axis][x2_axis] == 'L'
		|| map[y_axis][x2_axis] == '?'
		|| map[y_axis][x2_axis] == 'K'
		|| map[y_axis][x2_axis] == 'T'
		|| map[y_axis][x2_axis] == 'H'
		|| map[y_axis][x2_axis] == 'F'
		|| map[y_axis][x2_axis] == '>'
		|| map[y_axis][x2_axis] == '<'
		|| map[y_axis][x2_axis] == '}' && key)
	{
		map[y_axis][x_axis] = ' ';
		x_axis += horizontal;
		map[y_axis][x_axis] = 'G';
	}

	//when moving into object from above or below
	if (map[y2_axis][x_axis] == ' '
		|| map[y2_axis][x_axis] == 'C'
		|| map[y2_axis][x_axis] == 'P'
		|| map[y2_axis][x_axis] == 'L'
		|| map[y2_axis][x_axis] == '?'
		|| map[y2_axis][x_axis] == 'K'
		|| map[y2_axis][x_axis] == 'T'
		|| map[y2_axis][x_axis] == 'H'
		|| map[y2_axis][x_axis] == 'F'
		|| map[y2_axis][x_axis] == '>'
		|| map[y2_axis][x_axis] == '<'
		|| map[y2_axis][x_axis] == '}' && key)
	{
		map[y_axis][x_axis] = ' ';
		y_axis += vertical;
		map[y_axis][x_axis] = 'G';
	}
}