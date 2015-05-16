#pragma once
#include <iostream>
#include <stdlib.h>

#include <glut.h>

#include "imageloader.h"
#include "table.h"
#include "room.h"
#include "GlobalSphere.h"
#include "reflection.h"

using namespace std;

int camX = 0, camY = 1, camZ = 2, camLookX = 0, camLookY = 1, camLookZ = 2;

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
	case 27:
		exit(0);
		break;
	case 120:
		cout << camY << endl;
		camX = (camX + 3) % 9;
		camY = (camY + 3) % 9;
		camZ = (camZ + 3) % 9;
		camLookX = (camLookX + 3) % 9;
		camLookY = (camLookY + 3) % 9;
		camLookZ = (camLookZ + 3) % 9;
		glutPostRedisplay();
		break;
	}
}

void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0); //Enable light #0
	//glEnable(GL_LIGHT1); //Enable light #1
	glEnable(GL_NORMALIZE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Set the blend function
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float camPos[] = { 20.0f, 12.0f, -18.0f, -14.0f, 12.0f, 18.0f, 20.0f, -6.0f, 18.0f };
float camLook[] = { 0, 0, 0, 3, 0, 0, 0, 5, 0 };

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluPerspective(70.0f, 800.0f / 600.0f, 1.0f, 10000.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glTranslatef(-4.0f, -1.0f, -28.0f);
	gluLookAt(camPos[camX], camPos[camY], camPos[camZ],
		camLook[camLookX], camLook[camLookY], camLook[camLookZ],
		0.0f, 1.0f, 0.0f);

	GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

	Table::drawTable();
	GlobalSphere::drawGlobalSphere();
	//GlobalSphere::drawStand();
	Reflection::drawReflection();
	Room::createRoom();
	glutSwapBuffers();
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);

	glutCreateWindow("Computer Graphics - Scene 1");
	initRendering();

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutMainLoop();
	return 0;
}





