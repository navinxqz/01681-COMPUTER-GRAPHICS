#include <GL/glut.h>
void batman() {
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(3, 4.8);

	glVertex2f(-6.2, 4.8);
	glVertex2f(-5.6, 4.545);
	glVertex2f(-5.203, 4.334);
	glVertex2f(-4.865, 4.08);
	glVertex2f(-4.569, 3.802);
	glVertex2f(-4.341, 3.362);
	glVertex2f(-4.231, 2.872);
	glVertex2f(-4.332, 2.306);
	glVertex2f(-3.496, 2.34);
	glVertex2f(-2.77, 2.34);
	glVertex2f(-1.9924, 2.2135);
	glVertex2f(-1.3757, 2.0107);
	glVertex2f(-0.835, 1.7066);
	glVertex2f(-0.3873, 1.3518);
	glVertex2f(-0.1718, 1.0422);

	glVertex2f(0.0066, 0.7118);

	glVertex2f(0.1718, 1.0422);
	glVertex2f(0.3873, 1.3518);
	glVertex2f(0.835, 1.7066);
	glVertex2f(1.3757, 2.0107);
	glVertex2f(1.9924, 2.2135);
	glVertex2f(2.77, 2.34);
	glVertex2f(3.496, 2.34);
	glVertex2f(4.332, 2.306);
	glVertex2f(4.231, 2.872);
	glVertex2f(4.341, 3.362);
	glVertex2f(4.569, 3.802);
	glVertex2f(4.865, 4.08);
	glVertex2f(5.203, 4.334);
	glVertex2f(5.6, 4.545);
	glVertex2f(6.2, 4.8);

	glEnd();
}
static void whitespace() {
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(0.0066, 4.8);
	
	glVertex2f(0, 4.2);
	
	glVertex2f(-0.3135, 4.586);
	glVertex2f(-0.2333, 4.1537);
	glVertex2f(-0.46, 3.75);
	glVertex2f(-0.78, 3.8);
	glVertex2f(-1.204, 3.879);
	glVertex2f(-1.498, 3.972);
	glVertex2f(-1.8, 4.275);
	glVertex2f(-1.9414, 4.8);

	glEnd();

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(0.0066, 4.8);

	glVertex2f(0, 4.2);
	glVertex2f(0.349, 4.595);
	glVertex2f(0.467, 3.8965);
	glVertex2f(0.709, 3.789);
	glVertex2f(1.0243, 3.83);
	glVertex2f(1.2825, 3.87);
	glVertex2f(1.5828, 3.96);
	glVertex2f(1.822, 4.2048);
	glVertex2f(2.0745, 4.8);

	glEnd();
}

void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2.5);
	batman();
	whitespace();
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(820, 420);
	glutCreateWindow("I am Batman");
	gluOrtho2D(-7, +6.5, -1.5, +5.5);

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
