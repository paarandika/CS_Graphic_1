//----------------------------------------------------------------------
//	Best if viewed with tab stops set every 2 columns.
//----------------------------------------------------------------------
//	File: opengl-3D-sample.cpp - Sample 3D OpenGL/GLUT program
//	Origin: Lighthouse3D (heavily modified by Dave Mount)
//
//	This is a sample program that illustrates OpenGL and GLUT. It
//	renders a picture of 36 snowmen. The camera can be moved by dragging
//	the mouse. The camera moves forward by hitting the up-arrow key and
//	back by moving the down-arrow key. Hit ESC, 'q' or 'Q' to exit.
//
//	Warning #1: This program uses the function glutSpecialUpFunc, which
//	may not be available in all GLUT implementations. If your system
//	does not have it, you can comment this line out, but the up arrow
//	processing will not be correct.
//
//	Warning #2: This is a minimalist program. Very little attention has
//	been paid to good programming technique.
//----------------------------------------------------------------------
#include<iostream>
#include <stdlib.h> // standard definitions
#include <math.h> // math definitions
#include <stdio.h> // standard I/O

#include "imageloader.h"
#include "table.h"
#include "room.h"
#include "GlobalSphere.h"
#include "fan.h"
#include "reflection.h"

// include files are in a slightly different location for MacOS
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <glut.h>
#endif

// escape key (for exit)
#define ESC 27

//----------------------------------------------------------------------
// Global variables
//
// The coordinate system is set up so that the (x,y)-coordinate plane
// is the ground, and the z-axis is directed upwards. The y-axis points
// to the north and the x-axis points to the east.
//
// The values (x,y) are the current camera position. The values (lx, ly)
// point in the direction the camera is looking. The variables angle and
// deltaAngle control the camera's angle. The variable deltaMove
// indicates the amount of incremental motion for the camera with each
// redraw cycle. The variables isDragging and xDragStart are used to
// monitor the mouse when it drags (with the left button down).
//----------------------------------------------------------------------

// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f;
// XZ position of the camera
float x = 0.0f, z = 5.0f;
float deltaAngle = 0.0f;
float deltaMove = 0;
// all variables initialized to 1.0, meaning
// the triangle will initially be white
float red = 1.0f, blue = 1.0f, green = 1.0f;

// angle for rotating triangle
float angle = 0.0f;

int camX = 0, camY = 1, camZ = 2, camLookX = 0, camLookY = 1, camLookZ = 2;
float camPos[] = { 20.0f, 12.0f, -18.0f, -14.0f, 12.0f, 18.0f, 20.0f, -6.0f, 18.0f };
float camLook[] = { 0, 0, 0, 3, 0, 0, 0, 5, 0 };

void drawSnowMan()
{
	Table::drawTable();
	Fan::drawFan();
	GlobalSphere::drawGlobalSphere();
	GlobalSphere::drawStand();
	Reflection::drawReflection();
	Room::createRoom();
}

void changeSize(int w, int h)
{

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();
	//gluPerspective(70.0f, 800.0f / 600.0f, 1.0f, 10000.0f);
	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}
void renderScene(void)
{

	// Clear Color and Depth Buffers

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(camPos[camX], camPos[camY], camPos[camZ],
		x + lx, 1.0f, z + lz,
		0.0f, 1.0f, 0.0f);

	GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	// Draw 36 SnowMen
	glPushMatrix();
	drawSnowMan();
	glPopMatrix();

	glutSwapBuffers();
}


void processNormalKeys(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(0);
		break;
	case 120:
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

void processSpecialKeys(int key, int xx, int yy)
{

	float fraction = 0.7f;

	switch (key) {
	case GLUT_KEY_LEFT:
		x -= lx * fraction;
		z -= lz * fraction;
		break;
		
	case GLUT_KEY_RIGHT:
		x += lx * fraction;
		z += lz * fraction;

		break;
		/*
	case GLUT_KEY_UP:
		angle += 0.7f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case GLUT_KEY_DOWN:
		x -= lx * fraction;
		z -= lz * fraction;
		break;
		angle -= 0.7f;
		lx = sin(angle);
		lz = -cos(angle);
		break;*/
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

int main(int argc, char **argv) {

	// init GLUT and create window

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_STENCIL);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Computer Graphics - Scene 1");
	initRendering();

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}