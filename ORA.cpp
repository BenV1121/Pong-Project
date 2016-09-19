#include "sfwdraw.h"
#include "ORA.h"

using namespace sfw;

void ORA::init(float o_x, float o_xvel, char o_up, char o_down)
{
	x = o_x;
	y = 350;
	xvel = o_xvel;
	up = o_up;
	down = o_down;
}

void ORA::draw() const
{
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	if (getKey(KEY_LEFT_ALT))
	{ 
		drawString(d, "ORA!", x, y, 20, 20, 0, '\0', BLUE);
	}
}

void ORA::update()
{
	if (getKey(up))
	{
		y += getDeltaTime() * 500;
	}

	// If the key is S, then P1 will go down (-=) by the speed of delta time times 500
	if (getKey(down))
	{
		y -= getDeltaTime() * 500;
	}


	if (y < -50)
	{
		y = 600;
	}

	if (y > 600)
	{
		y = -50;
	}
}