#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // 绘制蓝色环
    glColor3f(0.0f, 0.0f, 1.0f);
    glPushMatrix();
    glTranslatef(-1.4f, 0.5f, 0.0f);
    glutSolidTorus(0.08, 0.6, 50, 50);
    glPopMatrix();

    // 绘制黄色环
    glColor3f(1.0f, 1.0f, 0.0f);
    glPushMatrix();
    glTranslatef(-0.8f, -0.4f, 0.0f);
    glutSolidTorus(0.08, 0.6, 50, 50);
    glPopMatrix();

    // 绘制黑色环
    glColor3f(0.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.0f);
    glutSolidTorus(0.08, 0.6, 50, 50);
    glPopMatrix();

    // 绘制绿色环
    glColor3f(0.0f, 1.0f, 0.0f);
    glPushMatrix();
    glTranslatef(0.8f, -0.4f, 0.0f);
    glutSolidTorus(0.08, 0.6, 50, 50);
    glPopMatrix();

    // 绘制红色环
    glColor3f(1.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(1.4f, 0.5f, 0.0f);
    glutSolidTorus(0.08, 0.6, 50, 50);
    glPopMatrix();

    glutSwapBuffers();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Olympic Rings");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
