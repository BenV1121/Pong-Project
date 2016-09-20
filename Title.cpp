#include "Title.h"
#include "sfwdraw.h"

void Title::init(int a_font)
{
	font = a_font;
}

void Title::draw()
{
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	sfw::drawString(d, "[PRESS SPACE TO PLAY]", 200, 40, 20, 20, 0, '\0', RED);
}

APP_STATE Title::next()
{
	if (sfw::getKey(KEY_SPACE))
		return ENTER_GAME;
	else
		return TITLE;
}