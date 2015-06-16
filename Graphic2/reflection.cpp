#include "reflection.h"


Reflection::Reflection() {
}


Reflection::~Reflection() {
}

void Reflection::drawReflection() {
	glEnable(GL_STENCIL_TEST);
	glColorMask(0, 0, 0, 0);
	glDisable(GL_DEPTH_TEST);
	glStencilFunc(GL_ALWAYS, 1, 1);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	Room::createRoom();

	glColorMask(1, 1, 1, 1);
	glEnable(GL_DEPTH_TEST);
	glStencilFunc(GL_EQUAL, 1, 1);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

	glPushMatrix();
	glScalef(-1, 1, 1);
	glTranslatef(28, 0, 0);
	Table::drawTable();
	Room::drawFloor();
	Fan::drawFan();
	GlobalSphere::drawGlobalSphere();
	GlobalSphere::drawStand();
	glPopMatrix();

	glPushMatrix();
	glScalef(-1, 1, 1);
	glTranslatef(-40, 0, 0);
	Table::drawTable();
	Room::drawFloor();
	Fan::drawFan();
	GlobalSphere::drawGlobalSphere();
	GlobalSphere::drawStand();
	glPopMatrix();

	glPushMatrix();
	glScalef(1, 1, -1);
	glTranslatef(0, 0, 36);
	Table::drawTable();
	Room::drawFloor();
	Fan::drawFan();
	GlobalSphere::drawGlobalSphere();
	GlobalSphere::drawStand();
	glPopMatrix();

	glPushMatrix();
	glScalef(1, 1, -1);
	glTranslatef(0, 0, -36);
	Table::drawTable();
	Room::drawFloor();
	Fan::drawFan();
	GlobalSphere::drawGlobalSphere();
	GlobalSphere::drawStand();
	glPopMatrix();

	glDisable(GL_STENCIL_TEST);
}
