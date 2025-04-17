#include <GL/glut.h> 
#include <math.h> 

int windowWidth = 1000, windowHeight = 600;
void drawCircle(float cx, float cy, float radius, int segments) {
    glBegin(GL_POLYGON);

    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(segments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void drawBuilding(float offsetX) {
    float bx1 = 250 + offsetX, by1 = 100;
    float bx2 = 550 + offsetX, by2 = 500;
    float centerX = (bx1 + bx2) / 2;
    glColor3f(1.0f, 0.96f, 0.8f);
    glBegin(GL_POLYGON);

    glVertex2f(bx1, by1);
    glVertex2f(bx2, by1);
    glVertex2f(bx2, by2);
    glVertex2f(bx1, by2);

    glEnd();



    float roofPeakY = by2 + 50;
    glColor3f(0.6f, 0.3f, 0.1f);
    glBegin(GL_TRIANGLES);

    glVertex2f(bx1 - 10, by2);
    glVertex2f(bx2 + 10, by2);
    glVertex2f(centerX, roofPeakY);

    glEnd();

    glColor3f(0, 0, 0);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);

    glVertex2f(bx1 - 10, by2);
    glVertex2f(bx2 + 10, by2);
    glVertex2f(centerX, roofPeakY);

    glEnd();



    float floorHeight = (by2 - by1) / 5;
    float winWidth = 30, winHeight = 30;



    for (int floor = 0; floor < 5; floor++) {
        float winY1 = by1 + floor * floorHeight + 20;
        float winY2 = winY1 + winHeight;
        float leftX1 = bx1 + 30;
        float leftX2 = leftX1 + winWidth;

        glColor3f(0.5f, 0.8f, 1.0f);
        glBegin(GL_POLYGON);

        glVertex2f(leftX1, winY1);
        glVertex2f(leftX2, winY1);
        glVertex2f(leftX2, winY2);
        glVertex2f(leftX1, winY2);
        glEnd();

        glColor3f(0, 0, 0);
        glLineWidth(2.0f);
        glBegin(GL_LINE_LOOP);

        glVertex2f(leftX1, winY1);
        glVertex2f(leftX2, winY1);
        glVertex2f(leftX2, winY2);
        glVertex2f(leftX1, winY2);
        glEnd();



        float rightX2 = bx2 - 30;
        float rightX1 = rightX2 - winWidth;
        glColor3f(0.5f, 0.8f, 1.0f);
        glBegin(GL_POLYGON);

        glVertex2f(rightX1, winY1);
        glVertex2f(rightX2, winY1);
        glVertex2f(rightX2, winY2);
        glVertex2f(rightX1, winY2);
        glEnd();

        glColor3f(0, 0, 0);
        glBegin(GL_LINE_LOOP);
        glVertex2f(rightX1, winY1);
        glVertex2f(rightX2, winY1);
        glVertex2f(rightX2, winY2);
        glVertex2f(rightX1, winY2);
        glEnd();
    }
    float doorWidth = 60, doorHeight = 80;
    float doorX1 = centerX - doorWidth / 2;
    float doorX2 = centerX + doorWidth / 2;
    float doorY1 = by1;
    float doorY2 = by1 + doorHeight;
    
    glColor3f(0.7f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(doorX1, doorY1);
    glVertex2f(doorX2, doorY1);
    glVertex2f(doorX2, doorY2);
    glVertex2f(doorX1, doorY2);
    glEnd();

    glColor3f(0, 0, 0);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(doorX1, doorY1);
    glVertex2f(doorX2, doorY1);
    glVertex2f(doorX2, doorY2);
    glVertex2f(doorX1, doorY2);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(centerX, doorY1);
    glVertex2f(centerX, doorY2);
    glEnd();
}

void drawTree(float x, float y) {
    float trunkWidth = 50;
    float trunkHeight = 140;
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + trunkWidth, y);
    glVertex2f(x + trunkWidth, y + trunkHeight);
    glVertex2f(x, y + trunkHeight);
    glEnd();

    float centerX = x + trunkWidth / 2;
    float centerY = y + trunkHeight;

    glColor3f(0.0f, 0.6f, 0.2f);
    drawCircle(centerX, centerY + 80, 70, 50);
    drawCircle(centerX - 50, centerY + 50, 60, 50);
    drawCircle(centerX + 50, centerY + 50, 60, 50);
    drawCircle(centerX - 30, centerY + 10, 55, 50);
    drawCircle(centerX + 30, centerY + 10, 55, 50);
}

void drawLampPost(float x, float y) {

    float postWidth = 4;

    float postHeight = 100;



    glColor3f(0.4f, 0.4f, 0.4f);

    glBegin(GL_POLYGON);

    glVertex2f(x, y);

    glVertex2f(x + postWidth, y);

    glVertex2f(x + postWidth, y + postHeight);

    glVertex2f(x, y + postHeight);

    glEnd();



    glColor3f(0.3f, 0.3f, 0.3f);

    float headWidth = 20, headHeight = 5;

    glBegin(GL_POLYGON);

    glVertex2f(x + postWidth / 2 - headWidth / 2, y + postHeight);

    glVertex2f(x + postWidth / 2 + headWidth / 2, y + postHeight);

    glVertex2f(x + postWidth / 2 + headWidth / 2, y + postHeight + headHeight);

    glVertex2f(x + postWidth / 2 - headWidth / 2, y + postHeight + headHeight);

    glEnd();



    glColor3f(1.0f, 1.0f, 0.2f);

    drawCircle(x + postWidth / 2, y + postHeight + headHeight + 5, 10, 50);

}



void drawBench(float x, float y) {

    glColor3f(0.65f, 0.33f, 0.10f);

    float legWidth = 4, legHeight = 18;

    float seatLength = 60, seatHeight = 8, backrestHeight = 4;



    glBegin(GL_POLYGON); glVertex2f(x, y); glVertex2f(x + legWidth, y);

    glVertex2f(x + legWidth, y + legHeight); glVertex2f(x, y + legHeight); glEnd();



    glBegin(GL_POLYGON); glVertex2f(x + seatLength - legWidth, y);

    glVertex2f(x + seatLength, y); glVertex2f(x + seatLength, y + legHeight);

    glVertex2f(x + seatLength - legWidth, y + legHeight); glEnd();



    glBegin(GL_POLYGON);

    glVertex2f(x, y + legHeight);

    glVertex2f(x + seatLength, y + legHeight);

    glVertex2f(x + seatLength, y + legHeight + seatHeight);

    glVertex2f(x, y + legHeight + seatHeight);

    glEnd();



    for (int i = 0; i < 2; i++) {

        float offset = seatHeight + 4 + i * (backrestHeight + 3);

        glBegin(GL_POLYGON);

        glVertex2f(x, y + legHeight + offset);

        glVertex2f(x + seatLength, y + legHeight + offset);

        glVertex2f(x + seatLength, y + legHeight + offset + backrestHeight);

        glVertex2f(x, y + legHeight + offset + backrestHeight);

        glEnd();

    }

}

void drawSidewalk() {

    glColor3f(0.5f, 0.5f, 0.5f);

    glBegin(GL_POLYGON);

    glVertex2f(0, 95);

    glVertex2f(2000, 95);

    glVertex2f(2000, 115);

    glVertex2f(0, 115);

    glEnd();

}



void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawSidewalk();



    drawTree(50, 100);

    drawLampPost(160, 100);

    drawBuilding(0);             // Building 1 

    drawLampPost(680, 100);

    drawBench(610, 100);
    glFlush();

}



void reshape(int w, int h) {

    windowWidth = w;

    windowHeight = h;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(0, windowWidth, 0, windowHeight);

    glMatrixMode(GL_MODELVIEW);

}
int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(windowWidth, windowHeight);

    glutCreateWindow("Complete Scene");



    glClearColor(0.0, 0.0, 0.0, 1.0);



    glutDisplayFunc(display);

    glutReshapeFunc(reshape);



    glutMainLoop();

    return 0;

}
