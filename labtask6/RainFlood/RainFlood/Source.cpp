#include <GL/glut.h>
#include <cmath>

const int NUM_RAINDROPS = 100;
const float RAIN_SPEED = 0.02f;

float waterLevel = 0.0f;        
float maxWaterLevel = 1.0f;

struct Raindrop {
    float x, y;
} raindrops[NUM_RAINDROPS];

void initRain() {
    for (int i = 0; i < NUM_RAINDROPS; ++i) {
        raindrops[i].x = ((float)(rand() % 200) / 100.0f) - 1.0f; 
        raindrops[i].y = ((float)(rand() % 200) / 100.0f);
    }
}
void drawRaindrop(const Raindrop& rd) {
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(rd.x, rd.y);
    glVertex2f(rd.x, rd.y + 0.05f);
    glEnd();
}
void updateRain() {
    for (int i = 0; i < NUM_RAINDROPS; ++i) {
        raindrops[i].y -= RAIN_SPEED;
        if (raindrops[i].y < -1.0f) {
            raindrops[i].y = 1.0f;
        }
    }
}
void updateFlood() {
    if (waterLevel < maxWaterLevel) {
        waterLevel += 0.001f;
    }
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    for (int i = 0; i < NUM_RAINDROPS; ++i) {
        drawRaindrop(raindrops[i]);
    }
    glColor3f(0.2f, 0.4f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f + waterLevel);
    glVertex2f(-1.0f, -1.0f + waterLevel);
    glEnd();

    glutSwapBuffers();
}
void timer(int value) {
    updateRain();
    updateFlood();
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}
void init() {
    glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue background (sky)
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Simple Rain to Flood Animation");

    init();
    initRain();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}