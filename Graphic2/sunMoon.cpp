#include "sunMoon.h"
#define PI 3.14159265

SunMoon::SunMoon() {
}


SunMoon::~SunMoon() {
}


void SunMoon::sunMoon(int roatation) {

	int y = round(25 * sin(roatation*PI / 180));
	int x = round(25 * cos(roatation*PI / 180));
	GLfloat sunPos[] = { -1*x, -1*y-6.0, -18.0, 1.0 };
	GLfloat moonPos[] = { x, y-6.0, -18.0, 1.0 };
	GLfloat sunColor[] = { 1.8f, 1.8f, 1.8f, 1.0f };
	GLfloat moonColor[] = { 0.3f, 0.3f, 0.2f, 1.0f };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, sunColor);
	glLightfv(GL_LIGHT1, GL_POSITION, sunPos);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, moonColor);
	glLightfv(GL_LIGHT2, GL_POSITION, moonPos);
	
}