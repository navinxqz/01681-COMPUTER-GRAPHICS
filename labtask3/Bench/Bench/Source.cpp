#include <GL/glut.h>

void BenchLegs() {
    glColor3f(0.3f, 0.2f, 0.1f);
    glBegin(GL_POLYGON);    //left
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(-0.75f, -0.8f);
    glVertex2f(-0.75f, -0.4f);
    glVertex2f(-0.8f, -0.4f);
    glEnd();

    glBegin(GL_POLYGON);    //right
    glVertex2f(0.75f, -0.8f);
    glVertex2f(0.8f, -0.8f);
    glVertex2f(0.8f, -0.4f);
    glVertex2f(0.75f, -0.4f);
    glEnd();
}

void BenchSeat() {
    glColor3f(0.6f, 0.4f, 0.2f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85f, -0.4f);
    glVertex2f(0.85f, -0.4f);
    glVertex2f(0.85f, -0.35f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();
}

void BenchBackrest() {
    glColor3f(0.5f, 0.3f, 0.15f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85f, -0.2f);
    glVertex2f(0.85f, -0.2f);
    glVertex2f(0.85f, -0.15f);
    glVertex2f(-0.85f, -0.15f);
    glEnd();

    glColor3f(0.3f, 0.2f, 0.1f);
    for (float x = -0.8f; x <= 0.8f; x += 0.2f) {
        glBegin(GL_POLYGON);
        glVertex2f(x, -0.4f);
        glVertex2f(x + 0.02f, -0.4f);
        glVertex2f(x + 0.02f, -0.2f);
        glVertex2f(x, -0.2f);
        glEnd();
    }
}

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    BenchLegs();
    BenchSeat();
    BenchBackrest();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(300, 200);
    glutCreateWindow("Bench");

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
