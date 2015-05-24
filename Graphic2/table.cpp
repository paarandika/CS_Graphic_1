#include "table.h"


Table::Table() {
}


Table::~Table() {
}


void Table::drawTable() {
	glColor3f(1.0, 1.0, 1.0);

	Image* image = loadBMP("res/wood.bmp");
	GLuint	_textureId = Texture::loadTexture(image);
	delete image;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBegin(GL_QUADS);

	GLfloat param[4] = { 0.992157, 0.941176, 0.807843, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, param);
	glMaterialf(GL_FRONT, GL_SHININESS, 0);
	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, -0.2f);
	glVertex3f(-6.0f, -0.5f, 9.0f);
	glTexCoord2f(1.0f, -0.2f);
	glVertex3f(6.0f, -0.5f, 9.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(6.0f, 0.0f, 9.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-6.0f, 0.0f, 9.0f);

	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(1.2f, 1.0f);
	glVertex3f(6.0f, -0.5f, -9.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(6.0f, 0.0f, -9.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(6.0f, 0.0f, 9.0f);
	glTexCoord2f(1.2f, 0.0f);
	glVertex3f(6.0f, -0.5f, 9.0f);

	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 1.2f);
	glVertex3f(-6.0f, -0.5f, -9.0f);
	glTexCoord2f(1.0f, 1.2f);
	glVertex3f(6.0f, -0.5f, -9.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(6.0f, 0.0f, -9.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-6.0f, 0.0f, -9.0f);

	//Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(2.2f, 2.2f);
	glVertex3f(-6.0f, -0.5f, -9.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-6.0f, 0.0f, -9.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-6.0f, 0.0f, 9.0f);
	glTexCoord2f(0.0f, 2.2f);
	glVertex3f(-6.0f, -0.5f, 9.0f);

	//Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(6.0f, 0.0f, 9.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-6.0f, 0.0f, 9.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-6.0f, 0.0f, -9.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(6.0f, 0.0f, -9.0f);

	//Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(1.2f, 0.0f);
	glVertex3f(6.0f, -0.5f, 9.0f);
	glTexCoord2f(2.2f, 0.0f);
	glVertex3f(-6.0f, -0.5f, 9.0f);
	glTexCoord2f(2.2f, 1.0f);
	glVertex3f(-6.0f, -0.5f, -9.0f);
	glTexCoord2f(1.2f, 1.0f);
	glVertex3f(6.0f, -0.5f, -9.0f);


	param[0] = 0;
	param[1] = 0;
	param[2] = 0;
	param[3] = 0;
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, param);

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

	Image* image = loadBMP("res/wood2.bmp");
	GLuint	_textureId = Texture::loadTexture(image);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBegin(GL_QUADS);

	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(xOffset + 0.0f, -0.5f, zOffset + 0.0f);
	glTexCoord2f(0.25f, 1.0f);
	glVertex3f(xOffset + 1.0f, -0.5f, zOffset + 0.0f);
	glTexCoord2f(0.25f, 0.0f);
	glVertex3f(xOffset + 1.0f, -6.0f, zOffset + 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(xOffset + 0.0f, -6.0f, zOffset + 0.0f);

	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.75f, 1.0f);
	glVertex3f(xOffset + 0.0f, -0.5f, zOffset + -1.0f);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(xOffset + 1.0f, -0.5f, zOffset + -1.0f);
	glTexCoord2f(0.5f, 0.0f);
	glVertex3f(xOffset + 1.0f, -6.0f, zOffset + -1.0f);
	glTexCoord2f(0.75f, 0.0f);
	glVertex3f(xOffset + 0.0f, -6.0f, zOffset + -1.0f);

	//Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(xOffset + 0.0f, -0.5f, zOffset + 0.0f);
	glTexCoord2f(0.75f, 1.0f);
	glVertex3f(xOffset + 0.0f, -0.5f, zOffset + -1.0f);
	glTexCoord2f(0.75f, 0.0f);
	glVertex3f(xOffset + 0.0f, -6.0f, zOffset + -1.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(xOffset + 0.0f, -6.0f, zOffset + 0.0f);

	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(xOffset + 1.0f, -0.5f, zOffset + 0.0f);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(xOffset + 1.0f, -0.5f, zOffset + -1.0f);
	glTexCoord2f(0.5f, 0.0f);
	glVertex3f(xOffset + 1.0f, -6.0f, zOffset + -1.0f);
	glTexCoord2f(0.25f, 0.0f);
	glVertex3f(xOffset + 1.0f, -6.0f, zOffset + 0.0f);

	//Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(xOffset + 0.0f, -6.0f, zOffset + -1.0f);
	glVertex3f(xOffset + 0.0f, -6.0f, zOffset + 0.0f);
	glVertex3f(xOffset + 1.0f, -6.0f, zOffset + 0.0f);
	glVertex3f(xOffset + 1.0f, -6.0f, zOffset + -1.0f);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}