#pragma once
#include <glut.h>

class Table {
public:
	Table();
	~Table();
	static void drawTable();
	static void drawLeg(float xOffset, float zOffset);
};

