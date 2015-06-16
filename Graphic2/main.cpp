#pragma once
#include <iostream>
#include <stdlib.h>

#include <glut.h>

#include "imageloader.h"
#include "table.h"
#include "room.h"
#include "GlobalSphere.h"
#include "fan.h"
#include "reflection.h"

using namespace std;

int camX = 0, camY = 1, camZ = 2, camLookX = 0, camLookY = 1, camLookZ = 2, rotatex=0, rotatey=0;

float camPos[] = { -14.0f, 12.0f, 18.0f, 20.0f, 12.0f, -18.0f, 20.0f, -6.0f, 18.0f };
float camLook[] = {  3, 0, 0, 0, 0, 0,0, 5, 0 };
float camPosRef[] = { -14.0f, 12.0f, 18.0f, 20.0f, 12.0f, -18.0f, 20.0f, -6.0f, 18.0f };
float camLookRef[] = { 3, 0, 0, 0, 0, 0, 0, 5, 0 };

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
	case 27:
		exit(0);
		break;
	case 'x':
	case 'X':
		camPos[camX] = camPosRef[camX];
		camPos[camY] = camPosRef[camY];
		camPos[camZ] = camPosRef[camZ];
		camLook[camLookX] = camLookRef[camLookX];
		camLook[camLookY] = camLookRef[camLookY];
		camLook[camLookZ] = camLookRef[camLookZ];
		rotatex = 0;
		rotatey = 0;
		camX = (camX + 3) % 9;
		camY = (camY + 3) % 9;
		camZ = (camZ + 3) % 9;
		camLookX = (camLookX + 3) % 9;
		camLookY = (camLookY + 3) % 9;
		camLookZ = (camLookZ + 3) % 9;
		glutPostRedisplay();
		break;
	case 'w':
	case 'W':
		camPos[camX] += 0.5;
		camLook[camLookX] += 0.5;
		glutPostRedisplay();
		break;

	case 's':
	case 'S':
		camPos[camX] -= 0.5;
		camLook[camLookX] -= 0.5;
		glutPostRedisplay();
		break;

	case 'a':
	case 'A':
		camPos[camZ] += 0.5;
		camLook[camLookZ] += 0.5;
		glutPostRedisplay();
		break;

	case 'd':
	case 'D':
		camPos[camZ] -= 0.5;
		camLook[camLookZ] -= 0.5;
		glutPostRedisplay();
		break;

	case 'q':
	case 'Q':
		camPos[camY] += 0.5;
		camLook[camLookY] += 0.5;
		glutPostRedisplay();
		break;

	case 'e':
	case 'E':
		camPos[camY] -= 0.5;
		camLook[camLookY] -= 0.5;
		glutPostRedisplay();
		break;

	}
}

void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 0.7f;

	switch (key) {
	case GLUT_KEY_LEFT:
		rotatey -= 5;
		glutPostRedisplay();
		break;

	case GLUT_KEY_RIGHT:
		rotatey += 5;
		glutPostRedisplay();
		break;
		
	case GLUT_KEY_UP:
		rotatex += 5;
		glutPostRedisplay();
		break;

	case GLUT_KEY_DOWN:
		rotatex -= 5;
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

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluPerspective(70.0f, 800.0f / 600.0f, 1.0f, 10000.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glTranslatef(-4.0f, -1.0f, -28.0f);
	gluLookAt(camPos[camX], camPos[camY], camPos[camZ],
		camLook[camLookX], camLook[camLookY], camLook[camLookZ],
		0.0f, 1.0f, 0.0f);
	glRotatef(rotatex, 1, 0, 0);
	glRotatef(rotatey, 0, 1, 0);
	GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	Table::drawTable();
	Fan::drawFan();
	GlobalSphere::drawGlobalSphere();
	GlobalSphere::drawStand();
	Reflection::drawReflection();
	Room::createRoom();
	glutSwapBuffers();
	
}


int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_STENCIL);
	glutInitWindowSize(800, 600);

	glutCreateWindow("Computer Graphics - Scene 1");
	initRendering();
	glutDisplayFunc(drawScene);
	glutTimerFunc(5,Fan::Fan_physics,5);
	//glutIdleFunc(Fan::Fan_physics);
	glutKeyboardFunc(handleKeypress);
	glutSpecialFunc(processSpecialKeys);
	glutReshapeFunc(handleResize);

	glutMainLoop();
	return 0;
}





