#include "sfwdraw.h"
#include "Ball.h"

int score1 = 0;
int score2 = 0;

Ball createBall(float b_xpos, float b_ypos, float b_xvel, float b_yvel, float b_rad, unsigned b_steps)
{
	Ball ret;
	ret.xpos = b_xpos;
	ret.ypos = b_ypos;
	ret.xvel = b_xvel;
	ret.yvel = b_yvel;
	ret.radius = b_rad;
	ret.steps = b_steps;

	return ret;
}

void drawBall(const Ball &b)
{
	drawCircle(b.xpos, b.ypos, b.radius, b.steps, BLACK);
}

void updateBall(Ball &b)
{
	unsigned d = loadTextureMap("./res/fontmap.png", 16, 16);

	b.xpos += b.xvel * getDeltaTime();
	b.ypos += b.yvel * getDeltaTime();

	if (b.ypos < 0)
	{
		b.yvel *= -1;
	}

	if (b.ypos > 600)
	{
		b.yvel *= -1;
	}

	if (b.xpos < 0)
	{
		//b.xvel *= -1;
		b.xpos = 400;
		b.ypos = 300;

		b.xvel = rand() % 1000 - 10;
		b.yvel = rand() % 1000 - 10;

		std::cout << "Score: " << ++score2 << std::endl;
	}

	if (b.xpos > 800)
	{
		//b.xvel *= -1;
		b.xpos = 400;
		b.ypos = 300;

		b.xvel = rand() % 1000 - 1010;
		b.yvel = rand() % 1000 - 1010;
		
		std::cout << "Score: " << ++score1 << std::endl;
	}
	drawString(d, std::to_string(score1).c_str(), 0, 580, 40, 40, '\0');
	drawString(d, std::to_string(score2).c_str(), 755, 580, 40, 40, '\0');
}

