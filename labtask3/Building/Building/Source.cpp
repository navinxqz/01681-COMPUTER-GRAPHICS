#include <GL/glut.h>
void drawRectangle(float x1, float y1, float x2, float y2) {
    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x1, y2);
    glVertex2f(x2, y2);
    glVertex2f(x2, y1);
    glEnd();
}
void drawGround() {
    glColor3f(0.6f, 0.6f, 0.6f);
    drawRectangle(-1.0f, -0.9f, 1.0f, -0.8f);
}
void drawBuilding() {
    glColor3f(0.7f, 0.7f, 0.7f);
    drawRectangle(-0.5f, -0.8f, 0.5f, 0.8f);
}
void drawRoof() {
    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.6f, 0.8f);
    glVertex2f(0.6f, 0.8f);
    glVertex2f(0.0f, 1.0f);
    glEnd();
}
void drawWindows() {
    glColor3f(0.0f, 0.0f, 0.0f);
    float windowWidth = 0.05f;
    float windowHeight = 0.1f;

    for (int floor = 0; floor < 5; floor++) {
        float y = -0.6f + floor * 0.3f;
        for (int col = 0; col < 3; col++) {
            float x = -0.35f + col * 0.35f;

            glColor3f(0.9f, 0.9f, 0.9f);
            drawRectangle(x - windowWidth / 2 - 0.01f, y - windowHeight / 2 - 0.01f,
                x + windowWidth / 2 + 0.01f, y + windowHeight / 2 + 0.01f);

            glColor3f(0.0f, 0.0f, 0.0f);
            drawRectangle(x - windowWidth / 2, y - windowHeight / 2,
                x + windowWidth / 2, y + windowHeight / 2);
        }
    }
}

void drawDoor() {
    glColor3f(0.5f, 0.3f, 0.0f);
    drawRectangle(-0.1f, -0.8f, 0.1f, -0.4f);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawRectangle(-0.1f, -0.6f, 0.1f, -0.62f); 
    drawRectangle(-0.01f, -0.8f, 0.01f, -0.4f);
    drawRectangle(0.05f, -0.7f, 0.07f, -0.72f);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); 
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);

    drawGround();   
    drawBuilding(); 
    drawRoof();     
    drawWindows();  
    drawDoor();
    glFlush();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowSize(400, 400); 
    glutCreateWindow("Building");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}