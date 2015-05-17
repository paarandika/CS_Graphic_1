#include "reflection.h"


Reflection::Reflection() {
}


Reflection::~Reflection() {
}

void Reflection::drawReflection() {
	glEnable(GL_STENCIL_TEST); //Enable using the stencil buffer
	glColorMask(0, 0, 0, 0); //Disable drawing colors to the screen
	glDisable(GL_DEPTH_TEST); //Disable depth testing
	glStencilFunc(GL_ALWAYS, 1, 1); //Make the stencil test always pass
	//Make pixels in the stencil buffer be set to 1 when the stencil test passes
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	//Set all of the pixels covered by the floor to be 1 in the stencil buffer
	Room::createRoom();

	glColorMask(1, 1, 1, 1); //Enable drawing colors to the screen
	glEnable(GL_DEPTH_TEST); //Enable depth testing
	//Make the stencil test pass only when the pixel is 1 in the stencil buffer
	glStencilFunc(GL_EQUAL, 1, 1);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP); //Make the stencil buffer not change

	//Draw the cube, reflected vertically, at all pixels where the stencil
	//buffer is 1
	glPushMatrix();
	glScalef(-1, 1, 1);
	glTranslatef(28, 0, 0);
	Table::drawTable();
	Room::drawFloor();
	glPopMatrix();

	glPushMatrix();
	glScalef(-1, 1, 1);
	glTranslatef(-40, 0, 0);
	Table::drawTable();
	Room::drawFloor();
	glPopMatrix();

	glPushMatrix();
	glScalef(1, 1, -1);
	glTranslatef(0, 0, 36);
	Table::drawTable();
	Room::drawFloor();
	glPopMatrix();

	glPushMatrix();
	glScalef(1, 1, -1);
	glTranslatef(0, 0, -36);
	Table::drawTable();
	Room::drawFloor();
	glPopMatrix();

	glDisable(GL_STENCIL_TEST);
}
