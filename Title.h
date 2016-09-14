#pragma once

#include "constdec1.h"

class Title
{
	int font;
public:
	// Called on startup
	void init(int a_font);
	// Called on update
	void draw();

	APP_STATE next();
};