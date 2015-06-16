#include "fan.h"

Fan::Fan() {
}


Fan::~Fan() {
}

static GLfloat spin = 0.0;
GLUquadricObj *qobj;
//GLfloat lngh ; GLfloat width ; GLfloat depth ;
float lngh; float width; float depth;
int i;
double angle = 0;
void box(float lngh, float width, float depth);
//void Fan_Physics();



void Fan::Fan_physics(int n)
{
	angle = angle + 1;
	if (angle >= 360){
		angle = 0;
	}
	glutPostRedisplay();
	glutTimerFunc(5, Fan::Fan_physics, 5);
}

void Fan::drawFan()
{
	glPushMatrix();
	/* Fan*/
	glTranslatef(-2.0f, 0.0f, 3.0f);//Fan position
	glRotatef(140.0f, 0.0f, 1.0f, 0.0f);//Rotate fan
	glPushMatrix();
	//**********************************************

	// Fan Base:
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricDrawStyle(qobj, GLU_FILL); /* smooth shaded */
	gluQuadricNormals(qobj, GLU_SMOOTH);
	glScalef(4, 0.5, 4);
	glEnable(GL_NORMALIZE);
	//Sphere with radius 0.25 then scaled
	gluSphere(qobj, 0.4, 20, 20);
	glPopMatrix();
	// Fan stand:  
	glPushMatrix();
	gluQuadricDrawStyle(qobj, GLU_FILL); /* flat shaded */
	gluQuadricNormals(qobj, GLU_FLAT);
	glRotatef(-90, 1.0, 0.0, 0.0);
	gluCylinder(qobj, 0.125, 0.125, 4.5, 16, 10);

	glPopMatrix();
	// Fan Motor:
	glPushMatrix();
	gluQuadricDrawStyle(qobj, GLU_FILL); /* smooth shaded */
	gluQuadricNormals(qobj, GLU_SMOOTH);
	glTranslatef(0.0, 4.5, 0.0);
	glScalef(0.5, 0.5, 1);
	glEnable(GL_NORMALIZE);
	gluSphere(qobj, 1, 20, 20);
	glPopMatrix();
	//casing back

	glTranslatef(0.0, 4.5, 0.3);
	glRotatef(spin, 0.0, 0.0, 1.0);
	for (i = 1; i <= 360; i = i + 20)

	{
		glPushMatrix();
		glRotatef(i, 0.0, 0.0, 1.0);
		glTranslatef(0.5, 0.0, 0.0);
		glRotatef(-45, 1.0, 0.0, 0.0);
		glShadeModel(GL_FLAT);
		glPushMatrix();
		box(2.0, 0.02, 0.01);
		//glEnable(GL_LIGHTING);
		glPopMatrix();
		glPopMatrix();

	}
	//Outer Casing
	glPushMatrix();
	gluCylinder(qobj, 2.5f, 2.6f, 0.4f, 64, 64);
	glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -0.8f);
	gluCylinder(qobj, 2.5f, 2.6f, 0.4f, 64, 64);


	glPopMatrix();



	//**********************************************
	// Fan Blades:
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.5);
	glRotatef(angle, 0.0, 0.0, 1.0);
	for (i = 1; i <= 360; i = i + 60)

	{
		glPushMatrix();
		glRotatef(i, 0.0, 0.0, 1.0);
		glTranslatef(1.5, 0.0, 0.0);
		glRotatef(-45, 1.0, 0.0, 0.0);
		glShadeModel(GL_FLAT);
		glPushMatrix();
		
		box(0.8, 0.3, 0.08);
		//glEnable(GL_LIGHTING);
		glPopMatrix();
		glPopMatrix();

	}
	glPopMatrix();
	//casing front

	glTranslatef(0.0, 0.0, 0.3);
	glRotatef(0.0, 0.0, 0.0, 1.0);

	for (i = 1; i <= 360; i = i + 20)

	{
		glPushMatrix();
		glRotatef(i, 0.0, 0.0, 1.0);
		glTranslatef(0.5, 0.0, 0.0);
		glRotatef(-45, 1.0, 0.0, 0.0);
		glShadeModel(GL_FLAT);
		glPushMatrix();
		box(2.0, 0.02, 0.01);
		glPopMatrix();
		glPopMatrix();

	}
	glPopMatrix();

}




void box(float lngh, float width, float depth)
{
	float a = lngh; float b = width; float c = depth;


	glBegin(GL_QUADS);

	/* Top face of box*/
	glVertex3f(a, b, -c);     // Top right vertex (Top of cube)
	glVertex3f(-a, b, -c);    //Top left vertex (Top of cube)
	glVertex3f(-a, b, c);     // Bottom left vertex (Top of cube)
	glVertex3f(a, b, c);      // Bottom right vertex (Top of cube)

	// Bottom face of box

	glVertex3f(a, -b, -c);     // Top right vertex (Bottom of cube)
	glVertex3f(-a, -b, -c);    // Top left vertex (Bottom of cube)
	glVertex3f(-a, -b, c);   // Bottom left vertex (Bottom of cube)
	glVertex3f(a, -b, c);   // Bottom right vertex (Bottom of cube)

	// Front of box

	glVertex3f(a, b, c);      // Top right vertex (Front)
	glVertex3f(-a, b, c);     // Top left vertex (Front)
	glVertex3f(-a, -b, c);    // Bottom left vertex (Front)
	glVertex3f(a, -b, c);     // Bottom right vertex (Front)

	// Back of box

	glVertex3f(a, -b, -c);    // Bottom right vertex (Back)
	glVertex3f(-a, -b, -c);   // Bottom left vertex (Back)
	glVertex3f(-a, b, -c);    // top left vertex (Back)
	glVertex3f(a, b, -c);     // Top right vertex (Back)

	// Left of box

	glVertex3f(-a, b, c);     // Top right vertex (Left)
	glVertex3f(-a, b, -c);    // Top left vertex (Left)
	glVertex3f(-a, -b, -c);   // Bottom left vertex (Left)
	glVertex3f(-a, -b, c);    // Bottom vertex (Left)

	// Right of box

	glVertex3f(a, b, -c);     // Top right vertex (Right)
	glVertex3f(a, b, c);      // Top left vertex (Right)
	glVertex3f(a, -b, c);     // Bottom left vertex (Right)
	glVertex3f(a, -b, -c);    // Bottom right vertex (Right)

	// End drawing the box
	glEnd();
	//return TRUE;

}