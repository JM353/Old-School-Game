#ifndef ENEMY_H
#define ENEMY_H
#pragma once

class enemy
{
public:
	enemy();
	~enemy();
	void movement(int vertical, int horizontal);;
	int init(int vertical, int horizontal);

	int ex_axis = 0;
	int ey_axis = 0;
	char minion = 'M';

	bool setLocal = false;
	bool sightedLetterG = false;
};

extern int ex_axis;
extern int ey_axis;

#endif