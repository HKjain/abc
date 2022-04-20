#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

void reshape(int, int);
void timer(int);

float x_shift = 0;
float y_shift = 40;
int ctr = 0;
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
    x_shift += 4;
    if (x_shift > 792)
    {
        x_shift = -245;
        y_shift += 121;
        ctr += 1;
        if (ctr > 1)
        {
            y_shift = 40;
            ctr = 0;
        }
    }
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50, 800, -50, 800);
    glMatrixMode(GL_MODELVIEW);
}

void circle(float xs, float ys, float r)
{
    int radius = r;
    float pi = 2 * 3.142857142857143;
    glBegin(GL_POLYGON);
    for (float theta = 0; theta <= 360; theta += 0.005)
    {
        float x = radius * cos(theta * pi / 360), y = radius * sin(theta * pi / 360);
        glVertex2f(x + xs, y + ys);
    }
    glEnd();
}

void strips(float x, float y)
{
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-7 + x, 40 + y);
    glVertex2f(5 + x, 70 + y);
    glVertex2f(105 + x, 70 + y);
    glVertex2f(93 + x, 40 + y);
    glEnd();
}

void drawCar()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // road
    glColor3f(0, 0, 0);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(-50, -1);
    glVertex2f(800, -1);
    glEnd();

    // road
    glBegin(GL_LINES);
    glVertex2f(-50, 120);
    glVertex2f(800, 120);
    glEnd();

    // road
    glBegin(GL_LINES);
    glVertex2f(-50, 241);
    glVertex2f(800, 241);
    glEnd();

    strips(0, 0);
    strips(300, 0);
    strips(600, 0);

    strips(100, 121);
    strips(400, 121);
    strips(700, 121);

    // smoke pipe
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(x_shift + 8, 25 + y_shift);
    glVertex2f(x_shift + 8, 30 + y_shift);
    glVertex2f(x_shift + 20, 30 + y_shift);
    glVertex2f(x_shift + 20, 25 + y_shift);
    glEnd();

    // headlights
    glColor3f(1, 0.658823529, 0);
    circle(x_shift + 186, 32 + y_shift, 10);

    // rectangle
    glColor3f(0.4, 0.9, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(x_shift + 20, 15 + y_shift);
    glVertex2f(x_shift + 20, 60 + y_shift);
    glVertex2f(x_shift + 190, 60 + y_shift);
    glVertex2f(x_shift + 190, 15 + y_shift);
    glEnd();

    // trapezium
    glColor3f(0.4, 0.9, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(x_shift + 20, 60 + y_shift);
    glVertex2f(x_shift + 45, 100 + y_shift);
    glVertex2f(x_shift + 135, 100 + y_shift);
    glVertex2f(x_shift + 190, 60 + y_shift);
    glEnd();

    // window left
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_POLYGON);
    glVertex2f(x_shift + 47, 63 + y_shift);
    glVertex2f(x_shift + 47, 93 + y_shift);
    glVertex2f(x_shift + 87, 93 + y_shift);
    glVertex2f(x_shift + 87, 63 + y_shift);
    glEnd();

    // window right
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_POLYGON);
    glVertex2f(x_shift + 102, 63 + y_shift);
    glVertex2f(x_shift + 102, 93 + y_shift);
    glVertex2f(x_shift + 135, 93 + y_shift);
    glVertex2f(x_shift + 169, 68 + y_shift);
    glVertex2f(x_shift + 169, 63 + y_shift);
    glEnd();

    glColor3f(0.211764706, 0.270588235, 0.309803922);
    circle(x_shift + 50, 15 + y_shift, 14);
    circle(x_shift + 150, 15 + y_shift, 14);

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 650);
    glutCreateWindow("Car");
    glutDisplayFunc(drawCar);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    init();
    glutMainLoop();
}