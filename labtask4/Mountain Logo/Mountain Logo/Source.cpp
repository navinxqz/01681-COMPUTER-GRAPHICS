#include <GL/glut.h>
#include <string.h>
#include <math.h>

void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cosf(theta); 
        float y = r * sinf(theta); 
        glVertex2f(x + cx, y + cy);
    }glEnd();
}

void drawSun() {
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(0.0f, 0.4f, 0.4f, 100);

    glBegin(GL_LINES);
    glVertex2f(-0.55f, 0.65f);
    glVertex2f(0.0f, 0.65f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.2f, 0.5f);
    glVertex2f(0.6f, 0.5f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.3f, 0.3f);
    glVertex2f(0.5f, 0.3f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.5f, 0.35f);
    glVertex2f(-0.2f, 0.35f);
    glEnd();
}
void drawMountain() {
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.8f, 0.0f);
    glVertex2f(0.8f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.7f, 0.0f);
    glVertex2f(-0.32f, 0.16f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.32f, 0.16f);
    glVertex2f(-0.2f, 0.25f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.32f, 0.16f);
    glVertex2f(-0.2f, 0.25f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.32f, 0.16f);
    glVertex2f(-0.2f, 0.25f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.2f, 0.25f);
    glVertex2f(-0.11f, 0.35f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.11f, 0.35f);
    glVertex2f(0.0f, 0.35f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.35f);
    glVertex2f(0.1f, 0.45f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.1f, 0.45f);
    glVertex2f(0.15f, 0.35f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.15f, 0.35f);
    glVertex2f(0.3f, 0.2f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.3f, 0.2f);
    glVertex2f(0.7f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.04f, 0.34f);
    glVertex2f(0.1f, 0.45f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.04f, 0.34f);
    glVertex2f(0.08f, 0.33f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.08f, 0.33f);
    glVertex2f(0.1f, 0.3f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.1f, 0.3f);
    glVertex2f(0.08f, 0.27f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.08f, 0.27f);
    glVertex2f(0.085f, 0.26f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.085f, 0.26f);
    glVertex2f(0.075f, 0.245f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.075f, 0.245f);;
    glVertex2f(0.08f, 0.22f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.08f, 0.22f);
    glVertex2f(0.07f, 0.21f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.07f, 0.21f);
    glVertex2f(0.08f, 0.18f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.08f, 0.18f);
    glVertex2f(0.04f, 0.12f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.08f);
    glVertex2f(-0.06f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.1f, 0.32f);
    glVertex2f(0.02f, 0.32f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.16f, 0.27f);
    glVertex2f(0.06f, 0.27f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.22f, 0.21f);
    glVertex2f(0.06f, 0.21f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.36f, 0.12f);
    glVertex2f(0.02f, 0.12f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.46f, 0.07f);
    glVertex2f(-0.02f, 0.07f);
    glEnd();
}

void drawTreeL() {
    glBegin(GL_LINES);
    glVertex2f(-0.7f, 0.0f);
    glVertex2f(-0.7f, 0.3f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.75f, 0.05f);
    glVertex2f(-0.7f, 0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.7f, 0.1f);
    glVertex2f(-0.65f, 0.05f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.75, 0.15);
    glVertex2f(-0.7f, 0.2f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.7f, 0.2f);
    glVertex2f(-0.65f, 0.15f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.75f, 0.25f);
    glVertex2f(-0.7f, 0.3f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.7f, 0.3f);
    glVertex2f(-0.65f, 0.25f);
    glEnd();
}

void drawTreeR() {
    glBegin(GL_LINES);
    glVertex2f(0.7f, 0.0f);
    glVertex2f(0.7f, 0.3f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.75f, 0.05f);
    glVertex2f(0.7f, 0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.7f, 0.1f);
    glVertex2f(0.65f, 0.05f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.75, 0.15);
    glVertex2f(0.7f, 0.2f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.7f, 0.2f);
    glVertex2f(0.65f, 0.15f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.75f, 0.25f);
    glVertex2f(0.7f, 0.3f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.7f, 0.3f);
    glVertex2f(0.65f, 0.25f);
    glEnd();
}
void drawText(const char* text, float x, float y) {
    glRasterPos2f(x, y);
    for (int i = 0; i < strlen(text); i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);

    drawSun();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.32f, 0.16f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.7f, 0.0f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.3f, 0.2f);
    glVertex2f(0.7f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glEnd();

    drawMountain();
    drawTreeL();
    drawTreeR();
    drawText("MOUNTAIN", -0.1f,-0.1f);
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(300, 200);
    glutCreateWindow("Mountain");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
