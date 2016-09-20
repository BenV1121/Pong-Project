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

	player1.init (10,	  'W', 'S', 'D', BLUE);
	player2.init (790,	  'I', 'K', 'J', YELLOW);
	ball.init	 (400, 290, 100, 100, 10, 30);

	font = loadTextureMap("./res/fontmap.png", 16, 16);
}

void GameState::draw() const
{
	ball.draw();
	player1.draw();
	player2.draw();

	//sfw::drawString(font, "TEST", 0, 16, 16, 16);
}



void GameState::update()
{
	ball.update();
	std::cout << ball.xpos << " " << ball.ypos << " " << std::endl;
	player1.update();
	player2.update();

	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);

	// Collision with ball and paddles
	if (ball.xpos < player1.x && ball.ypos > player1.y && ball.ypos < player1.y + player1.size )
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

	if (player1.ora.active)
	{
		// Collision with ball and ORA/MUDAs
		if (ball.ypos + ball.radius > player1.ora.y - player1.ora.size &&		// top of ball > bottom of the box
			ball.ypos - ball.radius < player1.ora.y &&							// bot of ball < top of the box
			ball.xpos - ball.radius < player1.ora.x + player1.ora.size * 2 &&	// lef of ball < right of the box
			ball.xpos + ball.radius > player1.ora.x)							// rht of ball > left of the box
		{
			ball.xvel *= -1;
			ball.xpos = player1.ora.x + player1.ora.size * 2;
			ball.ypos = player1.ora.y + player1.ora.size * 1.5f;
			//ball.xvel += 50;
			//ball.yvel += 50;
		}
	}

	if (player2.muda.active)
	{
		if (ball.ypos + ball.radius > player2.muda.y - player2.muda.size &&		// top of ball > bottom of the box
			ball.ypos - ball.radius < player2.muda.y &&							// bot of ball < top of the box
			ball.xpos - ball.radius > player2.muda.x + player2.muda.size * 2 &&	// lef of ball < right of the box
			ball.xpos + ball.radius > player2.muda.x)							// rht of ball > left of the box
		{
			ball.xvel *= -1;
			ball.xpos = player2.muda.x + player2.muda.size * 2;
			ball.ypos = player2.muda.y + player2.muda.size * 1.5f;
			//ball.xvel += 50;
			//ball.yvel += 50;
		}
	}
}

APP_STATE GameState::next() const
{
	if (ball.p1Score >= 10 || ball.p2Score >= 10)
		return ENTER_END;

	return GAME;
}