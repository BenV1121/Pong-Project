#include "sfwdraw.h"
#include "Player.h"

using namespace sfw;

void Player::init(float a_x, char a_up, char a_down, unsigned a_color)
{
	x = a_x;
	y = 300;

	up = a_up;
	down = a_down;

	size = 75;

	color = a_color;
}

void Player::draw() const
{
	drawLine(x, y, x, y + size, color);
}

void Player::update()
{

	if (getKey(up))
	{
		y += getDeltaTime() * 500;
	}

	// If the key is S, then P1 will go down (-=) by the speed of delta time times 500
	if (getKey(down))
	{
		y -= getDeltaTime() * 500;
	}


	if (y < -50)
	{
		y = 600;
	}

	if (y > 600)
	{
		y = -50;
	}
}