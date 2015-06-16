#include "room.h"


Room::Room() {
}


Room::~Room() {
}


void Room::createRoom() {
	drawFloor();
	glPushMatrix();
	glColor4f(0.3281, 0.7109, 0.9726, 0.4);
	glBegin(GL_QUADS);
	glDisable(GL_COLOR_MATERIAL);
	GLfloat param[4] = { 1, 1, 1, 1.0 };
	GLfloat materialColor[] = { 0.3281, 0.7109, 0.9726, 0.7};

	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialColor);
	glMaterialfv(GL_FRONT, GL_SPECULAR, param);
	glMaterialf(GL_FRONT, GL_SHININESS, 100);

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

	param[0] = 0;
	param[1] = 0;
	param[2] = 0;
	param[3] = 0;
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, param);
	glEnable(GL_COLOR_MATERIAL);
	glEnd();
	glPopMatrix();
	glMaterialf(GL_FRONT, GL_SHININESS, 0);
}
void Room::drawFloor() {
	Image* image = loadBMP("res/floor.bmp");
	GLuint	_textureId = Texture::loadTexture(image);
	delete image;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBegin(GL_QUADS);

	//Bottom
	glColor4f(1.0, 1.0, 1.0, 1);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(20.0f, -6.0f, -18.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-14.0f, -6.0f, -18.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-14.0f, -6.0f, 18.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(20.0f, -6.0f, 18.0f);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}