/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include<math.h>
#define degree 2*M_PI/360.0

void drawCube(float BaseX, float BaseY, float BaseZ,float Lenght, float Width, float Height, float r, float g, float b)
{
    glBegin(GL_POLYGON);
        glColor3f(r,g,b);
        glVertex3f(BaseX, BaseY, BaseZ);       // side 1 or down
        glVertex3f(BaseX+Lenght,BaseY,BaseZ);
        glVertex3f(BaseX+Lenght,BaseY+Height, BaseZ);
        glVertex3f(BaseX,BaseY+Height,BaseZ);

        glColor3f(r,g,b);
        glVertex3f(BaseX,BaseY,BaseZ+Width);       // side 2 or top
        glVertex3f(BaseX+Lenght,BaseY,BaseZ+Width);
        glVertex3f(BaseX+Lenght,BaseY+Height,BaseZ+Width);
        glVertex3f(BaseX,BaseY+Height,BaseZ+Width);

        glColor3f(r,g,b);
        glVertex3f(BaseX,BaseY,BaseZ);       // side 3 or front
        glVertex3f(BaseX+Lenght,BaseY,BaseZ);
        glVertex3f(BaseX+Lenght,BaseY,BaseZ+Width);
        glVertex3f(BaseX,BaseY,BaseZ+Width);

        glColor3f(r,g,b);
        glVertex3f(BaseX,BaseY+Height,BaseZ);       // side 4 or Back
        glVertex3f(BaseX,BaseY+Height,BaseZ+Width);
        glVertex3f(BaseX+Lenght,BaseY+Height,BaseZ);
        glVertex3f(BaseX+Lenght,BaseY+Height,BaseZ+Width);

        glColor3f(r,g,b);
        glVertex3f(BaseX+Lenght,BaseY,BaseZ);       // side 5 or right side
        glVertex3f(BaseX+Lenght,BaseY,BaseZ+Width);
        glVertex3f(BaseX+Lenght,BaseY+Height,BaseZ);
        glVertex3f(BaseX+Lenght,BaseY+Height,BaseZ+Width);

        glColor3f(r,g,b);
        glVertex3f(BaseX,BaseY,BaseZ);       // side 6 or Left
        glVertex3f(BaseX,BaseY,BaseZ+Width);
        glVertex3f(BaseX,BaseY+Height,BaseZ);
        glVertex3f(BaseX,BaseY+Height,BaseZ+Width);
    glEnd();
}

void drawChair()
{
    drawCube(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 5.0f, 0.0f,0.0f,1.0f);
    drawCube(4.0f, 0.0f, 0.0f, 1.0f, 1.0f, 5.0f, 0.0f,1.0f,1.0f);
    drawCube(4.0f, 0.0f, 4.0f, 1.0f, 1.0f, 5.0f, 0.0f,1.0f,0.0f);
    drawCube(0.0f, 0.0f, 4.0f, 1.0f, 1.0f, 5.0f, 1.0f,0.0f,0.0f);
    drawCube(0.0f, 5.0f, 0.0f, 5.0f, 5.0f, 1.0f, 0.0f,1.0f,1.0f);
    drawCube(0.0f, 6.0f, 0.0f, 1.0f, 5.0f, 5.0f, 1.0f,0.0f,1.0f);
}

void DrawTable()
{

    drawCube(6.0, 10.0, 3.0, 10.0, 0.5,0.5,0.8560, 0.125, 0.2365 );

    // draw back right leg

    drawCube(6.0, 0.0, 3.0, 0.5, 10.0,10.0,0.0, 1.0, 0.0);

    // draw back left leg

    drawCube(6.0, 0.0, 12.5, 0.5, 10.0,10.0,0.0, 1.0, 0.0);

    // draw front right leg

    drawCube(14.0, 0.0, 3.0, 0.5, 10.0,10.0,0.0, 1.0, 0.0);

    // draw front left leg
    drawCube(14.0, 0.0, 12.5, 0.5, 10.0,10.0,0.0, 1.0, 0.0);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    drawChair();
    DrawTable();
    glFlush();
    glutSwapBuffers();
}

void init()
{
    glClearColor(0,0,0,0);
    glViewport(0,0,50,50);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50,50,-50,50,-50,50);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


int main(int argcp, char ** argv )
{
    glutInit(&argcp,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(50,50);
    glutCreateWindow("My Room");
    glEnable(GL_DEPTH_TEST);
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}
