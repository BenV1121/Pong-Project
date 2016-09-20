#pragma once

#include "constdec1.h"

class EndState
{
	int p1score, p2score;
	int font;
public:
	void init(int a_font);
	void play(int s1, int s2);
	void update();
	void draw() const;
	APP_STATE next() const;
};
