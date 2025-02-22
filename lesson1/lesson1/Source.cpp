#include <GL/glut.h>

//func to render scene
void RenderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);	//clear the window with current clearing color
	glFlush();	//flush drawing commands
}
//func to create rendering state
void SetupRC() {
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);	//bg color to blue
}
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);	//initialize GLUT library
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);	//set display mode
	glutCreateWindow("Simple 1");	//create window with title

	glutDisplayFunc(RenderScene);	//set rendering func
	SetupRC();	//set up rendering state

	glutMainLoop();	//start glut event loop
	return 0;
}