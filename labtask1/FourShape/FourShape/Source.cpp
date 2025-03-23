#include <GL/glut.h>
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw Black Vertical Line (Center)
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glBegin(GL_LINES);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(0.0f, -1.0f);
    glEnd();

    //Black Horizontal Line
    glBegin(GL_LINES);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glEnd();

    //Red Square
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glBegin(GL_QUADS);
    glVertex2f(-0.6f, 0.6f);
    glVertex2f(-0.3f, 0.6f);
    glVertex2f(-0.3f, 0.3f);
    glVertex2f(-0.6f, 0.3f);
    glEnd();

    //Purple LeftFacing Triangle
    glColor3f(0.5f, 0.0f, 0.5f); // Purple color
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.6f, -0.3f);
    glVertex2f(-0.3f, -0.1f);
    glVertex2f(-0.3f, -0.5f);
    glEnd();

    //Green Right Arrow
    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glBegin(GL_QUADS);
    glVertex2f(0.3f, 0.4f);
    glVertex2f(0.7f, 0.4f);
    glVertex2f(0.7f, 0.6f);
    glVertex2f(0.3f, 0.6f);
    glEnd();
    glBegin(GL_TRIANGLES); // Arrow Head
    glVertex2f(0.7f, 0.3f);
    glVertex2f(0.9f, 0.5f);
    glVertex2f(0.7f, 0.7f);
    glEnd();

    //Yellow Triangle
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.5f, -0.1f);
    glVertex2f(0.7f, -0.5f);
    glVertex2f(0.3f, -0.5f);
    glEnd();
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); //white bg
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("4 Shapes");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
