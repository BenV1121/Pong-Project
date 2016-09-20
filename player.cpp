#include "sfwdraw.h"
#include "Player.h"

using namespace sfw;

void Player::init(float a_x, char a_up, char a_down, char a_fire, unsigned a_color)
{
	x = a_x;
	y = 300;

	up = a_up;
	down = a_down;
	fire = a_fire;

	size = 75;

	color = a_color;

	if (x < 400)
	{
		ora.init(x, y);
	}
	else
	{
		muda.init(x, y);
	}

}

void Player::draw() const
{
	if (x < 400)
	{
		ora.draw();
	}
	else
	{
		muda.draw();
	}

	drawLine(x, y, x, y + size, color);
}

void Player::update()
{
	if (x < 400)
	{
		ora.update();
	}
	else
	{
		muda.update();
	}

	if (getKey(up))
	{
		y += getDeltaTime() * 500;
	}

	// If the key is S, then P1 will go down (-=) by the speed of delta time times 500
	if (getKey(down))
	{
		y -= getDeltaTime() * 500;
	}

	if (getKey(fire))
	{
		shout();
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

void Player::shout()
{
	if (x < 400 && !ora.active)
	{
		ora.x = x;
		ora.y = y;
		ora.active = true;
	}
	else if (x > 400 && !muda.active)
	{
		muda.x = x;
		muda.y = y;
		muda.active = true;
	}

}