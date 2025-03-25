#include <GL/glut.h>
void batman() {
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-1.5, 4.8);

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
	glVertex2f(-0.0066, 0.7118);

	glVertex2f(0.079, 0.446);

	glVertex2f(0.177, 0.712);
	glVertex2f(0.3606, 1.0637);
	glVertex2f(0.6513, 1.4247);
	glVertex2f(1.0827, 1.7246);
	glVertex2f(1.572, 1.954);
	glVertex2f(2.0079, 2.0942);
	glVertex2f(2.4347, 2.1782);
	glVertex2f(2.949, 2.239);
	glVertex2f(3.5035, 2.2622);
	glVertex2f(3.9573, 2.2488);
	glVertex2f(4.29, 2.22);
	glVertex2f(4.5455, 2.1815);

	glVertex2f(4.4626, 2.5395);
	glVertex2f(4.472, 2.815);
	glVertex2f(4.53, 3.15);
	glVertex2f(4.713, 3.494);
	glVertex2f(5, 3.8);
	glVertex2f(5.4488, 4.1706);
	glVertex2f(5.912, 4.427);
	glVertex2f(6.4089, 4.6315);

	glEnd();
}
void extra() {
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);

	glVertex2f(0, 4.8);
	glVertex2f(0, 3.9);
	glVertex2f(-0.411, 3.762);
	glVertex2f(-0.21, 4.546);
	glVertex2f(-0.78, 3.8);

	glVertex2f(-0.97, 3.81);
	glVertex2f(-1.204, 3.879);
	glVertex2f(-1.498, 3.972);
	glVertex2f(-1.8, 4.275);
	glVertex2f(-1.9414, 4.8);

	glEnd();

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);

	glVertex2f(0, 4.8);
	glVertex2f(0, 3.9);
	glVertex2f(0.4, 3.8);
	glVertex2f(0.6, 4.6);
	glVertex2f(0.78, 3.8);
	glVertex2f(1, 3.5);
	glVertex2f(1.25, 3.6);
	glVertex2f(1.4, 3.8);
	glVertex2f(1.5, 4.2);
	glVertex2f(1.5, 4.8);


	glEnd();
}

void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2.5);
	batman();
	extra();
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