#include<stdio.h>
#include<stdarg.h>
#include<math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif // __APPLE__

// Functions Prototypes
void display();
void specialKeys(int, int, int);

//Global Variables
double rotate_y = 0;
double rotate_x = 0;

// display() callback function
void display(){
    //clear screen and Z buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //reset Transformations
  //  glTranslatef(0.1, 0.0, 0.0); // not included
    //glRotatef(180, 0.0, 1.0, 0.0); // not included
    //Rotate when user changes rotate_x and rotate_y
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    //other Transformations
  //  glScalef(2.0, 2.0, 0.0); // not included

    //Multi-colored side - FRONT
    glBegin(GL_POLYGON);
        glColor3f(10.0, 10.0 , -10.0);
        glVertex3f(0.5, -0.5, -0.5);
       // glColor3f(1.0, 1.0, 1.0);
        glVertex3f(0.5, 0.5, -0.5);
       // glColor3f(1.0, 1.0, 1.0);
        glVertex3f(-0.5, 0.5, -0.5);
        //glColor3f(1.0, 1.0, 1.0);
        glVertex3f(-0.5, -0.5, -0.5);
    glEnd();

    //white-side BACK
    glBegin(GL_POLYGON);
        glColor3f(5.0, 5.0 , 5.0);
        glVertex3f(0.5, -0.5, 0.5);
        glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(-0.5, 0.5, 0.5);
        glVertex3f(-0.5, -0.5, 0.5);
    glEnd();

    //Purple side - Right
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0 , 1.0);
        glVertex3f(0.5, -0.5, -0.5);
        glVertex3f(0.5, 0.5, -0.5);
        glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(0.5, -0.5, 0.5);
    glEnd();

    //Green side LEFT
    glBegin(GL_POLYGON);
        glColor3f(0.0, 1.0 , 0.0);
        glVertex3f(-0.5, -0.5, 0.5);
        glVertex3f(-0.5, 0.5, 0.5);
        glVertex3f(-0.5, 0.5, -0.5);
        glVertex3f(-0.5, -0.5, -0.5);
    glEnd();

    //Blue Side TOP
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0 , 1.0);
        glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(0.5, 0.5, -0.5);
        glVertex3f(-0.5, 0.5, -0.5);
        glVertex3f(-0.5, 0.5, 0.5);
    glEnd();

    //Red side BOTTOM
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0 , 0.0);
        glVertex3f(0.5, -0.5, -0.5);
        glVertex3f(0.5, -0.5, 0.5);
        glVertex3f(-0.5, -0.5, 0.5);
        glVertex3f(-0.5, -0.5, -0.5);
    glEnd();

    glFlush();
    glutSwapBuffers();
}

// specialKeys CALLBACK function
void specialKeys(int key, int x, int y){
    // right arrow increases rotation by 5 degrees
    if(key == GLUT_KEY_RIGHT)
        rotate_y += 5;
    // left arrow decreases rotation by 5 degrees
    else if(key == GLUT_KEY_LEFT)
        rotate_y -= 5;
    else if(key == GLUT_KEY_UP)
        rotate_x += 5;
    else if(key == GLUT_KEY_DOWN)
        rotate_x -= 5;
    //request display update
    glutPostRedisplay();
}

// main function
int main(int argc, char ** argv){
    //initialize GLUT and process user Parameters
    glutInit(&argc, argv);
    // request double buffered true color window with z buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    //create window
    glutCreateWindow("Moving_CUBE");
    // enable z buffer depth test
    glEnable(GL_DEPTH_TEST);
    // callback function
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    //pass control to GLUT for events
    glutMainLoop();
    // Return to OS
    return 0;
}




