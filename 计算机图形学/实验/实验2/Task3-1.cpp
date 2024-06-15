#include <GL/glut.h>  // 这个头文件是用于定义OpenGL的常量和数据类型
#include <cmath>

const GLfloat PI = 3.14159265359f;
GLfloat slices = 40.0;//经线数量
GLfloat stacks = 40.0;//纬线数量
GLfloat radius = 20.0;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);//设置颜色为红色

    glShadeModel(GL_FLAT);

    glEnable(GL_DEPTH_TEST);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glLoadIdentity();

    // 设置视角
    gluLookAt(0.0, 0.0, 50.0,  
        0.0, 0.0, 0.0, 
        0.0, 1.0, 0.0); 

    glBegin(GL_LINES);  // 开始绘制线段
    for (int i = 0; i < slices; ++i) {
        for (int j = 0; j < stacks; ++j) {
            float theta1 = i * PI *2/ slices;
            float theta2 = (i + 1) * PI *2/ slices;//两个经度点
            float phi1 = j * PI / stacks;
            float phi2 = (j + 1) * PI / stacks;//两个纬度点

            // 连接纬度
            glVertex3f(radius * sin(theta1) * sin(phi1), radius * cos(phi1), radius * cos(theta1) * sin(phi1));
            glVertex3f(radius * sin(theta2) * sin(phi1), radius * cos(phi1), radius * cos(theta2) * sin(phi1));

            // 连接经度
            glVertex3f(radius * sin(theta1) * sin(phi1), radius * cos(phi1), radius * cos(theta1) * sin(phi1));
            glVertex3f(radius * sin(theta1) * sin(phi2), radius * cos(phi2), radius * cos(theta1) * sin(phi2));

           
        }
    }
    glEnd();  // 结束绘制

    glutSwapBuffers(); 
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h); 

    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluPerspective(45.0, (float)w / (float)h, 1.0, 100.0); 
    glMatrixMode(GL_MODELVIEW); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); 
    glutCreateWindow("线框球体"); 
    init();
    glutDisplayFunc(display); 
    glutReshapeFunc(reshape); 
    glutMainLoop();

    return 0;
}
