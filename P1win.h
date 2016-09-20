#pragma once

#include "constdec1.h"

class P1win
{
	int font;
public:
	// Called on startup
	void init(int a_font);
	// Called on update
	void draw();
};