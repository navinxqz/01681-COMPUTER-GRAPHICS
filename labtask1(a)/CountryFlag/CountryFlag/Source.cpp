#include <GL/glut.h>
#include <math.h>

void drawRectangle(float x1, float y1, float x2, float y2, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}
void England(float x1, float y1, float x2, float y2) {
    drawRectangle(x1, y1, x2, y2, 1.0f, 1.0f, 1.0f); // White bg
    drawRectangle((x1 + x2) / 2 - 0.03f, y1, (x1 + x2) / 2 + 0.03f, y2, 1.0f, 0.0f, 0.0f); // Vertical
    drawRectangle(x1, (y1 + y2) / 2 - 0.03f, x2, (y1 + y2) / 2 + 0.03f, 1.0f, 0.0f, 0.0f); // Horizontal
}

void Finland(float x1, float y1, float x2, float y2) {
    drawRectangle(x1, y1, x2, y2, 1.0f, 1.0f, 1.0f);
    drawRectangle(x1 + 0.07f, y1, x1 + 0.14f, y2, 0.0f, 0.0f, 1.0f); // Vertical
    drawRectangle(x1, (y1 + y2) / 2 - 0.03f, x2, (y1 + y2) / 2 + 0.03f, 0.0f, 0.0f, 1.0f); // Horizontal
}

void Italy(float x1, float y1, float x2, float y2) {
    drawRectangle(x1, y1, x1 + (x2 - x1) / 3, y2, 0.0f, 0.5f, 0.0f); // Green
    drawRectangle(x1 + (x2 - x1) / 3, y1, x1 + 2 * (x2 - x1) / 3, y2, 1.0f, 1.0f, 1.0f); // White
    drawRectangle(x1 + 2 * (x2 - x1) / 3, y1, x2, y2, 1.0f, 0.0f, 0.0f); // Red
}

void France(float x1, float y1, float x2, float y2) {
    drawRectangle(x1, y1, x1 + (x2 - x1) / 3, y2, 0.0f, 0.0f, 1.0f); // Blue
    drawRectangle(x1 + (x2 - x1) / 3, y1, x1 + 2 * (x2 - x1) / 3, y2, 1.0f, 1.0f, 1.0f); // White
    drawRectangle(x1 + 2 * (x2 - x1) / 3, y1, x2, y2, 1.0f, 0.0f, 0.0f); // Red
}

void Germany(float x1, float y1, float x2, float y2) {
    drawRectangle(x1, y1, x2, y1 + (y2 - y1) / 3, 0.0f, 0.0f, 0.0f); // Black
    drawRectangle(x1, y1 + (y2 - y1) / 3, x2, y1 + 2 * (y2 - y1) / 3, 1.0f, 0.0f, 0.0f); // Red
    drawRectangle(x1, y1 + 2 * (y2 - y1) / 3, x2, y2, 1.0f, 1.0f, 0.0f); // Yellow
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    float width = 2.0f / 5;
    float height = 0.45f;
    float spacing = 0.02f;

    England(-1.0f, -height / 2, -1.0f + width - spacing, height / 2);
    Finland(-1.0f + width + spacing, -height / 2, -1.0f + 2 * width - spacing, height / 2);
    Italy(-1.0f + 2 * width + spacing, -height / 2, -1.0f + 3 * width - spacing, height / 2);
    France(-1.0f + 3 * width + spacing, -height / 2, -1.0f + 4 * width - spacing, height / 2);
    Germany(-1.0f + 4 * width + spacing, -height / 2, 1.0f, height / 2);

    glFlush();
}

void init() {
    glClearColor(0.5, 0.5, 0.5, 1.0); // Gray bg
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 450);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("5 Flags");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
