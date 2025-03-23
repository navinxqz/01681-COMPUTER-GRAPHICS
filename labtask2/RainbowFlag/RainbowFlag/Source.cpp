#include <GL/glut.h>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

void conv(const string& hex, float& r, float& g, float& b) {    //hex to rgb format
    int hr = stoi(hex.substr(1, 2), nullptr, 16);
    int hg = stoi(hex.substr(3, 2), nullptr, 16);
    int hb = stoi(hex.substr(5, 2), nullptr, 16);
    r = hr / 255.0f;
    g = hg / 255.0f;
    b = hb / 255.0f;
}

void drawStripe(const string& color, float y1, float y2) {
    float r, g, b;
    conv(color, r, g, b);
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(-0.8f, y1);
    glVertex2f(0.8f, y1);
    glVertex2f(0.8f, y2);
    glVertex2f(-0.8f, y2);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawStripe("#9400D3", 0.7f, 0.5f); // purple
    drawStripe("#0000FF", 0.5f, 0.3f); // Blue
    drawStripe("#00CED1", 0.3f, 0.1f); // Cyan
    drawStripe("#008000", 0.1f, -0.1f); // Green
    drawStripe("#FFA500", -0.1f, -0.3f); // Orange
    drawStripe("#FFFF00", -0.3f, -0.5f); // Yellow
    drawStripe("#FF0000", -0.5f, -0.7f); // Red
    glutSwapBuffers();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // white bg
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // coordinates
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Rainbow Flag");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
