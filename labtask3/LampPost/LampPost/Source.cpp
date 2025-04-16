#include <GL/glut.h>
#include <cmath>

// Function to draw the base of the lamp post
void drawBase() {
    glColor3f(0.0, 0.0, 0.0); // Black
    glBegin(GL_POLYGON);
    glVertex2f(-0.2f, -1.0f);
    glVertex2f(0.2f, -1.0f);
    glVertex2f(0.2f, -0.9f);
    glVertex2f(-0.2f, -0.9f);
    glEnd();
}

// Function to draw the pole
void drawPole() {
    glColor3f(0.0, 0.0, 0.0); // Black
    glBegin(GL_POLYGON);
    glVertex2f(-0.05f, -0.9f);
    glVertex2f(0.05f, -0.9f);
    glVertex2f(0.05f, 0.5f);
    glVertex2f(-0.05f, 0.5f);
    glEnd();
}

// Function to draw the stylized roof
void drawRoof() {
    glColor3f(0.5f, 0.0f, 0.0f); // Dark Red
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.25f, 0.7f);   // Left corner
    glVertex2f(0.25f, 0.7f);   // Right corner
    glVertex2f(0.0f, 0.9f);   // Top peak
    glEnd();
}

// Function to draw the lamp box
void drawLampBox() {
    glColor3f(0.0, 0.0, 0.0); // Black
    glBegin(GL_POLYGON);
    glVertex2f(-0.15f, 0.5f);
    glVertex2f(0.15f, 0.5f);
    glVertex2f(0.15f, 0.7f);
    glVertex2f(-0.15f, 0.7f);
    glEnd();
}

// Function to draw the circular bulb
void drawBulb() {
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    float cx = 0.0f, cy = 0.6f, radius = 0.04f;
    int segments = 100;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= segments; i++) {
        float angle = i * 2.0f * 3.1416f / segments;
        glVertex2f(cx + radius * cos(angle), cy + radius * sin(angle));
    }
    glEnd();
}

// Display function that calls all parts
void display() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    glClear(GL_COLOR_BUFFER_BIT);

    drawBase();
    drawPole();
    drawLampBox();
    drawRoof();
    drawBulb();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Stylized Lamp Post");
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
