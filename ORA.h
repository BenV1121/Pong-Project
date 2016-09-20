#pragma once
#include "sfwdraw.h"
#include "Ball.h"

using namespace sfw;

class ORA
{
public:
	float x, y;
	float xvel;
	float size;

	bool active;

	void init(float o_x, float o_xvel);
	void draw() const;
	void update();
};