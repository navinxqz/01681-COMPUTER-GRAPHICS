#include <GL/glut.h>
#include <math.h>
float bladeRotation = 0.0f;

void drawCircle(float cx, float cy, float r, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);

    for (int i = 0; i <= segments; ++i) {
        float angle = 2.0f * 3.1416 * i / segments;
        float x = cx + r * cos(angle);
        float y = cy + r * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawRectangle(float x, float y, float x2, float y2) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x2, y);
    glVertex2f(x2, y2);
    glVertex2f(x, y2);
    glEnd();
}
void Blades() {
    glPushMatrix();
    glRotatef(bladeRotation, 0.0f, 0.0f, 1.0f);
    glColor3f(0.4f, 0.4f, 0.4f);
    drawRectangle(-0.6f, -0.05f, 0.6f, 0.05f);
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
    drawRectangle(-0.6f, -0.05f, 0.6f, 0.05f);

    glPopMatrix();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-5.0, 5.0, -3.0, 3.0);
    glColor3f(0.3f, 0.3f, 0.3f);
    drawRectangle(-0.1f, -1.5f, 0.1f, 1.0f);
    glColor3f(0.6f, 0.6f, 0.6f);
    drawCircle(0.0f, 1.0f, 0.3f, 30);

    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    Blades();
    glPopMatrix();
    glutSwapBuffers();
}

void timer(int value) {
    bladeRotation += 2.0f;
    if (bladeRotation > 360.0f)
        bladeRotation -= 360.0f;

    glutPostRedisplay();
    glutTimerFunc(2, timer, 0);
}
void init() {
    glClearColor(0.8f, 0.9f, 1.0f, 1.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(300, 100);
    glutCreateWindow("Windmill Animation");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}