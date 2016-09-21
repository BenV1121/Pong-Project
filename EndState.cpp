#include "EndState.h"
#include "Ball.h"
#include "sfwdraw.h"

void EndState::play(int s1, int s2)
{
	p1score = s1;
	p2score = s2;
}

void EndState::init(int a_font)
{
	font = a_font;
}

void EndState::update()
{
}

void EndState::draw() const
{
	unsigned j = sfw::loadTextureMap("./res/Joe.png");
	unsigned d = sfw::loadTextureMap("./res/Di.png");

	if		(p2score <= 0)
	{
		drawTexture(j, 0, 600, 800, 600, 0, false, 0, WHITE);
		sfw::drawString(font, "PLAYER 1 WINS", 320, 550, 20, 20, 0, '\0', RED);
		sfw::drawString(font, "SABAKU NO WA ORE NO STANDO DA!", 16, 100, 25, 25, 0, '\0', BLUE);
	}
	else if (p1score <= 0)
	{
		drawTexture(d, 0, 600, 800, 600, 0, false, 0, WHITE);
		sfw::drawString(font, "PLAYER 2 WINS", 320, 550, 20, 20, 0, '\0', BLUE);
		sfw::drawString(font, "WRRRRRRRRYYYYYYYYYYYYYYYYYYYYYYY!", 1, 100, 30, 30, 0, '\0', YELLOW);
	}

	sfw::drawString(font, "Press Enter to return to the Splash Screen.", 30, 30, 15, 15, 0, '\0', BLACK);
}

APP_STATE EndState::next() const
{
	if (sfw::getKey(KEY_ENTER))
		return SPLASH;
	else
		return END;
}
