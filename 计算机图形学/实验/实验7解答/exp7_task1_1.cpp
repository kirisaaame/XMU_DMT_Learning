#include <GL/glut.h>
#include <iostream>
#include <vector>
#define STEP 0.001
using namespace std;
GLfloat controlPoints[][3] = {
    {0, 0, -10},
    {1, 1, -10},
    {2, -1, -10}
};

std::vector<GLfloat> curvePoints; // 存储已计算的曲线点
static float t = 0.0;
static float animationSpeed = 0.01f; // 控制动画速度

void calculateBezierPoint(float t, GLfloat point[3]) {
    GLfloat p10[3] = {
        t * controlPoints[0][0] + (1 - t) * controlPoints[1][0],
        t * controlPoints[0][1] + (1 - t) * controlPoints[1][1],
        t * controlPoints[0][2] + (1 - t) * controlPoints[1][2]
    };
    GLfloat p11[3] = {
        t * controlPoints[1][0] + (1 - t) * controlPoints[2][0],
        t * controlPoints[1][1] + (1 - t) * controlPoints[2][1],
        t * controlPoints[1][2] + (1 - t) * controlPoints[2][2]
    };
    point[0] = t * p10[0] + (1 - t) * p11[0];
    point[1] = t * p10[1] + (1 - t) * p11[1];
    point[2] = t * p10[2] + (1 - t) * p11[2];
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 绘制控制点
    glPointSize(8.0f);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    for (int i = 0; i < 3; ++i) {
        glVertex3fv(controlPoints[i]);
    }
    glEnd();

    // 绘制控制线
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 3; ++i) {
        glVertex3fv(controlPoints[i]);
    }
    glEnd();

    // 计算当前点并添加到曲线点集
    GLfloat currentPoint[3];
    calculateBezierPoint(t, currentPoint);
    curvePoints.push_back(currentPoint[0]);
    curvePoints.push_back(currentPoint[1]);
    curvePoints.push_back(currentPoint[2]);

    // 绘制完整的贝塞尔曲线
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_STRIP);
    for (size_t i = 0; i < curvePoints.size(); i += 3) {
        glVertex3f(curvePoints[i], curvePoints[i + 1], curvePoints[i + 2]);
    }
    glEnd();

    // 更新t值
    t += animationSpeed;
    if (t > 1.0f) {
        t = 1.0f; // 保持在终点
    }

    glutSwapBuffers();
}
void init(void)
{
	glClearColor(0.949, 0.949, 0.949, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);

	glShadeModel(GL_SMOOTH);
	
}
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, .0,  // 相机位置
        0.0, 0.0, -10.0, // 观察点
        0.0, 1.0, 0.0);  // 上向量
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(0);
		break;
	}
}
void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // 约60FPS
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
    glutTimerFunc(16,timer,0);
     GLfloat firstPoint[3];
    calculateBezierPoint(0.0f, firstPoint);
    curvePoints.push_back(firstPoint[0]);
    curvePoints.push_back(firstPoint[1]);
    curvePoints.push_back(firstPoint[2]);
	glutMainLoop();
	return 0;
}

