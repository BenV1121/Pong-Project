#include "sfwdraw.h"
#include "Ball.h"

int score1 = 0;
int score2 = 0;

void Ball::init(float b_xpos, float b_ypos, float b_xvel, float b_yvel, float b_rad, unsigned b_steps)
{
	xpos = b_xpos;
	ypos = b_ypos;
	xvel = b_xvel;
	yvel = b_yvel;
	radius = b_rad;
	steps = b_steps;
}


void Ball::draw() const
{
	drawCircle(xpos, ypos, radius, steps, WHITE);
}

void Ball::update()
{
	unsigned d = loadTextureMap("./res/fontmap.png", 16, 16);

	xpos += xvel * getDeltaTime();
	ypos += yvel * getDeltaTime();

	if (ypos < 0)
	{
		yvel *= -1;
	}

	if (ypos > 600)
	{
		yvel *= -1;
	}

	if (xpos < 0)
	{
		//b.xvel *= -1;
		xpos = 400;
		ypos = 300;

		xvel = rand() % 1000 - 10;
		yvel = rand() % 1000 - 10;

		std::cout << "Score: " << ++score2 << std::endl;
	}

	if (xpos > 800)
	{
		//b.xvel *= -1;
		xpos = 400;
		ypos = 300;

		xvel = rand() % 1000 - 1010;
		yvel = rand() % 1000 - 1010;

		std::cout << "Score: " << ++score1 << std::endl;
	}
	drawString(d, std::to_string(score1).c_str(), 0, 580, 40, 40, '\0');
	drawString(d, std::to_string(score2).c_str(), 705, 580, 40, 40, '\0');
}

