#pragma once
#include "sfwdraw.h"

using namespace sfw;

class Player
{
public:
	// How many variables do I need?
	float x, y;
	float size;
	char up, down;

	void init(float a_x, char a_up, char a_down);
	void draw() const;
	void update();
};