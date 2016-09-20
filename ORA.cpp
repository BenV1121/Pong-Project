#include "sfwdraw.h"
#include "ORA.h"

using namespace sfw;

void ORA::init(float o_x, float o_xvel)
{
	active = false;
	x = o_x;
	y = 400;
	xvel = o_xvel;
	size = 50;
}

void ORA::draw() const
{
	if (active)
	{
		unsigned d = sfw::loadTextureMap("./res/dio_font.png", 16, 6);
		drawString(d, "ab", x, y, size, size, 0, '\0', BLUE);

		
	}
}

void ORA::update()
{
	if (active)
	{
		x += sfw::getDeltaTime() * 5000;

		if (x > 800)
		{
			active = false;
		}
	}
}