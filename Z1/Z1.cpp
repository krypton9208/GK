// Z1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h" 
#define _USE_MATH_DEFINES 
#include <cmath > 
#include <GL/freeglut.h>
GLfloat xo = 0.0f, yo = 0.0f, w = 1.0f, h = 1.0f, t = 0.0f;

void render(void) {
	glClearColor(0.2f, 0.2f, 0.4f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 0.0f);
	t = (t > 2.0f*M_PI) ? (0.0f) : (t + 0.1f); 
	glRectf(xo + 0.3f*w*cos(t), yo + 0.3f*h*sin(t), xo + w*cos(t), yo + h*sin(t));
	glFlush();
	glutSwapBuffers();
}


void reshape(int w, int h) {
	GLdouble xo = -1.0f, x1 = 1.0f, yo = -1.0f, y1 = 1.0f, zo = -1.0f, z1 = 1.0f; GLdouble q = (GLdouble)w / h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h) {
		glOrtho(xo, x1, yo / q, y1 / q, zo, z1);
	}
	else { glOrtho(xo*q, x1*q, yo, y1, zo, z1); } glMatrixMode(GL_MODELVIEW);
}
void keyboard(unsigned char key, int x, int y) { switch (key) { case 27: exit(0); break; } return; }


int main(int argc, CHAR* argv[])
{
	void render(void);
	void reshape(int, int);
	void keyboard(unsigned char, int, int);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Okno renderowania OpenGL");
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutIdleFunc(render);
	glutDisplayFunc(render);
	glutFullScreen();
	glutMainLoop();
	return 0;
}

