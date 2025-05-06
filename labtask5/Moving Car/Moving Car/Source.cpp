#include <GL/glut.h>
#include <cmath>

float wheelRotation = 0.0f;
float carPos = -4.0f;

void drawCircle(float cx, float cy, float r, int numSegments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);

    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0f * 3.1415 * i / numSegments;
        float x = r * cosf(angle);
        float y = r * sinf(angle);
        glVertex2f(cx + x, cy + y);
    }glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glClearColor(0.3f, 0.48f, 0.55f, 1.0f);
    glPushMatrix();

    glTranslatef(carPos, 0, 0);
    glScalef(0.2f, 0.2f, 1.0f);

    //roof
    glColor3f(0.22f, 0.24f, 0.27f);
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, 0.0f);   // E
    glVertex2f(-0.5f, 0.5f);   // F
    glVertex2f(0.5f, 0.5f);    // G
    glVertex2f(1.0f, 0.0f);    // H
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, 0.0f);   // E
    glVertex2f(-0.5f, 0.5f);   // F
    glVertex2f(-1.0f, 0.0f);    // M
    glEnd();

    //body
    glColor3f(0.87f, 0.82f, 0.72f);
    glBegin(GL_QUADS);
    glVertex2f(-2.0f, 0.0f);   // A
    glVertex2f(2.0f, 0.0f);    // B
    glVertex2f(2.0f, -0.5f);   // C
    glVertex2f(-2.0f, -0.5f);  // D
    glEnd();

    //roof to base
    glColor3f(0.22f, 0.24f, 0.27f);
    glBegin(GL_LINES);
    glVertex2f(-0.5f, 0.0f);   // E
    glVertex2f(-2.0f, 0.0f);   // A
    glVertex2f(1.0f, 0.0f);    // H
    glVertex2f(2.0f, 0.0f);    // B
    glEnd();
    glPushMatrix();

    // Front Wheel
    glTranslatef(-1.0f, -0.5f, 0.0f);
    glRotatef(wheelRotation, 0.0f, 0.0f, 1.0f);
    glColor3f(0.13f, 0.16f, 0.19f);
    drawCircle(0.0f, 0.0f, 0.25f, 20);
    glPopMatrix();

    // Back Wheel
    glPushMatrix();
    glTranslatef(1.0f, -0.5f, 0.0f);
    glRotatef(wheelRotation, 0.0f, 0.0f, 1.0f);
    glColor3f(0.13f, 0.13f, 0.13f);
    drawCircle(0.0f, 0.0f, 0.25f, 20);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}
void timer(int value) {
    wheelRotation += 2.0f;
    if (wheelRotation > 360.0f) { wheelRotation -= 360.0f; }

    carPos += 0.02f;
    if (carPos > 6.0f) { carPos = -4.0f; }
    glutPostRedisplay();
    glutTimerFunc(10, timer, 0);
}
void init() {
    glClearColor(0.3f, 0.48f, 0.55f, 1.0f);
    gluOrtho2D(-4.0, 4.0, -2.5, 2.0);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(300, 100);
    glutCreateWindow("Car Movement");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}