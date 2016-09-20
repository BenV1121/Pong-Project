#pragma once
#include "Player.h"
#include "Ball.h"
#include "ORA.h"
#include "MUDA.h"

#include "constdec1.h"

class GameState
{
	Player player1, player2;
	Ball ball;

	unsigned font;

public:
	void init();
	void update();
	void draw() const;
	APP_STATE next() const;


	int getp1Score() const { return ball.p1Score; }
	int getp2Score() const { return ball.p2Score; }
};
