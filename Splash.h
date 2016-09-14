#pragma once

#include "constdec1.h"

class Splash
{
	int font;
	float timer;
public:
	// Called on startup
	void init(int a_font);
	void play();
	// Called on update
	void draw();
	void step();

	APP_STATE next();
};