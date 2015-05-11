#include "table.h"


Table::Table() {
}


Table::~Table() {
}


void Table::drawTable() {
	glBegin(GL_QUADS);

	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-6.0f, -0.5f, 9.0f);
	glVertex3f(6.0f, -0.5f, 9.0f);
	glVertex3f(6.0f, 0.5f, 9.0f);
	glVertex3f(-6.0f, 0.5f, 9.0f);

	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(6.0f, -0.5f, -9.0f);
	glVertex3f(6.0f, 0.5f, -9.0f);
	glVertex3f(6.0f, 0.5f, 9.0f);
	glVertex3f(6.0f, -0.5f, 9.0f);

	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-6.0f, -0.5f, -9.0f);
	glVertex3f(6.0f, -0.5f, -9.0f);
	glVertex3f(6.0f, 0.5f, -9.0f);
	glVertex3f(-6.0f, 0.5f, -9.0f);

	//Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-6.0f, -0.5f, -9.0f);
	glVertex3f(-6.0f, 0.5f, -9.0f);
	glVertex3f(-6.0f, 0.5f, 9.0f);
	glVertex3f(-6.0f, -0.5f, 9.0f);

	//Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(6.0f, 0.5f, 9.0f);
	glVertex3f(-6.0f, 0.5f, 9.0f);
	glVertex3f(-6.0f, 0.5f, -9.0f);
	glVertex3f(6.0f, 0.5f, -9.0f);

	//Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(6.0f, -0.5f, 9.0f);
	glVertex3f(-6.0f, -0.5f, 9.0f);
	glVertex3f(-6.0f, -0.5f, -9.0f);
	glVertex3f(6.0f, -0.5f, -9.0f);
	glEnd();

	//front right leg
	drawLeg(3.0f, 7.0f);

	//front left leg
	drawLeg(-4.0f, 7.0f);

	//back right leg
	drawLeg(3.0f, -6.0f);

	//back left leg
	drawLeg(-4.0f, -6.0f);
}

void Table::drawLeg(float xOffset, float zOffset) {
	glBegin(GL_QUADS);

	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(xOffset + 0.0f, -0.5f, zOffset + 0.0f);
	glVertex3f(xOffset + 1.0f, -0.5f, zOffset + 0.0f);
	glVertex3f(xOffset + 1.0f, -6.0f, zOffset + 0.0f);
	glVertex3f(xOffset + 0.0f, -6.0f, zOffset + 0.0f);

	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(xOffset + 0.0f, -0.5f, zOffset + -1.0f);
	glVertex3f(xOffset + 1.0f, -0.5f, zOffset + -1.0f);
	glVertex3f(xOffset + 1.0f, -6.0f, zOffset + -1.0f);
	glVertex3f(xOffset + 0.0f, -6.0f, zOffset + -1.0f);

	//Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(xOffset + 0.0f, -0.5f, zOffset + 0.0f);
	glVertex3f(xOffset + 0.0f, -0.5f, zOffset + -1.0f);
	glVertex3f(xOffset + 0.0f, -6.0f, zOffset + -1.0f);
	glVertex3f(xOffset + 0.0f, -6.0f, zOffset + 0.0f);

	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(xOffset + 1.0f, -0.5f, zOffset + 0.0f);
	glVertex3f(xOffset + 1.0f, -0.5f, zOffset + -1.0f);
	glVertex3f(xOffset + 1.0f, -6.0f, zOffset + -1.0f);
	glVertex3f(xOffset + 1.0f, -6.0f, zOffset + 0.0f);

	//Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(xOffset + 0.0f, -6.0f, zOffset + -1.0f);
	glVertex3f(xOffset + 0.0f, -6.0f, zOffset + 0.0f);
	glVertex3f(xOffset + 1.0f, -6.0f, zOffset + 0.0f);
	glVertex3f(xOffset + 1.0f, -6.0f, zOffset + -1.0f);

	glEnd();
}