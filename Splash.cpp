#include "Splash.h"
#include "sfwdraw.h"

void Splash::init(int a_font)
{
	font = a_font;
}

void Splash::play()
{
	timer = 7.f;
}

void Splash::draw()
{
	sfw::drawString(font, "This is a Splash Screen", 200, 180, 20, 20);
	sfw::drawString(font, "Please wait", 200, 100, 20, 20);
	sfw::drawLine(100, 80, 100 + 500 * (timer / 7.f), 80, RED);
}

void Splash::step()
{
	timer -= sfw::getDeltaTime();
}

APP_STATE Splash::next()
{
	if (timer < 0)
		return TITLE;
	else
		return SPLASH;
}