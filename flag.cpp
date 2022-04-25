#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

float counter = 600;

vector<vector<pair<float,float>>> points, points2;

void init(void)
{
	glClearColor(1.0,1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
}

void circle(float xs, float ys, float r)
{
	int radius = r;float pi = 2 * 3.142857142857143;
	glColor3f(0.0, 0.0, 0.533333333);
	for (float theta = 0; theta <= 90; theta += 18)
	{
		vector<pair<float,float>> t;
		float x = radius * cos(theta * pi / 360), y = radius * sin(theta * pi / 360);
		t.push_back({x+xs,y+ys});
		t.push_back({-x+xs,-y+ys});
		points.push_back(t);
		t.clear();
		t.push_back({x+xs,-y+ys});
		t.push_back({-x+xs,y+ys});
		points2.push_back(t);
	}
	
	
	for(auto &h:points)
	{
		glBegin(GL_LINES);
		for(auto &k:h)
		{
			glVertex2f(k.first,k.second);
		}
		glEnd();
	}
	for(auto &h:points2)
	{
		glBegin(GL_LINES);
		for(auto &k:h)
		{
			glVertex2f(k.first,k.second);
		}
		glEnd();
	}
}

void circle2(float xs, float ys, float r)
{
	int radius = r;float pi = 2 * 3.142857142857143;
	glColor3f(0.0, 0.0, 0.533333333);
	glBegin(GL_POINTS);
	for (float theta = 0; theta <= 360; theta += 0.005)
	{
		float x = radius * cos(theta * pi / 360), y = radius * sin(theta * pi / 360);
		glVertex2f(x+xs,y+ys);
	}
	glEnd();
	
}

void drawFlag()
{

	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0,-30);
	glVertex2f(0,80);
	glVertex2f(1,80);
	glVertex2f(1,-30);
	glEnd();
	
	
	glColor3f(1.0,0.6,0.2);
	glBegin(GL_POLYGON);
	glVertex2f(1,65);
	glVertex2f(1,75);
	glVertex2f(61,75);
	glVertex2f(61,65);
	glEnd();
	
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(1,55);
	glVertex2f(1,65);
	glVertex2f(61,65);
	glVertex2f(61,55);
	glEnd();
	
	glColor3f(0.070588235,0.533333333,0.02745098);
	glBegin(GL_POLYGON);
	glVertex2f(1,45);
	glVertex2f(1,55);
	glVertex2f(61,55);
	glVertex2f(61,45);
	glEnd();

	// base stand
	glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(-25,-30);
	glVertex2f(26,-30);
	glVertex2f(26,-35);
	glVertex2f(-25,-35);
	glEnd();

	glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(-30,-35);
	glVertex2f(31,-35);
	glVertex2f(31,-45);
	glVertex2f(-30,-45);
	glEnd();
	
	circle(30,60,4);
	circle2(30,60,4);

	
	glFlush();
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(450, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Flag");
	init();
	glutDisplayFunc(drawFlag);
	glutMainLoop();
}
