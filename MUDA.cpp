#include "sfwdraw.h"
#include "MUDA.h"

using namespace sfw;

void MUDA::init(float o_x, float o_xvel, char o_up, char o_down)
{
	x = o_x;
	y = 350;
	xvel = o_xvel;
	up = o_up;
	down = o_down;
}

void MUDA::draw() const
{
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	if (getKey(KEY_RIGHT_ALT))
	{
		int x = 680;

		drawString(d, "MUDA!", x, y, 20, 20, 0, '\0', YELLOW);
		x -= xvel * getDeltaTime();
	}
}

void MUDA::update()
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