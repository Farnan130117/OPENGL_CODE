

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include<math.h>
#define degree 2*M_PI/360.0

void specialKeys(int, int, int);

//Global Variables
double rotate_y = 0;
double rotate_x = 0;
double rotate_z = 0;

void drawCube(float BaseX, float BaseY, float BaseZ,float Lenght, float Width, float Height, float r, float g, float b)
{
    glBegin(GL_POLYGON);// Begin drawing
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




void DrawTable()
{

    drawCube(0.0, 0.0, 0.0, 2.0,2.0,11.0,0.5560, 0.125, 0.2365 );
    drawCube(0.0, 0.0, -8.0, 2.0,2.0,11.0,0.5560, 0.125, 0.2365 );
    drawCube(10.0, 0.0, 0.0, 2.0,2.0,11.0,0.5560, 0.125, 0.2365 );
    drawCube(10.0, 0.0, -8.0, 2.0,2.0,11.0,0.5560, 0.125, 0.2365 );
    drawCube(-2.0, 11.0, -10.0, 17.0,13.0,2.0,0.5560, 0.125, 0.2365 );


}
void    Drawwall()
{
    drawCube(-13.0, 0.0, -50.0, 50.0,2.0,40.0,.5, .5, 3 );
    drawCube(-13.0, -0.5, -50.0, 50.0,100.0,1.0,0.1, 2, 2 );
    drawCube(-13.0, 0.0, -50.0, 1.0,100.0,40.0,0.2, 2, 2 );

}

void DrawChair()
{


    drawCube(22.0, 0.0, -2.0, 1.0,1.0,15.0,1, 0.5, 0.2365 );
    drawCube(22.0, 0.0, -8.0, 1.0,1.0,15.0,1, 0.5, 0.2365 );
    drawCube(16.0, 0.0, -2.0, 1.0,1.0,8.0,1, 0.5, 0.2365 );
    drawCube(16.0, 0.0, -8.0, 1.0,1.0,8.0,1, 0.5, 0.2365 );
    drawCube(15.0, 7.0, -8.0, 8.0,8.0,1.0,1, 0.5, 0.2365 );



}
void DrawCircle(float cx, float cy, float r, int num_segments)
{
	float theta = 2 * 3.1415926 / float(num_segments);
	float tangetial_factor = tanf(theta);//calculate the tangential factor

	float radial_factor = cosf(theta);//calculate the radial factor

	float x = r;//we start at angle = 0

	float y = 0;

	glBegin(GL_LINE_LOOP);
	for(int ii = 0; ii < num_segments; ii++)
	{
		glVertex2f(x + cx, y + cy);//output vertex

		//calculate the tangential vector
		//remember, the radial vector is (x, y)
		//to get the tangential vector we flip those coordinates and negate one of them

		float tx = -y;
		float ty = x;

		//add the tangential vector

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;

		//correct using the radial factor

		x *= radial_factor;
		y *= radial_factor;
	}
	glEnd();
}


void display()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);// Clear color and depth buffers

   // glRotatef(30, 1.0, 0.0, 0.0);
   // glRotatef(.001, 0.0, -1.0, 0.0);
   // glRotatef(40, 0.0, 1.0, 0.0);


    DrawTable();
    Drawwall();
    DrawChair();
   // DrawCircle(15,20,5,5);
    glFlush();
    glutSwapBuffers();
}
void displayTable()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);// Clear color and depth buffers

    DrawTable();
   // Drawwall();
    glFlush();
    glutSwapBuffers();
}

void displayChair()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);// Clear color and depth buffers

    DrawChair();
   // Drawwall();
    glFlush();
    glutSwapBuffers();
}


void objControl(unsigned char key, int x, int y)
{


    glutIdleFunc(displayChair);
   // glutIdleFunc(displayTable);

    switch(key)
    {
    case 2:
        exit(0);
        break;

    case '.':
        glScalef(2.0f, 2.0f, 2.0f);
        break;
    case ',':
        glScalef(0.75f, 0.75f, 0.75f);
        break;
    case 'm':
        glLoadIdentity();
        break;
    case 'j':
        glRotatef(-30*degree, 0, 1, 0);
        break;
    case 'g':
        glRotatef(30*degree, 0, 1, 0);
        break;
    case 't':

        glTranslatef(0.01, 0.0, 0.0); // Move right and into the screen

        break;
    }
}

void nKeys(unsigned char key, int x, int y)
{
    switch(key)
    {

    case 2:
        exit(0);
        break;
    case 'd':
        glRotatef(30*degree, 1, 0, 0);
        break;
    case 'a':
        glRotatef(-30*degree, 1, 0, 0);
        break;
    case 'w':
        glRotatef(30*degree, 0, 1, 0);
        break;
    case 's':
        glRotatef(-30*degree, 0, 1, 0);
        break;
    case 'x':
        glRotatef(30*degree, 0, 0, 1);
        break;
    case 'z':
        glRotatef(-30*degree, 0, 0, 1);
        break;
    case '+':
        glScalef(2.0f, 2.0f, 2.0f);
        break;
    case '-':
        glScalef(0.75f, 0.75f, 0.75f);
        break;
    case 'l':
        glLoadIdentity();
        break;

    case '1':
        glutKeyboardFunc(objControl);
        break;


    }
}

void init()
{
    glClearColor(0,0,0,0);// Set background color to black
    glViewport(0,0,50,50); // Set the viewport to cover the new window
    glMatrixMode(GL_PROJECTION);// To operate on the Projection matrix
    glLoadIdentity(); // Reset the model-view matrix
    glOrtho(-50,50,-50,50,-50,500); // Set up orthographic projection view
    glMatrixMode(GL_MODELVIEW); // To operate on model-view matrix
    glLoadIdentity(); // Reset the model-view matrix
}





int main(int argcp, char ** argv )
{
    glutInit(&argcp,argv);// Initialize GLUT
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(600,600); // Set the window's initial width & height
    glutInitWindowPosition(50,50);// Position the window's initial top-left corner
    glutCreateWindow("My Room");// Create window with the given title
    glEnable(GL_DEPTH_TEST);// Enable depth testing for z-culling
    init();// Our own OpenGL initialization

    glutDisplayFunc(display);// Register callback handler for window re-paint event

    glutIdleFunc(display);
   // glutDisplayFunc(displayTable);
    //glutIdleFunc(displayTable);






    //glutKeyboardFunc(objControl);
    glutKeyboardFunc(nKeys);
    glutMainLoop();// Enter the infinite event-processing loop
    return EXIT_SUCCESS;
}
