#include <GL/glut.h>
#include <iostream>
using namespace std;

void drawSquare(float x1, float y1, float x2, float y2, bool isBlack){
    if(isBlack){
        glColor3f(0, 0, 0);
    }else{
        glColor3f(1, 1, 1);
    }
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

void border() {
    glColor3f(0, 0, 0);
    glLineWidth(3); //thickness
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(0.8f, -0.8f);
    glVertex2f(0.8f, 0.8f);
    glVertex2f(-0.8f, 0.8f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    float size = 0.4f; //square size
    float startX = -0.8f, startY = 0.8f; // Top-left of the board

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            bool isBlack = (i + j) % 2 == 0;
            float x1 = startX + j * size;
            float y1 = startY - i * size;
            float x2 = x1 + size;
            float y2 = y1 - size;
            drawSquare(x1, y1, x2, y2, isBlack);
        }
    }border();
    glutSwapBuffers();
}

void init() {
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("4x4 Chessboard");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
