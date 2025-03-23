#include <GL/glut.h>
#include <iostream>
#include <sstream>
using namespace std;

void conv(const char* hex, float& r, float& g, float& b){  //hex to RGB conv
    int hr, hg, hb;
    string hexStr(hex + 1); // Skip #
    stringstream ss;
    ss << std::hex << hexStr.substr(0, 2) << " "
        << hexStr.substr(2, 2) << " "
        << hexStr.substr(4, 2);
    ss >> hr >> hg >> hb;
    r = hr / 255.0f;
    g = hg / 255.0f;
    b = hb / 255.0f;
}

void drawStripe(float yTop, float yBottom, const char* color, float flagLeft, float flagRight) {
    float r, g, b;
    conv(color, r, g, b);
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(flagLeft, yTop);
    glVertex2f(flagRight, yTop);
    glVertex2f(flagRight, yBottom);
    glVertex2f(flagLeft, yBottom);
    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    const char* colors[7] = {
        "#9400D3",  // Violet
        "#0000FF",  // Blue
        "#00CED1",  // Cyan
        "#008000",  // Green
        "#FFA500",  // Orange
        "#FFFF00",  // Yellow
        "#FF0000"   // Red
    };

    float flagLeft = -0.6f;//boundary
    float flagRight = 0.6f;
    float flagTop = 0.5f;
    float flagBottom = -0.5f;

    float stripeHeight = (flagTop - flagBottom) / 7; //stripe height
    float yTop = flagTop, yBottom = flagTop - stripeHeight;

    for (int i = 0; i < 7; i++) {
        drawStripe(yTop, yBottom, colors[i], flagLeft, flagRight);
        yTop -= stripeHeight;
        yBottom -= stripeHeight;
    }
    glutSwapBuffers();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); //white bg
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); //coordinate
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
