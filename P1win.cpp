#include "P1win.h"
#include "sfwdraw.h"

void P1win::init(int a_font)
{
	font = a_font;
}

void P1win::draw()
{
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	sfw::drawString(d, "PLAYER 1 WINS", 200, 40, 20, 20, 0, '\0', RED);
	sfw::drawString(d, "Sabaku no wa ore no Stando da!", 500, 40, 40, 40, 0, '\0', BLUE);
}

