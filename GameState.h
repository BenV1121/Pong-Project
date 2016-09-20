#pragma once
#include "Player.h"
#include "Ball.h"
#include "ORA.h"
#include "MUDA.h"

class GameState
{
	Player player1, player2;
	Ball ball;

	unsigned font;

public:
	void init();
	void update();
	void draw() const;
};
