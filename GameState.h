#pragma once
#include "Player.h"
#include "Ball.h"

// Move variables into a big game state struct.
struct GameState
{
	Player player1, player2;
	Ball ball;

	float topBoundary, bottomBoundary;

	int p1score, p2score;
};

// Set up the starting values for everything.
GameState createGameState(GameState &gs);

// should call update and collision related function
// also check for anything else that isn't
// part of any of our structs.
void updateGameState(GameState &gs)
{
	updatePlayer(gs.player1);
	updatePlayer(gs.player2);
}

// Drawing functions go in here.
void drawGameState(GameState &gs);