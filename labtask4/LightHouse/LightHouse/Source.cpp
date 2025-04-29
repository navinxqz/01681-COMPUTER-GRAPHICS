#include <GL/glut.h>
#include <math.h>

void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); // angle
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}
void drawHill() {

    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(0.0f, -0.3f, 0.565f, 100);

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.45, 0.1);
    glVertex2f(-0.3, 0.18);
    glVertex2f(0.3, 0.18);
    glVertex2f(0.45, 0.1);
    glVertex2f(0.5, 0.0);
    glVertex2f(-0.5, 0.0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.45, 0.1);
    glVertex2f(-0.3, 0.18);
    glVertex2f(0.3, 0.18);
    glVertex2f(0.45, 0.1);
    glVertex2f(0.5, 0.0);
    glVertex2f(-0.5, 0.0);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.45, 0.1);
    glVertex2f(-0.3, 0.18);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.85, 0.1);
    glVertex2f(-0.45, 0.1);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.45, 0.1);
    glVertex2f(0.3, 0.18);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.85, 0.1);
    glVertex2f(0.45, 0.1);
    glEnd();
}

void drawLightHouse() {
    glBegin(GL_LINES);
    glVertex2f(-0.04, 0.26);
    glVertex2f(-0.02, 0.62);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.05, 0.62);
    glVertex2f(0.06, 0.26);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.03, 0.67);
    glVertex2f(-0.02, 0.675);
    glVertex2f(0.05, 0.675);
    glVertex2f(0.06, 0.67);
    glVertex2f(0.06, 0.625);
    glVertex2f(0.05, 0.62);
    glVertex2f(-0.02, 0.62);
    glVertex2f(-0.03, 0.625);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.03, 0.67);
    glVertex2f(-0.02, 0.675);
    glVertex2f(0.05, 0.675);
    glVertex2f(0.06, 0.67);
    glVertex2f(0.06, 0.625);
    glVertex2f(0.05, 0.62);
    glVertex2f(-0.02, 0.62);
    glVertex2f(-0.03, 0.625);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.03, 0.655);
    glVertex2f(0.06, 0.655);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.03, 0.64);
    glVertex2f(0.06, 0.64);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.015, 0.72);
    glVertex2f(-0.025, 0.72);
    glVertex2f(0.015, 0.76);
    glVertex2f(0.055, 0.72);
    glVertex2f(0.045, 0.72);
    glVertex2f(0.045, 0.675);
    glVertex2f(-0.015, 0.675);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.015, 0.72);
    glVertex2f(-0.025, 0.72);
    glVertex2f(0.015, 0.76);
    glVertex2f(0.055, 0.72);
    glVertex2f(0.045, 0.72);
    glVertex2f(0.045, 0.675);
    glVertex2f(-0.015, 0.675);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.725);
    glVertex2f(0.03, 0.725);
    glVertex2f(0.03, 0.675);
    glVertex2f(0.0, 0.675);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.0, 0.725);
    glVertex2f(0.03, 0.725);
    glVertex2f(0.03, 0.675);
    glVertex2f(0.0, 0.675);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.0, 0.715);
    glVertex2f(0.03, 0.715);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.015, 0.76);
    glVertex2f(0.015, 0.78);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.005, 0.605);
    glVertex2f(0.025, 0.605);
    glVertex2f(0.025, 0.57);
    glVertex2f(0.005, 0.57);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.005, 0.605);
    glVertex2f(0.025, 0.605);
    glVertex2f(0.025, 0.57);
    glVertex2f(0.005, 0.57);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.598);
    glVertex2f(0.02, 0.598);
    glVertex2f(0.02, 0.578);
    glVertex2f(0.01, 0.578);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.01, 0.598);
    glVertex2f(0.02, 0.598);
    glVertex2f(0.02, 0.578);
    glVertex2f(0.01, 0.578);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.004, 0.39);
    glVertex2f(0.024, 0.39);
    glVertex2f(0.024, 0.362);
    glVertex2f(0.004, 0.362);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.004, 0.39);
    glVertex2f(0.024, 0.39);
    glVertex2f(0.024, 0.362);
    glVertex2f(0.004, 0.362);
    glEnd();


    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.01, 0.3845);
    glVertex2f(0.018, 0.3845);
    glVertex2f(0.018, 0.367);
    glVertex2f(0.01, 0.367);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.01, 0.3845);
    glVertex2f(0.018, 0.3845);
    glVertex2f(0.018, 0.367);
    glVertex2f(0.01, 0.367);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.42, 0.78);
    glVertex2f(-0.06, 0.71);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.51, 0.69);
    glVertex2f(-0.07, 0.68);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.44, 0.58);
    glVertex2f(-0.07, 0.65);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.1, 0.71);
    glVertex2f(0.46, 0.78);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.12, 0.68);
    glVertex2f(0.55, 0.69);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.12, 0.65);
    glVertex2f(0.48, 0.58);
    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawHill();
    drawLightHouse();
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);        
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1, 1, 0, 1);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(300, 10);
    glutCreateWindow("Light House");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

