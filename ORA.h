#pragma once
#include "sfwdraw.h"

using namespace sfw;

class ORA
{
public:
	float x;
	float xvel;
	char up, down;

	void init(float o_x, float o_xvel, char o_up, char o_down);
	void draw() const;
	void update();
};