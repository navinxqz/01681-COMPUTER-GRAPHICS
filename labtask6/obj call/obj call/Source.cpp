#include <GL/glut.h>
#include <cmath>

int currentObject = 0;
const int numObjects = 4;
const int delay = 20;

void drawCircle(float x, float y, float r) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 30; ++i) {
        float angle = 2.0 * 3.1416 * i / 30;
        float px = x + r * cos(angle);
        float py = y + r * sin(angle);
        glVertex2f(px, py);
    }
    glEnd();
}

void drawRectangle(float x1, float y1, float x2, float y2) {
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}
void drawTriangle() {
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glEnd();
}
void drawStar() {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 10; ++i) {
        float angle = i * 2 * 3.1416 / 10;
        float r = (i % 2 == 0) ? 0.5f : 0.25f;
        float x = 0.0f + r * cos(angle);
        float y = 0.0f + r * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);

    switch (currentObject) {
    case 0:
        drawCircle(0.0f, 0.0f, 0.4f);
        break;
    case 1:
        drawRectangle(-0.4f, -0.4f, 0.4f, 0.4f);
        break;
    case 2:
        drawTriangle();
        break;
    case 3:
        drawStar();
        break;
    }
    glPopMatrix();
    glutSwapBuffers();
}
void timer(int value) {
    currentObject = (currentObject + 1) % numObjects;
    glutPostRedisplay();
    glutTimerFunc(delay, timer, 0);
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Sequential Object Animation");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(delay, timer, 0);
    glutMainLoop();
    return 0;
}