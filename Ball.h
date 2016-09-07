#pragma once
#include <cstdlib>
#include <random>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "sfwdraw.h"

using namespace sfw;

struct Ball
{
	float xpos, ypos;
	float xvel, yvel;
	float radius;
	unsigned steps;
};

Ball createBall(float b_xpos, float b_ypos, float b_xvel, float b_yvel, float b_rad, unsigned b_steps);
void drawBall(const Ball &b);
void updateBall(Ball &b);