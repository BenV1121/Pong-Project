#pragma once
#include "sfwdraw.h"

#include "ORA.h"
#include "MUDA.h"

using namespace sfw;

class Player
{
public:
	// How many variables do I need?
	float x, y;
	float size;
	char up, down, fire;
	unsigned color;

	ORA ora;
	MUDA muda;

	void init(float a_x, char a_up, char a_down, char a_fire, unsigned a_color);
	void draw() const;
	void update();

	void shout();
};