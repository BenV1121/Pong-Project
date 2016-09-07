#pragma once
#include "sfwdraw.h"

using namespace sfw;

struct Player
{
	// How many variables do I need?
	float x, y;
	float size;
	char up, down;
};
	Player createPlayer(float a_x, char a_up, char a_down);
	void drawPlayer  (const Player &p);
	void drawPlayer2 (const Player &p);
	void updatePlayer(Player &p);