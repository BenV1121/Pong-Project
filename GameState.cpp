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
#include "ORA.h"
#include "MUDA.h"

void GameState::init()
{
	//GameState state;

	player1.init (10,	  'W', 'S', BLUE);
	player2.init (790,	  'I', 'K', YELLOW);
	ora.init	 (20,  100, 'W', 'S');
	muda.init	 (720, 100, 'I', 'K');
	ball.init	 (400, 290, 100, 100, 10, 30);

	font = loadTextureMap("./res/fontmap.png", 16, 16);
}


void GameState::draw() const
{
	ball.draw();
	player1.draw();
	player2.draw();
	ora.draw();
	muda.draw();
}

void GameState::update()
{
	ball.update();
	player1.update();
	player2.update();
	ora.update();
	muda.update();

	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);

	// Collision with ball and paddles
	if (ball.xpos < player1.x && ball.ypos > player1.y && ball.ypos < player1.y + player1.size)
	{
		ball.xvel *= -1;
		ball.xpos = player1.x;
		ball.xvel += 50;
		ball.yvel += 50;
	}

	if (ball.xpos > player2.x && ball.ypos > player2.y && ball.ypos < player2.y + player2.size)
	{
		ball.xvel *= -1;
		ball.xpos = player2.x;
		ball.xvel -= 50;
		ball.yvel -= 50;
	}
}