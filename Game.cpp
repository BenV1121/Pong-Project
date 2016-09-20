#include "Game.h"
#include "sfwdraw.h"
#include "Ball.h"

void Game::init(int a_font)
{
	font = a_font;
}

void Game::draw()
{
	sfw::drawString(font, "GAME State", 100, 100, 20, 20);
}

APP_STATE Game::next()
{
	return END;
}