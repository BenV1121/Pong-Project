#pragma once
#include "sfwdraw.h"
#include "Ball.h"

using namespace sfw;

class MUDA
{
public:
	float x, y;
	float xvel;
	bool active;
	float size;

	Ball ball;

	void init(float o_x, float o_xvel);
	void draw() const;
	void update();
};