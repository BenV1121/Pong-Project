#include <cstdlib>
#include <random>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "sfwdraw.h"
#include "Player.h"
#include "Ball.h"
#include "GameState.h"
#include "constdec1.h"
#include "Splash.h"
#include "Game.h"
#include "Title.h"

using namespace sfw;


int main()
{
	

	initContext(800, 600, "Undefined Pong");

	unsigned r = sfw::loadTextureMap("./res/Cairo.png");

	unsigned b = sfw::loadTextureMap("./res/SS1.png");

	unsigned t = sfw::loadTextureMap("./res/Title.png");

	unsigned font = sfw::loadTextureMap("./res/fontmap.png", 16, 16);

	Splash splash;
	Game game;
	Title title;

	APP_STATE state = ENTER_SPLASH;

	splash.init(font);
	title.init(font);

	GameState gs;

	gs.init();

	while (stepContext())
	{		
		switch (state)
		{
		case ENTER_SPLASH:
			splash.play();
		case SPLASH:
			splash.step();
			splash.draw();
			state = splash.next();
			drawTexture(b, 0, 600, 800, 600, 0, false, 0, 0x88888888);
			setBackgroundColor(WHITE);
			break;

		case TITLE:
			title.draw();
			state = title.next();
			drawTexture(t, 0, 600, 800, 600, 0, false, 0, 0x88888888);
			break;


		case GAME:
			drawTexture(r, 0, 600, 800, 600, 0, false, 0, 0x88888888);
			gs.draw();
			gs.update();
			drawLine(400, 0, 400, 600, BLACK);

			unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);

			if (getKey(KEY_LEFT_ALT))
			{
				drawString(d, "Yare yare daze.", 50, 50, 20, 20, 0, '\0', WHITE);
			}

			if (getKey(KEY_RIGHT_ALT))
			{
				drawString(d, "KONO DIO DA!", 500, 50, 20, 20, 0, '\0', WHITE);
			}
		}
	}
	termContext();
}