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
// then it fills a square in the drawing color.

void mydisplay()
{
	//fill the frame buffer with the background color
	glClear(GL_COLOR_BUFFER_BIT);

	//fill a square in the current drawing color
	glBegin(GL_POLYGON);
		glVertex2f(-0.5, -0.5);
		glVertex2f(-0.5, 0.5);
		glVertex2f(0.5, 0.5);
		glVertex2f(0.5, -0.5);
	glEnd();

	//flush the buffer so the square displays
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
	glClearColor (0.0, 0.0, 0.0, 1.0);

	//set the draw/fill color to white
	glColor3f(1.0, 1.0, 1.0);

	//set the "real" world coordinates
	//to a square from -1 to 1 in x and
	//-1 to 1 in y
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}
int main(int argc, char** argv)
{
	//set up a session with the window system
	glutInit(&argc, argv);

	//use a single frame buffer with red, green,
	//and blue color
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

	//set the window size to 500 by 500
	glutInitWindowSize(500,500);

	//the upper left corner will appear
	//at (0,0) on the screen
	glutInitWindowPosition(0,0);

	//When the window appears it has "simple"
	//on the title bar
	glutCreateWindow("simple");

	//register the display callback to be the
	//function mydisplay
	glutDisplayFunc(mydisplay);

	//initialize OpenGL
	init();

	//start the infinite event loop
	glutMainLoop();
}
