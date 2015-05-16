#include "GlobalSphere.h"


GlobalSphere::GlobalSphere() {
}


GlobalSphere::~GlobalSphere() {
}

void GlobalSphere::drawStand()
{
	/*glBegin(GL_QUADS);

	glNormal3f(-3.0f, 2.0f, 3.0f);
	glVertex3f(-3.0f, 1.0f, 0.0f);
	glVertex3f(-3.2f, 1.0f, 0.0f);
	glVertex3f(-3.4f, 1.0f, 0.0f);
	glVertex3f(-3.0f, 1.0f, 3.0f);

	glEnd();*/

}




void GlobalSphere::drawGlobalSphere() {
	// Draw body (a 20x20 spherical mesh of radius 0.75 at height 0.75)
	Image* image = loadBMP("res/world-map.bmp");
	GLuint	_textureId = Texture::loadTexture(image);
	delete image;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	//glBindTexture(GTexName());L_TEXTURE_2D, m_worldmap.

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	GLUquadric *quad = gluNewQuadric();
	glPushMatrix();
	glTranslatef(-3.0f, 2.0f, 3.0f);
	gluQuadricTexture(quad, 1);
	gluSphere(quad, 1.4,50, 50);
	glPopMatrix();

	glEnd();

	glDisable(GL_TEXTURE_2D);

}