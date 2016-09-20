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
#include "EndState.h"

using namespace sfw;


int main()
{
	

	initContext(800, 600, "Undefined Pong");

	unsigned r = sfw::loadTextureMap("./res/Cairo.png");

	unsigned b = sfw::loadTextureMap("./res/SS1.png");

	unsigned t = sfw::loadTextureMap("./res/Title.png");

	unsigned font = sfw::loadTextureMap("./res/fontmap.png", 16, 16);

	//unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);

	Splash splash;
	Title title;
	GameState gs;
	EndState end;

	APP_STATE state = ENTER_SPLASH;

	splash.init(font);
	title.init(font);
	end.init(font);

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

		case ENTER_GAME:
			gs.init();
		case GAME:
			drawTexture(r, 0, 600, 800, 600, 0, false, 0, 0x88888888);
			gs.draw();
			gs.update();
			drawLine(400, 0, 400, 600, BLACK);
			state = gs.next();

			

			if (getKey(KEY_LEFT_ALT))
			{
				drawString(font, "Yare yare daze.", 50, 50, 20, 20, 0, '\0', WHITE);
			}

			if (getKey(KEY_RIGHT_ALT))
			{
				drawString(font, "KONO DIO DA!", 500, 50, 20, 20, 0, '\0', WHITE);
			}
			break;


		case ENTER_END:
			end.play(gs.getp1Score(), gs.getp2Score());
		case END:
			end.update();
			end.draw();

			state = end.next();
			//std::cout << "This is the end!";
			break;
		}
	}
	termContext();
}