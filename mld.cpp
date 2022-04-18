#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

void init(void)
{
	glClearColor(0.0, .0, .0, 0.2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-15.0, 15.0, -15.0, 15.0);
}

void drawAxis()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1., 1., 1.);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(-14, 0);
	glVertex2f(14, 0);glVertex2f(0, 14);
	glVertex2f(0, -14);
	glEnd();
}

void drawLine(float x1, float y1, float x2, float y2)
{
	float deltaX = x2 - x1;
	float deltaY = y2 - y1;
	float steps = abs(deltaX) - 1;
	float xp = x1, yp = y1;
	float pk = 2 * deltaY - deltaX;
	glColor3f(1.0, 0.8, 0);
	glLineWidth(2);

	glBegin(GL_LINE_STRIP);
	glVertex2f(xp, yp);
	int i = 0;
	while ((xp != x2 or yp != y2) and (i <= steps))
	{
		float xp1, yp1, pk1;
		if (pk < 0)
		{
			pk1 = pk + 2 * deltaY;
			xp1 = xp + 1;
			yp1 = yp;
		}
		else
		{
			pk1 = pk + 2 * deltaY - 2 * deltaX;
			xp1 = xp + 1;
			yp1 = yp + 1;
		}
		
		i += 1;
		xp = xp1;
		yp = yp1;
		pk = pk1;
		cout << xp << " " << yp << "-" << i << endl;
		glVertex2f(xp, yp);
	}
	glEnd();
}

void lineSegment(void)
{
	drawAxis();
	drawLine(5, 6, 8, 12);
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);glutInitWindowPosition(50, 100);
	glutInitWindowSize(650, 650);
	glutCreateWindow("Mid Point Line Drawing Algorithm");
	init();
	glutDisplayFunc(lineSegment);
	glutMainLoop();
}
