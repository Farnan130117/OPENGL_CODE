#include<GL/glut.h>
void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_LINES);
		glVertex2d(-0.2,-0.5);
		glVertex2d(0.1, 0.5);

	glEnd();

        glutSwapBuffers();
}

int main(int argc, char **argv) {

	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(320,320);
	glutCreateWindow("Line Drawing");

	// register callbacks
	glutDisplayFunc(display);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}
