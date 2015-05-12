#include "GlobalSphere.h"


GlobalSphere::GlobalSphere() {
}


GlobalSphere::~GlobalSphere() {
}


void GlobalSphere::drawGlobalSphere() {
	// Draw body (a 20x20 spherical mesh of radius 0.75 at height 0.75)
	//glColor3f(0.5, 0.5, 1.0); // set drawing color 
	glPushMatrix();
	glTranslatef(4.0f, 2.0f, -3.0f);
	glutSolidSphere(1.8, 20, 20);
	glPopMatrix();

	glEnd();


}