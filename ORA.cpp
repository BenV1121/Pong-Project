#include "sfwdraw.h"
#include "ORA.h"

using namespace sfw;

void ORA::init(float o_x, float o_xvel, char o_up, char o_down)
{
	x = o_x;
	xvel = o_xvel;
	up = o_up;
	down = o_down;
}

void ORA::draw() const
{
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	if (sfw::getKey(KEY_LEFT_ALT))
		sfw::drawString(d, "ORA!", 200, 40, 20, 20, 0, '\0', RED);
}

void ORA::update()
{

}