#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f); // White color
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.5f, -0.5f); 
    glVertex2f(-0.5f, -0.5f);
    glEnd();

    //border Black outline
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.5f, 0.5f); 
    glVertex2f(0.5f, 0.5f);  
    glVertex2f(0.5f, -0.5f); 
    glVertex2f(-0.5f, -0.5f);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // bg white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); //coordinate system
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1280,720);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rectangle with Black Border");
    
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
