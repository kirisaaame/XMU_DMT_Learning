#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <cmath>
#define STEP 0.05
#define WINDOW_WIDTH 800.0
#define WINDOW_HEIGHT 600.0
#define POINT_RADIUS 10.0
#define FRAME_RATE 60.0
using namespace std;

// 计算二项式系数
int binomialCoefficient(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n - k) k = n - k;
    
    int result = 1;
    for (int i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

typedef struct BezierSurface {
    vector<vector<vector<GLfloat>>> controlPoints;  // 三维控制点网格
    int uCount, vCount;                             // u方向和v方向的控制点数量
    
    BezierSurface(const vector<vector<GLfloat*>>& points) {
        vCount = points.size();
        uCount = points[0].size();
        
        for (const auto& row : points)
        {
            vector<vector<GLfloat>> controlRow;
            for (auto point : row) {
                vector<GLfloat> p(3);
                for (int i = 0; i < 3; i++)
                    p[i] = point[i];
                controlRow.push_back(p);
            }
            controlPoints.push_back(controlRow);
        }
    }

    // 计算曲面上的点
    void getPoint(float u, float v, GLfloat point[3]) {
        point[0] = point[1] = point[2] = 0.0f;
        int m = uCount - 1;
        int n = vCount - 1;
        
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                float blend = binomialCoefficient(m, i) * binomialCoefficient(n, j) 
                            * pow(u, i) * pow(1-u, m-i) 
                            * pow(v, j) * pow(1-v, n-j);
                for(int k = 0; k < 3; k++) {
                    point[k] += controlPoints[j][i][k] * blend;
                }
            }
        }
    }
}BezierSurface;
//检查是否和点接触
int checkControlPointHit(int x, int y) {
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);

    // 转换为归一化设备坐标
    float nx = (2.0f * x) / viewport[2] - 1.0f;
    float ny = 1.0f - (2.0f * y) / viewport[3];

    // 转换为世界坐标（简化版正交投影）
    float wx = nx * 5.0f; // 5是glOrtho的右边界
    float wy = ny * 5.0f * (float)viewport[3] / viewport[2];
    std::cout << wx << ' ' << wy << std::endl;
    for (int i = 0; i < BezierCurveCnt; ++i)
        for (int j=0;j<controlPointsCnt;)
        {
            float dx = wx - bezierSurface->controlPoints[i][j][0] / 2;
            float dy = wy - bezierSurface->controlPoints[i][j][1] / 2;
            if (dx * dx + dy * dy < POINT_RADIUS / 500) 
            {
                std::cout << bezierSurface->controlPoints[i][j][0] << bezierSurface->controlPoints[i][1]  << std::endl;
                return i;
            }
        }
    return -1;
}

// 全局变量
BezierSurface* bezierSurface = nullptr;
std::vector<GLfloat> surfacePoints; // 存储已计算的曲面点
static float u = 0.0, v = 0.0;
static float animationSpeed = 0.02f; // 控制动画速度
static bool animationComplete = false;

/*------------------用户定义部分-----------------------*/
    // 定义控制点坐标
GLfloat points[3][3][3] = {
    {{-3.0f, -3.0f, 0.0f}, {-1.0f, -3.0f, 2.0f}, {1.0f, -3.0f, 2.0f}},
    {{-3.0f, -1.0f, 2.0f}, {-1.0f, -1.0f, 4.0f}, {1.0f, -1.0f, 4.0f}},
    {{-3.0f, 1.0f, 2.0f}, {-1.0f, 1.0f, 4.0f}, {1.0f, 1.0f, 4.0f} },
};
int BezierCurveCnt = 3;
int ControlPointsCnt = 3;
/*------------------------------------------------------*/

// 初始化贝塞尔曲面控制点
void initBezierSurface() {
    // 创建一个4x4的控制点网格
    vector<vector<GLfloat*>> controlPointsGrid;
   
    
    for (int i = 0; i <BezierCurveCnt ; i++) {
        vector<GLfloat*> row;
        for (int j = 0; j < ControlPointsCnt; j++) {
            row.push_back(points[i][j]);
        }
        controlPointsGrid.push_back(row);
    }
    
    bezierSurface = new BezierSurface(controlPointsGrid);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // 绘制控制点网格
    glPointSize(8.0f);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    for (int i = 0; i < bezierSurface->vCount; ++i) {
        for (int j = 0; j < bezierSurface->uCount; ++j) {
            glVertex3fv(bezierSurface->controlPoints[i][j].data());
        }
    }
    glEnd();

    // 绘制控制线网格
    glColor3f(0.7, 0.7, 0.7);
    glLineWidth(1.0f);
    
    // 绘制u方向的线
    for (int i = 0; i < bezierSurface->vCount; ++i) {
        glBegin(GL_LINE_STRIP);
        for (int j = 0; j < bezierSurface->uCount; ++j) {
            glVertex3fv(bezierSurface->controlPoints[i][j].data());
        }
        glEnd();
    }
    
    // 绘制v方向的线
    for (int j = 0; j < bezierSurface->uCount; ++j) {
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < bezierSurface->vCount; ++i) {
            glVertex3fv(bezierSurface->controlPoints[i][j].data());
        }
        glEnd();
    }

    // 计算当前曲面点并添加到曲面点集
    GLfloat currentPoint[3];
    bezierSurface->getPoint(u, v, currentPoint);
    surfacePoints.push_back(currentPoint[0]);
    surfacePoints.push_back(currentPoint[1]);
    surfacePoints.push_back(currentPoint[2]);

    // 绘制完整的贝塞尔曲面（以点的形式）
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(3.0f);
    glBegin(GL_POINTS);
    for (size_t i = 0; i < surfacePoints.size(); i += 3) {
        glVertex3f(surfacePoints[i], surfacePoints[i + 1], surfacePoints[i + 2]);
    }
    glEnd();

    // 绘制当前动画点
    glColor3f(0.0, 1.0, 0.0);
    glPointSize(10.0f);
    glBegin(GL_POINTS);
    glVertex3f(currentPoint[0], currentPoint[1], currentPoint[2]);
    glEnd();

    // 更新动画参数
    if (!animationComplete) {
        u += animationSpeed;
        if (u > 1.0f) {
            u = 0.0f;
            v += animationSpeed;
            if (v > 1.0f) {
                v = 1.0f;
                u = 1.0f;
                animationComplete = true;
            }
        }
    }

    glutSwapBuffers();
}

void init(void)
{
    glClearColor(0.949, 0.949, 0.949, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    
    // 初始化贝塞尔曲面
    initBezierSurface();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27: // ESC键
        exit(0);
        break;
    case 'r': // 重置动画
    case 'R':
        u = 0.0f;
        v = 0.0f;
        animationComplete = false;
        surfacePoints.clear();
        break;
    case ' ': // 空格键暂停/继续
        if (animationComplete) {
            u = 0.0f;
            v = 0.0f;
            animationComplete = false;
            surfacePoints.clear();
        }
        break;
    }
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            selectedPoint = checkControlPointHit(x, y);
            std::cout << "selected point index: " << selectedPoint << std::endl;
        }
        else {
            selectedPoint = -1; // 释放鼠标时取消选择
        }
    }
    glutPostRedisplay();
}
void motion(int x, int y) {
    if (selectedPoint != -1) {
        GLint viewport[4];
        glGetIntegerv(GL_VIEWPORT, viewport);

        // 转换为归一化设备坐标
        float nx = (2.0f * x) / viewport[2] - 1.0f;
        float ny = 1.0f - (2.0f * y) / viewport[3];

        // 转换为世界坐标（简化版正交投影）
        float wx = nx * 5.0f; // 5是glOrtho的右边界
        float wy = ny * 5.0f * (float)viewport[3] / viewport[2];

        controlPoints[selectedPoint][0] = wx * 2;
        controlPoints[selectedPoint][1] = wy * 2;
        // 保持z值不变
        glutPostRedisplay();
    }
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(1.0/FRAME_RATE, timer, 0); // 约60FPS
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("1");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(1.0/FRAME_RATE, timer, 0);
    glutMainLoop();
    return 0;
}

