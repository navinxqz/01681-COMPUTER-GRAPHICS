#include <GL/glut.h>
#include <iostream>

// Animation variables
float offset = 0.0f;
float direction = 0.005f;

// Function to draw a box using 4 points
void drawBox(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Save current matrix state
    glPushMatrix();

    // Move left box to the left
    glTranslatef(-offset, 0.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    drawBox(0, 1, -1, 1, -1, 0, 0, 0);

    glPopMatrix();
    glPushMatrix();

    // Move right box to the right
    glTranslatef(offset, 0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    drawBox(0, 1, 1, 1, 1, 0, 0, 0);

    glPopMatrix();

    glutSwapBuffers();
}
void timer(int value) {
    offset += direction;

    if (offset > 2.0f || offset < -2.0f)
        direction = -direction;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // ~60 FPS
}

// Initialize OpenGL settings
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    gluOrtho2D(-3, 3, -3, 3); // Orthographic projection
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Box Animation");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}