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
	initContext(800, 600, "NSFW Draw");
	setBackgroundColor(WHITE);

	GameState gs;

	gs = createGameState();

	float acc = 0;
	float acc2 = 0;
	float accRand = rand();

	int player = 0;
	
	Player p1 = createPlayer( 10, 'W', 'S');
	Player p2 = createPlayer(790, 'I', 'K');
	

	drawPlayer(gs);

	//Ball b = createBall(400, 290, 100, 100, 10, 30);

	
	while (stepContext())
	{		

			drawLine(400, 0, 400, 600, BLACK);

			updateGameState(gs);
			//renderGameState(gs);

			//updatePlayer(p1);
			//updatePlayer(p2);
			
		/*
		// PADDLE 1
		// If the key is W, then P1 will go up (+=) by the speed of delta time times 500
		if (getKey('W'))
		{
			acc += getDeltaTime() * 500;
		}

		// If the key is S, then P1 will go down (-=) by the speed of delta time times 500
		if (getKey('S'))
		{
			acc -= getDeltaTime() * 500;
		}

		//The line
		drawLine(10, 300 + acc, 10,  250 + acc, RED);

		// PADDLE 2
		// If the key is I, then P2 will go up (+=) by the speed of delta time times 500
		if (getKey('I'))
		{
			acc2 += getDeltaTime() * 500;
		}

		// If the key is K, then P2 will go down (-=) by the speed of delta time times 500
		if (getKey('K'))
		{
			acc2 -= getDeltaTime() * 500;
		}

		//The line
		drawLine(790, 300 + acc2, 790, 250 + acc2, BLUE);
		
		accRand += getDeltaTime() * 100;

		drawCircle(400 + accRand, 300 + accRand, 10, 30, BLACK);
		
		
			updateBall(b);
			
			drawBall(b);

			
			if (b.xpos < p1.x && b.ypos > p1.y && b.ypos < p1.y+p1.size)
			{
				b.xvel *= -1;
				b.xpos = p1.x;
				b.xvel += 50;
				b.yvel += 50;
			}

			if (b.xpos > p2.x && b.ypos > p2.y && b.ypos < p2.y+p2.size)
			{
				b.xvel *= -1;
				b.xpos = p2.x;
				b.xvel -= 50;
				b.yvel -= 50;
			}
			*/

	}
	termContext();
	//termContext();
}