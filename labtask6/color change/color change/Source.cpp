#include <GL/glut.h>

GLfloat colors[][3] = {
    {1.0f, 0.0f, 0.0f},  
    {0.0f, 1.0f, 0.0f},  
    {0.0f, 0.0f, 1.0f},  
    {1.0f, 1.0f, 0.0f},  
    {1.0f, 0.0f, 1.0f}
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
void init() {
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