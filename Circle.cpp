#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

// Function Name:   mydisplay()
//
// This function serves as the display callback.  When
// the window is displayed for the first time or is
// redisplayed again, this function is called.
//
// It fills the frame buffer with the background color,
// then it draws a multi-colored circle.

void mydisplay()
{
	const float PI=3.14159;

	//fill the frame buffer with the background color
	glClear(GL_COLOR_BUFFER_BIT);

	//fill a circle using a different color for each point
	//You get totally different drawings using the drawing
	//modes GL_POLYGON and GL_TRIANGLE_FAN
	//glBegin(GL_POLYGON);

	//fill a circle using a triangle fan
	glBegin(GL_TRIANGLE_FAN);
		//All triangles fan out starting with this point
		glVertex2f (0.0,0.0);
		for (int i = 0; i <=361; i++)
		{
				glColor3f(float(rand())/float(RAND_MAX),
				                float(rand())/float(RAND_MAX),
				                float(rand())/float(RAND_MAX));
				glVertex2f(2.0*cos(i*PI/180), 2.0*sin(i*PI/180));
		}
	glEnd();

	//flush the buffer so the circle displays
	//immediately
	glFlush();
}

//
// Function Name:  init()
//
// This function initializes several of
// OpenGL's state variables.  Namely it
// sets the background color, the fill
// color, and sets up the "real" world
// coordinate system.

void init()
{
	//set the background color to black
	glClearColor (0.0, 0.0, 0.0, 0.0);

	//set the draw/fill color to white
	glColor3f(1.0, 0.0, 0.0);

	//set the "real" world coordinates
	//to a window from -2.5 to 2.5 in x and
	//-2.5 to 2.5 in y
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D(-2.5,2.5,-2.5,2.5);
}
int main(int argc, char** argv)
{
	//set up a session with the window system
	glutInit(&argc, argv);

	//use a single frame buffer with red, green,
	//and blue color
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);

	//set the window size to 500 by 500
	glutInitWindowSize(500,500);

	//the upper left corner will appear
	//at (0,0) on the screen
	glutInitWindowPosition(0,0);

	//When the window appears it has "simple"
	//on the title bar
	glutCreateWindow("circle");

	//register the display callback to be the
	//function mydisplay
	glutDisplayFunc(mydisplay);

	//initialize OpenGL
	init();

	//start the infinite event loop
	glutMainLoop();
}


