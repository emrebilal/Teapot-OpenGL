#include <windows.h>
#include <cstdlib>
#include <iostream> // C++ I/O
#include <cstdio> // C I/O (for sprintf)
#include <cmath> // standard definitions
#include <GL/glut.h> // GLUT
#include <GL/glu.h> // GLU
#include <GL/gl.h> // OpenGL
#include <math.h>

GLfloat xRotated, yRotated, zRotated, x2Rotated, y2Rotated, z2Rotated, xdiff = 0.0f, ydiff = 0.0f;
GLfloat r = 1.0, g = 0.0, b = 0.0; //initial values for color
GLdouble size = 0.8; //size teapot
bool mouse_clicked = false;

void initFunc()
{
	//light properties
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; //specular light value
	GLfloat mat_shininess[] = { 50.0 }; //A low shininess values will result to a spread highlight, a high shininess will result to a concentrated highlight
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 }; //light position value

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); //specular color of material
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess); //specular exponent
	glLightfv(GL_LIGHT0, GL_POSITION, light_position); //light position

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void display_1(void)
{
	GLfloat color[] = { 1.0, 0.0, 0.0, 1.0 }; //Red Teapot
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color); //diffuse color of material

	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clears buffers to preset values
	glMatrixMode(GL_MODELVIEW); //defines how your objects are transformed
	// clear the drawing buffer.
	glClear(GL_COLOR_BUFFER_BIT);
	// clear the identity matrix.
	glLoadIdentity();
	// traslate
	glTranslatef(0.0, 0.0, 0.0);
	// Red color used to draw.
	glColor3f(0.9, 0.3, 0.2);
	// changing in transformation matrix.
	// rotation about X axis
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	// rotation about Y axis
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	// rotation about Z axis
	glRotatef(zRotated, 0.0, 0.0, 1.0);
	// scaling transfomation 
	glScalef(1.0, 1.0, 1.0);
	// built-in (glut library) function , draw you a teapot
	glutSolidTeapot(size);
	// Flush buffers to screen

	glFlush();
	// sawp buffers called because we are using double buffering 
   // glutSwapBuffers();
}

void display_2(void)
{
	GLfloat color[] = { r, g, b, 1.0 }; //inital value up there (changeable)
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color); //diffuse color of material

	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); //defines how your objects are transformed
	// clear the drawing buffer.
	glClear(GL_COLOR_BUFFER_BIT);
	// clear the identity matrix.
	glLoadIdentity();
	// traslate
	glTranslatef(0.0, 0.0, 0.0);
	// Red color used to draw.
	glColor3f(0.9, 0.3, 0.2);
	// changing in transformation matrix.
	// rotation about X axis
	glRotatef(x2Rotated, 1.0, 0.0, 0.0);
	// rotation about Y axis
	glRotatef(y2Rotated, 0.0, 1.0, 0.0);
	// rotation about Z axis
	glRotatef(z2Rotated, 0.0, 0.0, 1.0);
	// scaling transfomation 
	glScalef(1.0, 1.0, 1.0);
	// built-in (glut library) function , draw you a teapot
	glutSolidTeapot(size);
	// Flush buffers to screen

	glFlush();
	// sawp buffers called because we are using double buffering 
   // glutSwapBuffers();
}

void myReshape(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION); //defines the properties of the camera that views the objects in the world coordinate frame
	glLoadIdentity();

	glOrtho(-1.5, 1.5, -1.5*(GLfloat)480 / (GLfloat)640,
		1.5*(GLfloat)480 / (GLfloat)640, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW); //defines how your objects are transformed
	//glViewport(0,0,w,h);  //Use the whole window for rendering
	glLoadIdentity();
}
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) //left button action
	{
		mouse_clicked = true;

		xdiff = x - yRotated;
		ydiff = -y + xRotated;
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) //right button action
	{
		mouse_clicked = true;

		xdiff = x - yRotated;
		ydiff = -y + xRotated;
	}
	else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) //middle button action
	{
		mouse_clicked = true;

		xdiff = x - yRotated;
		ydiff = -y + xRotated;
	}
	else
		mouse_clicked = false;
}

void mouseMotion(int x, int y)
{
	if (mouse_clicked)
	{
		yRotated = x - xdiff;
		xRotated = y + ydiff;

		glutPostRedisplay();
	}
}
void menu(int value) {
	switch (value) {
	case 1: z2Rotated -= 45; //Clockwise rotating z axis
		break;
	case 2: z2Rotated -= 90; //Clockwise rotating z axis
		break;
	case 3: z2Rotated -= 180; //Clockwise rotating z axis
		break;
	case 4: z2Rotated -= 360; //Clockwise rotating z axis
		break;
	case 5: z2Rotated += 45; //Anticlockwise rotating z axis
		break;
	case 6: z2Rotated += 90; //Anticlockwise rotating z axis
		break;
	case 7: z2Rotated += 180; //Anticlockwise rotating z axis
		break;
	case 8: z2Rotated += 360; //Anticlockwise rotating z axis
		break;
	case 9: y2Rotated += 45; //Rotate right y axis
		break;
	case 10: y2Rotated += 90; //Rotate right y axis
		break;
	case 11: y2Rotated += 180; //Rotate right y axis
		break;
	case 12: y2Rotated += 360; //Rotate right y axis
		break;
	case 13: y2Rotated -= 45; //Rotate left y axis
		break;
	case 14: y2Rotated -= 90; //Rotate left y axis
		break;
	case 15: y2Rotated -= 180; //Rotate left y axis
		break;
	case 16: y2Rotated -= 360; //Rotate left y axis
		break;
	case 17: x2Rotated -= 45; //Rotate up x axis
		break;
	case 18: x2Rotated -= 90; //Rotate up x axis
		break;
	case 19: x2Rotated -= 180; //Rotate up x axis
		break;
	case 20: x2Rotated -= 360; //Rotate up x axis
		break;
	case 21: x2Rotated += 45; //Rotate down x axis
		break;
	case 22: x2Rotated += 90; //Rotate down x axis
		break;
	case 23: x2Rotated += 180; //Rotate down x axis
		break;
	case 24: x2Rotated += 360; //Rotate down x axis
		break;
	case 25: r = 1.0, g = 0.0, b = 0.0; //Change color red
		break;
	case 26: r = 0.0, g = 1.0, b = 0.0; //Change color green
		break;
	case 27: r = 0.0, g = 0.0, b = 1.0; //Change color blue
		break;
	case 28: r = 1.0, g = 1.0, b = 1.0; //Change color white
		break;
	case 29: r = 0.0, g = 0.0, b = 0.0; //Change color black
		break;
	case 30: exit(0); //exit
	}
	glutPostRedisplay();
}

void menuFunc()
{
	//creating submenus
	int sub1 = glutCreateMenu(menu);
	glutAddMenuEntry("45", 1);
	glutAddMenuEntry("90", 2);
	glutAddMenuEntry("180", 3);
	glutAddMenuEntry("360", 4);
	int sub2 = glutCreateMenu(menu);
	glutAddMenuEntry("45", 5);
	glutAddMenuEntry("90", 6);
	glutAddMenuEntry("180", 7);
	glutAddMenuEntry("360", 8);
	int sub3 = glutCreateMenu(menu);
	glutAddMenuEntry("45", 9);
	glutAddMenuEntry("90", 10);
	glutAddMenuEntry("180", 11);
	glutAddMenuEntry("360", 12);
	int sub4 = glutCreateMenu(menu);
	glutAddMenuEntry("45", 13);
	glutAddMenuEntry("90", 14);
	glutAddMenuEntry("180", 15);
	glutAddMenuEntry("360", 16);
	int sub5 = glutCreateMenu(menu);
	glutAddMenuEntry("45", 17);
	glutAddMenuEntry("90", 18);
	glutAddMenuEntry("180", 19);
	glutAddMenuEntry("360", 20);
	int sub6 = glutCreateMenu(menu);
	glutAddMenuEntry("45", 21);
	glutAddMenuEntry("90", 22);
	glutAddMenuEntry("180", 23);
	glutAddMenuEntry("360", 24);
	int sub7 = glutCreateMenu(menu);
	glutAddMenuEntry("Red", 25);
	glutAddMenuEntry("Green", 26);
	glutAddMenuEntry("Blue", 27);
	glutAddMenuEntry("White", 28);
	glutAddMenuEntry("Black", 29);
	//create main menu
	glutCreateMenu(menu);
	glutAddSubMenu("Clockwise", sub1);
	glutAddSubMenu("Anticlockwise", sub2);
	glutAddSubMenu("Rotate Right", sub3);
	glutAddSubMenu("Rotate Left", sub4);
	glutAddSubMenu("Rotate up", sub5);
	glutAddSubMenu("Rotate down", sub6);
	glutAddSubMenu("Change Color", sub7);

	glutAddMenuEntry("Quit", 30);
	glutAttachMenu(GLUT_RIGHT_BUTTON); //right button activated 
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH); //allows you to control the mode for subsequent OpenGLUT windows
	//GLUT_SINGLE: Single-buffered mode //GLUT_RGBA: Red, green, blue, alpha framebuffer //GLUT_DEPTH: Depth buffering

	//creating windows and defined functions
	glutCreateWindow("TEAPOT-1");
	glutDisplayFunc(display_1);
	glutReshapeFunc(myReshape);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	initFunc();
	glutCreateWindow("TEAPOT-2");
	glutDisplayFunc(display_2);
	glutReshapeFunc(myReshape);
	initFunc();
	menuFunc();
	glutMainLoop();
}