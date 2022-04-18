#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

int axis = 15;
vector<vector<float>> points, temp;
void init(void)
{
	glClearColor(0.0, .0, .0, 0.2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-axis, axis, -axis, axis);
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

void drawCircle(float x, float y, float r)
{	
	float x1=0, y1=r;
	float p = 1-r;
	
	while(x1<y1)
	{

		temp.push_back({x1,y1});
		x1 = x1+1;
		if(p<0)
		{
			p = p+2*x1+1;
		}	
		else
		{
			y1 = y1-1;
			p = p+2*x1+1-2*y1;
		}
	}
	
	int n = temp.size();
	points = temp;
	for(int i=n-1; i>=0; i--)
	{
		points.push_back({temp[i][1],temp[i][0]});
	}
	
	temp = points;
	reverse(temp.begin(), temp.end());
	vector<vector<float>> temp2;
	for(auto &h:temp)
	{
	points.push_back({h[0],-h[1]});
	temp2.push_back({h[0],-h[1]});
	}
	
	reverse(temp2.begin(), temp2.end());
	temp.clear();
	for(auto &h:temp2)
	{
	points.push_back({-h[0],h[1]});
	temp.push_back({-h[0],h[1]});
	}
	
	reverse(temp.begin(),temp.end());
	for(auto &h:temp)
	points.push_back({h[0],-h[1]});
	
	glColor3f(1.0, 0.8, 0);
	glPointSize(5);
	glBegin(GL_POLYGON);
	for(auto &h:points)
	{
		glVertex2f(h[0]+x,h[1]+y);
		cout << h[0] << " " << h[1] << endl;
	}
	glEnd();
	
}

void circle(void)
{
	drawAxis();
	drawCircle(0, 0, 10);
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);glutInitWindowPosition(50, 100);
	glutInitWindowSize(650, 650);
	glutCreateWindow("Mid Point Circle Drawing Algorithm");
	init();
	glutDisplayFunc(circle);
	glutMainLoop();
}
