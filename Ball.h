#pragma once
#include <cstdlib>
#include <random>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "sfwdraw.h"

using namespace sfw;

class Ball
{
	public:
	float xpos, ypos;
	float xvel, yvel;
	float radius;
	unsigned steps;
	void init(float b_xpos, float b_ypos, float b_xvel, float b_yvel, float b_rad, unsigned b_steps);
	void draw() const;
	void update();

	int p1Score;
	int p2Score;
};
