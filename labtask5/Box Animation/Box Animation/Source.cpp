#include <GL/glut.h>
#include <iostream>

float offset = 0.0f;
float direction = 0.005f;

void drawBox(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    glTranslatef(-offset, 0.0f, 0.0f);  // Move left box to the left
    glColor3f(0.96f, 0.933f, 0.867f);
    drawBox(0, 1, -1, 1, -1, 0, 0, 0);
    glPopMatrix();
    glPushMatrix();

    glTranslatef(offset, 0.0f, 0.0f);   // Move right box to the right
    glColor3f(0.48f, 0.89f, 0.81f);
    drawBox(0, 1, 1, 1, 1, 0, 0, 0);
    glPopMatrix();

    glutSwapBuffers();
}
void timer(int value) {
    offset = offset + direction;
    if (offset > 2.0f || offset < -2.0f) {
        direction = -direction;
    }
    glutPostRedisplay();
    glutTimerFunc(1, timer, 0);
}
void init() {
    glColor3f(0.0f, 0.1f, 0.2f);
    gluOrtho2D(-3, 3, -3, 3);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(300, 100);
    glutCreateWindow("Box Animation");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}