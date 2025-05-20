#include <GL/glut.h>
const float LEFT = -1.0f;
const float RIGHT = 1.0f;
const float TOP = 1.0f;
const float BOTTOM = -1.0f;

float x1 = 0.8f, y1 = 0.0f;  //square
float x2 = -0.8f, y2 = 0.0f; //triangle
float x3 = 0.0f, y3 = 0.8f;  //diamond
float x4 = 0.0f, y4 = -0.8f; //rectangle

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(0.93f, 0.93f, 0.93f);
    glBegin(GL_QUADS);
    glVertex2f(x1 - 0.05f, y1 - 0.05f);
    glVertex2f(x1 + 0.05f, y1 - 0.05f);
    glVertex2f(x1 + 0.05f, y1 + 0.05f);
    glVertex2f(x1 - 0.05f, y1 + 0.05f);
    glEnd();

    glColor3f(0.114f, 0.804f, 0.624f);
    glBegin(GL_TRIANGLES);
    glVertex2f(x2, y2 + 0.06f);
    glVertex2f(x2 - 0.05f, y2 - 0.05f);
    glVertex2f(x2 + 0.05f, y2 - 0.05f);
    glEnd();

    glColor3f(0.969f, 0.608f, 0.447f);
    glBegin(GL_QUADS);
    glVertex2f(x3, y3 + 0.05f);
    glVertex2f(x3 + 0.05f, y3);
    glVertex2f(x3, y3 - 0.05f);
    glVertex2f(x3 - 0.05f, y3);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(x4 - 0.07f, y4 - 0.04f);
    glVertex2f(x4 + 0.07f, y4 - 0.04f);
    glVertex2f(x4 + 0.07f, y4 + 0.04f);
    glVertex2f(x4 - 0.07f, y4 + 0.04f);
    glEnd();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'a': //square moves left
        x1 -= 0.05f;
        if (x1 < LEFT - 0.1f) x1 = RIGHT + 0.1f;
        break;
    case 's': //triangle moves right
        x2 += 0.05f;
        if (x2 > RIGHT + 0.1f) x2 = LEFT - 0.1f;
        break;
    case 'd': //diamond moves up
        y3 += 0.05f;
        if (y3 > TOP + 0.1f) y3 = BOTTOM - 0.1f;
        break;
    case 'f': //rectangle moves down
        y4 -= 0.05f;
        if (y4 < BOTTOM - 0.1f) y4 = TOP + 0.1f;
        break;
    }
    glutPostRedisplay();
}

void init() {
    glClearColor(0.2f, 0.2f, 0.2f, 0.3f);
    gluOrtho2D(LEFT, RIGHT, BOTTOM, TOP);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Moving 4 Objects with Keys");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
