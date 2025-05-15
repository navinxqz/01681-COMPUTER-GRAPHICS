#include <GL/glut.h>
#include <math.h>

const float LEFT = -1.0f;
const float RIGHT = 1.0f;
const float BOTTOM = -1.0f;
const float TOP = 1.0f;

const int NUM_OBJECTS = 4;
struct Object {
    float x, y;  
    float dx, dy;
    float size;  
};

Object objects[NUM_OBJECTS];
void initObjects() {
    objects[0].x = 1.0f;  objects[0].y = 0.6f;  objects[0].dx = -0.01f; objects[0].dy = 0.0f; objects[0].size = 0.1f; // Left
    objects[1].x = -1.0f; objects[1].y = 0.2f;  objects[1].dx = 0.01f;  objects[1].dy = 0.0f; objects[1].size = 0.1f; // Right
    objects[2].x = -0.6f; objects[2].y = -1.0f; objects[2].dx = 0.0f;   objects[2].dy = 0.01f; objects[2].size = 0.1f; // Up
    objects[3].x = 0.6f;  objects[3].y = 1.0f;  objects[3].dx = 0.0f;   objects[3].dy = -0.01f; objects[3].size = 0.1f; // Down
}
void drawCircle(float x, float y, float r) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 30; i++) {
        float angle = 2.0 * 3.1416 * i / 30;
        float px = x + r * cos(angle);
        float py = y + r * sin(angle);
        glVertex2f(px, py);
    }
    glEnd();
}
void drawSquare(float x, float y, float size) {
    float h = size / 2.0f;
    glBegin(GL_QUADS);
    glVertex2f(x - h, y - h);
    glVertex2f(x + h, y - h);
    glVertex2f(x + h, y + h);
    glVertex2f(x - h, y + h);
    glEnd();
}
void drawTriangle(float x, float y, float size) {
    float h = size / 2.0f;
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y + h);
    glVertex2f(x - h, y - h);
    glVertex2f(x + h, y - h);
    glEnd();
}
void drawStar(float x, float y, float size) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 10; ++i) {
        float angle = i * 2 * 3.1416 / 10;
        float r = (i % 2 == 0) ? size : size / 2;
        float px = x + r * cos(angle);
        float py = y + r * sin(angle);
        glVertex2f(px, py);
    }
    glEnd();
}
void updatePositions() {
    for (int i = 0; i < NUM_OBJECTS; ++i) {
        objects[i].x += objects[i].dx;
        objects[i].y += objects[i].dy;
        if (objects[i].x > RIGHT + 0.1f)  objects[i].x = LEFT - 0.1f;
        if (objects[i].x < LEFT - 0.1f)    objects[i].x = RIGHT + 0.1f;
        if (objects[i].y > TOP + 0.1f)     objects[i].y = BOTTOM - 0.1f;
        if (objects[i].y < BOTTOM - 0.1f)  objects[i].y = TOP + 0.1f;
    }
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    updatePositions();
    for (int i = 0; i < NUM_OBJECTS;i++) {
        switch (i) {
        case 0: glColor3f(0.6f, 0.65f, 0.698f); drawCircle(objects[i].x, objects[i].y, objects[i].size); break; // Circle
        case 1: glColor3f(0.969f, 0.608f, 0.447f); drawSquare(objects[i].x, objects[i].y, objects[i].size); break; // Square
        case 2: glColor3f(1.0f, 0.04f, 0.33f); drawTriangle(objects[i].x, objects[i].y, objects[i].size); break; // Triangle
        case 3: glColor3f(0.114f, 0.804f, 0.624f); drawStar(objects[i].x, objects[i].y, objects[i].size); break; // Star
        }
    }glutSwapBuffers();
}
void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}
void init() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Objects Animation");

    init();
    initObjects();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}