#include "GlobalSphere.h"



GlobalSphere::GlobalSphere() {
}


GlobalSphere::~GlobalSphere() {
}



void GlobalSphere::drawStand()
{
	
	GLUquadricObj *quadratic;
	glPushMatrix();
	//Draw stand - Cone
	glTranslatef(3.0f, 0.0f, -5.86f);
	glColor3f(0.1, 0.1, 0.1);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glutSolidCone(0.7f, 0.8f, 32, 32);
	glPopMatrix();
	
	//DrawArc
	glPushMatrix();
	glTranslatef(3.0f, 2.4f, -5.86f);
	glRotatef(0.0f, 3.0f, 1.0f, 0.0f);
	quadratic = gluNewQuadric();
	gluPartialDisk(quadratic, 1.55, 1.8, 20, 4, 0.0, 190.0);
	glPopMatrix();

	//small cylinder
	glPushMatrix();
	glTranslatef(3.1f, 3.8f, -5.86f);
	glColor3f(0.1, 0.1, 0.1);
	glRotatef(113.0f, -3.0f, 2.0f, 3.0f);
	GLUquadricObj *qobj = gluNewQuadric();
	gluCylinder(qobj, 0.08f, 0.099f, 0.3f, 64, 64);
	glPopMatrix();

	//small cylinder
	glPushMatrix();
	glTranslatef(2.99f, 0.8f, -5.86f);
	glColor3f(0.1, 0.1, 0.1);
	glRotatef(113.0f, -3.0f, 2.0f, 3.0f);
	GLUquadricObj *qobj2 = gluNewQuadric();
	gluCylinder(qobj2, 0.08f, 0.099f, 0.3f, 64, 64);
	glPopMatrix();
}




void GlobalSphere::drawGlobalSphere() {
	//Put the texture to the globe
	Image* image = loadBMP("res/world-map.bmp");
	GLuint	_textureId = Texture::loadTexture(image);
	delete image;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//Draw the sphere
	GLUquadric *quad = gluNewQuadric();
	glPushMatrix();
	glTranslatef(3.0f, 2.5f, -6.0f);
	gluQuadricTexture(quad, 1);
	gluSphere(quad, 1.4,50, 50);
	glPopMatrix();

	glEnd();

	glDisable(GL_TEXTURE_2D);

}
