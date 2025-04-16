#include <GL/glut.h>
#include <math.h>

void Base() {
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.2f, -1.0f);
    glVertex2f(0.2f, -1.0f);
    glVertex2f(0.2f, -0.9f);
    glVertex2f(-0.2f, -0.9f);
    glEnd();
}

void Pole() {
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.05f, -0.9f);
    glVertex2f(0.05f, -0.9f);
    glVertex2f(0.05f, 0.5f);
    glVertex2f(-0.05f, 0.5f);
    glEnd();
}

void Roof() {
    glColor3f(0.5f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.25f, 0.7f);
    glVertex2f(0.25f, 0.7f); 
    glVertex2f(0.0f, 0.9f);  
    glEnd();
}

void LampBox() {
    glColor3f(0.0, 0.0, 0.0); 
    glBegin(GL_POLYGON);
    glVertex2f(-0.15f, 0.5f);
    glVertex2f(0.15f, 0.5f);
    glVertex2f(0.15f, 0.7f);
    glVertex2f(-0.15f, 0.7f);
    glEnd();
}

void Bulb() {
    glColor3f(1.0f, 1.0f, 0.0f); 
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

void display() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    Base();
    Pole();
    LampBox();
    Roof();
    Bulb();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(300, 200);
    glutCreateWindow("Lamp Post");
    
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}