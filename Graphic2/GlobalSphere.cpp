#include "GlobalSphere.h"



GlobalSphere::GlobalSphere() {
}


GlobalSphere::~GlobalSphere() {
}

void GlobalSphere::DrawArc()
{
	
	//glColor3f(0.0, 0.0, 1.0);
	glTranslatef(-3.0f, 3.0f, 3.0f);
	glRotatef(67.0f, -6.0f, 3.0f, 2.0f);/* draw torus with given color    */
	glutSolidTorus(0.2, 0.6, 20, 20);
}


void GlobalSphere::drawStand()
{
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	glTranslatef(-3.0f, 0.0f, 3.0f);
	glRotatef(113.0f, -3.0f, 2.0f, 3.0f);
	gluCylinder(quadratic, 0.9f, 0.3f, 0.6f, 32, 32);
	
	//DrawArc();
	glTranslatef(-2.0f, 1.0f, 2.0f);
	glRotatef(270.0f, -3.0f, 1.0f, -3.0f);
	gluPartialDisk(quadratic, 1.5, 2.0, 20, 4, 0.0, 180.0);/* draw torus with given color    */
	//glutSolidTorus(0.2, 0.6, 20, 20);


}




void GlobalSphere::drawGlobalSphere() {
	// Draw body (a 20x20 spherical mesh of radius 0.75 at height 0.75)
	Image* image = loadBMP("res/world-map.bmp");
	GLuint	_textureId = Texture::loadTexture(image);
	delete image;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	GLUquadric *quad = gluNewQuadric();
	glPushMatrix();
	glTranslatef(-3.0f, 2.5f, 3.0f);
	gluQuadricTexture(quad, 1);
	gluSphere(quad, 1.4,50, 50);
	glPopMatrix();

	glEnd();

	glDisable(GL_TEXTURE_2D);

}