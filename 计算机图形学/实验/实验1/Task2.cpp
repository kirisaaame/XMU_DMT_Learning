#include <GL/glut.h>
#include <iostream>

const GLsizei WIDTH = 500; // 屏幕宽度
const GLsizei HEIGHT = 500; // 屏幕高度
const GLsizei RADIUS = WIDTH / 4; // 圆盘半径

GLfloat ZHANBI[7] = { 60, 55, 50, 45, 40, 35, 30 }; // 每个扇形占比

const GLdouble PI = 3.1415926;

class Point {
public:
    GLint x, y;
};

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // 背景色为白色
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}

void drawCircle() {
    Point center;
    GLdouble angle[7], cumulativeAngle[8];

    center.x = WIDTH / 2;
    center.y = HEIGHT / 2;

    GLdouble sum = 0.0;
    for (int i = 0; i < 7; i++) {
        sum += ZHANBI[i];
    }

    GLdouble tempAngle = 0.0;
    for (int i = 0; i < 7; i++) {
        angle[i] = 2 * PI * ZHANBI[i] / sum;
        cumulativeAngle[i] = tempAngle;
        tempAngle += angle[i];
    }
    cumulativeAngle[7] = cumulativeAngle[0];

    for (int i = 0; i < 7; i++) {
        GLfloat color[3] = { 0.0, 0.0, 0.0 };
        switch (i) {
        case 1:
            color[0] = 0.7; color[1] = 0.6; color[2] = 0.7; break;
        case 2:
            color[0] = 0.5; color[1] = 0.4; color[2] = 0.7; break;
        case 3:
            color[0] = 0.3; color[1] = 0.2; color[2] = 0.6; break;
        case 4:
            color[0] = 0.3; color[1] = 0.2; color[2] = 0.4; break;
        case 5:
            color[0] = 0.4; color[1] = 0.2; color[2] = 0.215; break;
        case 6:
            color[0] = 0.5; color[1] = 0.2; color[2] = 0.3; break;
        default:
            break;
        }
        glColor3fv(color);

        glBegin(GL_TRIANGLE_FAN);
        glVertex2i(center.x, center.y);
        for (GLdouble j = 0; j < 1000000; j++) {
            GLdouble t = cumulativeAngle[i] + j * angle[i] / 1000000;
            glVertex2f(center.x - RADIUS * cos(t), center.y + RADIUS * sin(t));
        }
        glEnd();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    drawCircle();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(300, 150);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("圆盘");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
