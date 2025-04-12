#include <GL/glut.h>
#include <math.h>

void drawRectangle(float x1, float y1, float x2, float y2) {
    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x1, y2);
    glVertex2f(x2, y2);
    glVertex2f(x2, y1);
    glEnd();
}
void drawCircle(float cx, float cy, float radius, int segments = 36) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * 3.1415926f * i / segments;
        glVertex2f(cx + radius * cos(angle), cy + radius * sin(angle));
    }
    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);

    glColor3f(0.4f, 0.2f, 0.0f);
    drawRectangle(-0.1f, -0.9f, 0.1f, -0.4f);
    glColor3f(0.0f, 0.8f, 0.0f);

    drawCircle(0.0f, -0.3f, 0.3f);
    drawCircle(0.0f, 0.1f, 0.25f);
    drawCircle(0.0f, 0.4f, 0.2f);
    glFlush();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);  
    glutCreateWindow("Tree");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}