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

using namespace sfw;


int main()
{
	initContext(800, 600, "Undefined Pong");

	unsigned r = sfw::loadTextureMap("./res/WoodenTiles.png");

	GameState gs;

	gs.init();

	while (stepContext())
	{		
		sfw::drawTexture(r, 0, 600, 800, 600, 0, false, 0, 0x88888888);
		gs.draw();
		gs.update();
		drawLine(400, 0, 400, 600, BLACK);
	}
	termContext();
}