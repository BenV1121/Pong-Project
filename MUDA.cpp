#include "sfwdraw.h"
#include "MUDA.h"

using namespace sfw;

void MUDA::init(float o_x, float o_xvel)
{
	active = false;
	x = o_x;
	y = 400;
	xvel = o_xvel;
	size = 50;
}

void MUDA::draw() const
{
	if (active)
	{
		unsigned d = sfw::loadTextureMap("./res/dio_font.png", 16, 6);
		drawString(d, "Z[", x, y, size, size, 0, '\0', YELLOW);
	}
}

void MUDA::update()
{
	if (active)
	{
		x -= sfw::getDeltaTime() * 5000;

		if (x < 0)
		{
			active = false;
		}
	}
}