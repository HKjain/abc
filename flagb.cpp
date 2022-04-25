#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

vector<vector<pair<float,float>>> points, points2;

void init(void)
{
	glClearColor(1.0,1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
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



void draw(GLfloat x0, GLfloat x1, GLfloat x2, GLfloat x3, GLfloat y0, GLfloat y1, GLfloat y2, GLfloat y3, float h )
{
	GLfloat x[4], y[4], yz[4];
	GLdouble xt[200], yt[200], yt2[200];
	
	x[0] = x0;x[1] = x1;x[2] = x2;x[3] = x3;
	y[0] = y0;y[1] = y1; y[2] = y2; y[3] = y3;
	yz[0] = y0-h;yz[1] = y1-h; yz[2] = y2-h; yz[3] = y3-h;
	
	int i=0;
	for(float t=0; t<=1; t+=0.01,i+=1)
	{
		xt[i] = pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
		yt[i] = pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
		yt2[i] = pow(1-t,3)*yz[0]+3*t*pow(1-t,2)*yz[1]+3*pow(t,2)*(1-t)*yz[2]+pow(t,3)*yz[3];
	}

	glBegin(GL_QUAD_STRIP);
	for(int j=0; j<i; j++)
	{	glVertex2d(xt[j],yt[j]);
		glVertex2d(xt[j],yt2[j]);
	}
	glEnd();
	
}

void drawF()
{

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.6,0.2);
	draw(100,200,200,300,450,500,400,450,30);
	glColor3f(1.0,1.0,1.0);
	draw(100,200,200,300,420,470,370,420,30);
	glColor3f(0.070588235,0.533333333,0.02745098);
	draw(100,200,200,300,390,440,340,390,30);
	circle(200,405,10);
	circle2(200,405,10);
	
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(97,460);
	glVertex2f(100,460);
	glVertex2f(100,100);
	glVertex2f(97,100);
	glEnd();
	

	glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(57,100);
	glVertex2f(140,100);
	glVertex2f(140,85);
	glVertex2f(57,85);
	glEnd();


	glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(47,85);
	glVertex2f(150,85);
	glVertex2f(150,65);
	glVertex2f(47,65);
	glEnd();
	
	glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(37,65);
	glVertex2f(160,65);
	glVertex2f(160,40);
	glVertex2f(37,40);
	glEnd();
	
	
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
	glutDisplayFunc(drawF);
	glutMainLoop();
}
