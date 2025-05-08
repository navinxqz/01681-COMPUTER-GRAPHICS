#include <GL/glut.h>

GLfloat colors[][3] = {
    {0.95f, 0.95f, 0.88f},  
    {0.15f, 0.33f, 0.54f},  
    {0.09f, 0.23f, 0.3f},  
    {0.87f, 0.69f, 0.33f},  
    {0.44f, 0.73f, 0.7f}
};
int currentColor = 0;
int numColors = 5;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glClearColor(colors[currentColor][0], colors[currentColor][1], colors[currentColor][2], 1.0f);

    glFlush();   
    glutSwapBuffers();
}
void timer(int value) {
    currentColor = (currentColor + 1) % numColors;

    glutPostRedisplay();
    glutTimerFunc(20, timer, 0);
}
void init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(300, 100);
    glutCreateWindow("Background Color Changer");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}