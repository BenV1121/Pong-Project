#pragma once

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
