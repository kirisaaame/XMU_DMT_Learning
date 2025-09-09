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

typedef struct BezierCurve {
    vector<vector<GLfloat>> controlPoints;  // 控制点数组，每个点用vector<GLfloat>表示
    int controlPointsCnt;                   // 控制点数量
    
    BezierCurve(const vector<GLfloat*>& points) {
        controlPointsCnt = points.size();
        for (auto point : points) {
            vector<GLfloat> p(3);
            for (int i = 0; i < 3; i++)
                p[i] = point[i];
            controlPoints.push_back(p);
        }
    }

    // 计算曲线上的点
    void getPoint(float t, GLfloat point[3]) {
        point[0] = point[1] = point[2] = 0.0f;
        int n = controlPointsCnt - 1;
        
        for (int i = 0; i <= n; i++) {
            float blend = binomialCoefficient(n, i) * pow(t, i) * pow(1-t, n-i);
            for(int j = 0; j < 3; j++) {
                point[j] += controlPoints[i][j] * blend;
            }
        }
    }
} BezierCurve;

typedef struct BezierSurface {
    vector<vector<vector<GLfloat>>> controlPoints;  // 三维控制点网格
    int uCount, vCount;                             // u方向和v方向的控制点数量
    
    BezierSurface(const vector<vector<GLfloat*>>& points) {
        vCount = points.size();
        uCount = points[0].size();
        
        for (const auto& row : points) {
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
} BezierSurface;

// 全局变量
BezierSurface* bezierSurface = nullptr;
std::vector<GLfloat> surfacePoints; // 存储已计算的曲面点
static float u = 0.0, v = 0.0;
static float animationSpeed = 0.02f; // 控制动画速度
static bool animationComplete = false;
/*------------------用户定义部分-----------------------*/

    // 定义控制点坐标
GLfloat points[4][4][3] = {
     {{-3.0f, -3.0f, 0.0f}, {-1.0f, -3.0f, 2.0f}, {1.0f, -3.0f, 2.0f}, {3.0f, -3.0f, 0.0f}},
        {{-3.0f, -1.0f, 2.0f}, {-1.0f, -1.0f, 4.0f}, {1.0f, -1.0f, 4.0f}, {3.0f, -1.0f, 2.0f}},
        {{-3.0f, 1.0f, 2.0f}, {-1.0f, 1.0f, 4.0f}, {1.0f, 1.0f, 4.0f}, {3.0f, 1.0f, 2.0f}},
        {{-3.0f, 3.0f, 0.0f}, {-1.0f, 3.0f, 2.0f}, {1.0f, 3.0f, 2.0f}, {3.0f, 3.0f, 0.0f}}

};
int BezierCurveCnt = 4;
int ControlPointsCnt = 4;

/*------------------------------------------------------*/
std::pair<int, int>selectedPoint;
std::pair<int,int> checkControlPointHit(int x, int y) {
    GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];
    GLfloat winX, winY, winZ;
    GLdouble posX, posY, posZ;
    
    glGetIntegerv(GL_VIEWPORT, viewport);
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    
    winX = (float)x;
    winY = (float)viewport[3] - (float)y; // 翻转Y坐标
    glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
    
    // 将屏幕坐标转换为世界坐标
    gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);
    
    std::cout << "Mouse screen: (" << x << ", " << y << ") -> World: (" << posX << ", " << posY << ", " << posZ << ")" << std::endl;
    
    // 检查每个控制点
    for (int i = 0; i < BezierCurveCnt; ++i) {
        for (int j = 0; j < ControlPointsCnt; ++j) {
            // 获取控制点的世界坐标
            GLfloat controlX = bezierSurface->controlPoints[i][j][0];
            GLfloat controlY = bezierSurface->controlPoints[i][j][1];
            GLfloat controlZ = bezierSurface->controlPoints[i][j][2];
            
            // 计算距离（只考虑X和Y坐标，因为Z坐标在透视投影中可能不准确）
            float dx = posX - controlX;
            float dy = posY - controlY;
            float distance = sqrt(dx * dx + dy * dy);
            
            // 设置点击阈值（可以根据需要调整）
            float threshold = POINT_RADIUS/100.0;
            
            if (distance < threshold) {
                std::cout << "Hit control point [" << i << "][" << j << "] at (" 
                         << controlX << ", " << controlY << ", " << controlZ 
                         << ") with distance " << distance << std::endl;
                return {i, j};
            }
        }
    }
    
    return {-1, -1};
}
// 初始化贝塞尔曲面控制点
void initBezierSurface() {
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
            std::cout << "selected point index: " << selectedPoint.first << ' '<< selectedPoint.second << std::endl;
        }
        else {
            selectedPoint = { -1,-1 }; // 释放鼠标时取消选择
        }
    }
    glutPostRedisplay();
}

void motion(int x, int y) {
    if (selectedPoint.first != -1 && selectedPoint.second != -1) {
        GLint viewport[4];
        GLdouble modelview[16];
        GLdouble projection[16];
        GLfloat winX, winY, winZ;
        GLdouble posX, posY, posZ;
        
        glGetIntegerv(GL_VIEWPORT, viewport);
        glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
        glGetDoublev(GL_PROJECTION_MATRIX, projection);
        
        winX = (float)x;
        winY = (float)viewport[3] - (float)y;
        
        // 尝试读取深度值，如果失败则使用默认值
        glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
        
        // 检查深度值是否有效，如果无效则使用控制点当前的Z坐标
        if (winZ == 1.0f || winZ == 0.0f) {
            // 深度值无效，使用控制点当前的Z坐标
            winZ = bezierSurface->controlPoints[selectedPoint.first][selectedPoint.second][2];
            // 将世界坐标的Z值转换为窗口坐标的Z值
            
            GLdouble tempX, tempY, tempZ;
            gluProject(0, 0, winZ, modelview, projection, viewport, &tempX, &tempY, &tempZ);
            winZ = (GLfloat)tempZ;
        }
        
        // 将屏幕坐标转换为世界坐标
        if (gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ)) {
            // 添加边界限制，防止控制点飞出窗口
            GLdouble maxX = 10.0f, maxY = 10.0f, maxZ = 10.0f;
            GLdouble minX = -10.0f, minY = -10.0f, minZ = -5.0f;
            
            posX = std::max(minX, std::min(maxX, posX));
            posY = std::max(minY, std::min(maxY, posY));
            posZ = std::max(minZ, std::min(maxZ, posZ));
            
            // 更新选中的控制点位置
            bezierSurface->controlPoints[selectedPoint.first][selectedPoint.second][0] = (GLfloat)posX;
            bezierSurface->controlPoints[selectedPoint.first][selectedPoint.second][1] = (GLfloat)posY;
            bezierSurface->controlPoints[selectedPoint.first][selectedPoint.second][2] = (GLfloat)posZ;
            
            std::cout << "Moving control point [" << selectedPoint.first << "][" << selectedPoint.second 
                     << "] to (" << posX << ", " << posY << ", " << posZ << ")" << std::endl;
        } else {
            std::cout << "Failed to unproject coordinates" << std::endl;
        }
        
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
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutTimerFunc(1.0/FRAME_RATE, timer, 0);
    glutMainLoop();
    return 0;
}

