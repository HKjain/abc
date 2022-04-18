#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

float counter = 600;

void init(void)
{
	glClearColor(1.0,1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-50, 800, -50, 800);
}

void circle(float xs, float ys, float r)
{
	int radius = r;float pi = 2 * 3.142857142857143;
	glColor3f(0.211764706, 0.270588235, 0.309803922);
	glBegin(GL_POLYGON);
	for (float theta = 0; theta <= 360; theta += 0.005)
	{
		float x = radius * cos(theta * pi / 360), y = radius * sin(theta * pi / 360);
		glVertex2f(x+xs, y+ys);
	}
	glEnd();
}

void drawCar()
{

	glClear(GL_COLOR_BUFFER_BIT);
	
	// rectangle
	glColor3f(0.2,0.9,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(20,15);
	glVertex2f(20,60);
	glVertex2f(190,60);
	glVertex2f(190,15);
	glEnd();
	
	// smoke pipe
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(8,25);
	glVertex2f(8,30);
	glVertex2f(20,30);
	glVertex2f(20,25);
	glEnd();
	
	// headlights
	glColor3f(1,0.658823529,0);
	glBegin(GL_POLYGON);
	glVertex2f(190,20);
	glVertex2f(190,42);
	glVertex2f(195,42);
	glVertex2f(195,20);
	glEnd();
	
	// trapezium
	glColor3f(0.2,0.9,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(20,60);
	glVertex2f(45,100);
	glVertex2f(135,100);
	glVertex2f(190,60);
	glEnd();
	
	// window left
	glColor3f(0.658823529, 0.658823529, 0.658823529);
	glBegin(GL_POLYGON);
	glVertex2f(47,63);
	glVertex2f(47,93);
	glVertex2f(87,93);
	glVertex2f(87,63);
	glEnd();
	
	//window right
	glColor3f(0.658823529, 0.658823529, 0.658823529);
	glBegin(GL_POLYGON);
	glVertex2f(102,63);
	glVertex2f(102,93);
	glVertex2f(135,93);
	glVertex2f(169,68);
	glVertex2f(169,63);
	glEnd();
	
	circle(50,15,14);
	circle(150,15,14);
	
	glFlush();
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);glutInitWindowPosition(50, 100);
	glutInitWindowSize(1300, 1300);
	glutCreateWindow("Car");
	init();
	glutDisplayFunc(drawCar);
	glutMainLoop();
}
