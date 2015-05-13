#pragma once
#include <glut.h>
#include "imageloader.h"
#include "texture.h"

class Table {
public:
	Table();
	~Table();
	static void drawTable();
	static void drawLeg(float xOffset, float zOffset);
};

