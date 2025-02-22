#include <GL/glut.h>

void RenderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);	//red
	glRectf(-0.5, 0.5, 0.5, -0.5);	//rectangle
	glFlush();
}
void SetupRC(void) {
	glClearColor(0.0, 0.0, 1.0, 1.0);	//blue
}
void ChangeSize(GLsizei w, GLsizei h) {
	if (h == 0) { h = 1; }
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	GLfloat aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w <= h) {
		glOrtho(-1.0, 1.0, -1 / aspectRatio, 1.0 / aspectRatio, 1.0, -1.0);
	}
	else {
		glOrtho(-1.0 * aspectRatio, 1.0 * aspectRatio, -1.0, 1.0, 1.0, -1.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Rectangle");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);

	SetupRC();
	glutMainLoop();
	return 0;
}