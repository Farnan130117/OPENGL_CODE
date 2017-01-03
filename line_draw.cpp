
#include<GL/glut.h>
void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_LINES);
		glVertex2i(0,0);//mid_point_of_the_display
		glVertex2i(0, 1);

	glEnd();

		glBegin(GL_LINES);
		glVertex2i(0,0);//mid_point_of_the_display
		glVertex2i(1, 0);

	glEnd();

        glBegin(GL_LINES);
		glVertex2i(1,0);//mid_point_of_the_display
		glVertex2i(0, 1);

	glEnd();

        glutSwapBuffers();
}

int main(int argc, char **argv) {

	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0,0);//mid_point_of_the_display
	glutInitWindowSize(400,400);
	glutCreateWindow("Line Drawing");

	// register callbacks
	glutDisplayFunc(display);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}
