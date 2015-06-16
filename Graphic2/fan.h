#pragma once
#include <glut.h>
#include "imageloader.h"
#include "texture.h"

class Fan {
public:
	Fan();
	~Fan();
	static void drawFan();
	static void Fan_physics(int n);

};

