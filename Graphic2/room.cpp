#include "room.h"


Room::Room() {
}


Room::~Room() {
}


void Room::createRoom() {
	glBegin(GL_QUADS);

	//Front
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-14.0f, -6.0f, 18.0f);
	glVertex3f(-14.0f, 12.0f, 18.0f);
	glVertex3f(20.0f, 12.0f, 18.0f);
	glVertex3f(20.0f, -6.0f, 18.0f);

	//Right
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(20.0f, -6.0f, 18.0f);
	glVertex3f(20.0f, 12.0f, 18.0f);
	glVertex3f(20.0f, 12.0f, -18.0f);
	glVertex3f(20.0f, -6.0f, -18.0f);

	//Back
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(20.0f, 12.0f, -18.0f);
	glVertex3f(20.0f, -6.0f, -18.0f);
	glVertex3f(-14.0f, -6.0f, -18.0f);
	glVertex3f(-14.0f, 12.0f, -18.0f);

	//Left
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-14.0f, -6.0f, -18.0f);
	glVertex3f(-14.0f, 12.0f, -18.0f);
	glVertex3f(-14.0f, 12.0f, 18.0f);
	glVertex3f(-14.0f, -6.0f, 18.0f);

	//Top
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(20.0f, 12.0f, -18.0f);
	glVertex3f(-14.0f, 12.0f, -18.0f);
	glVertex3f(-14.0f, 12.0f, 18.0f);
	glVertex3f(20.0f, 12.0f, 18.0f);

	//Bottom
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(20.0f, -6.0f, -18.0f);
	glVertex3f(-14.0f, -6.0f, -18.0f);
	glVertex3f(-14.0f, -6.0f, 18.0f);
	glVertex3f(20.0f, -6.0f, 18.0f);
	glEnd();
}