#include "table.h"


Table::Table() {
}


Table::~Table() {
}


void Table::drawTable() {

	Image* image = loadBMP("res/wood.bmp");
	GLuint	_textureId = Texture::loadTexture(image);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);

	//Bottom
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

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
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(6.0f, 0.5f, 9.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-6.0f, 0.5f, 9.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-6.0f, 0.5f, -9.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(6.0f, 0.5f, -9.0f);

	//Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(6.0f, -0.5f, 9.0f);
	glVertex3f(-6.0f, -0.5f, 9.0f);
	glVertex3f(-6.0f, -0.5f, -9.0f);
	glVertex3f(6.0f, -0.5f, -9.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
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