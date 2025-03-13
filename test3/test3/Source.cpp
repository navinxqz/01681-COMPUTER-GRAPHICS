#include <windows.h> // for MS Windows

#include <GL/glut.h> // GLUT, include glu.h and gl.h


/* Handler for window-repaint event. Call back when the window first appears and

whenever the window needs to be re-painted. */

void display() {

	glClearColor(162/256, 0.83, 0.0f, 1.0f); // Set background color to black and opaque

	glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

	glPointSize(5.0);

	// Draw a Red 1x1 Square centered at origin

	glBegin(GL_POINTS); // Each set of 4 vertices form a quad

	glColor3f(1.0f, 0.0f, 0.0f); // Red

	glVertex2f(-0.0f, -0.0f); // x, y


	glEnd();


	glFlush(); // Render now

}


/* Main function: GLUT runs as a console application starting at main() */

int main(int argc, char** argv) {

	glutInit(&argc, argv); // Initialize GLUT

	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title

	glutInitWindowSize(600,600); // Set the window's initial width & height

	glutDisplayFunc(display); // Register display callback handler for window re-paint

	glutMainLoop(); // Enter the event-processing loop

	return 0;

}