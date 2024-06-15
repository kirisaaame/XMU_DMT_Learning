//A.1  Sierpinski镂垫程序
/* two-dimensional Sierpinski gasket             */
/* generated using randomly selected vertices  */
/* and bisection                                    */
#include <GL/glut.h>
#include <Windows.h> 
#include <ctime>
/*you may have to change the include to<glut.h> or
elsewhere depending on where it is stored on your system */
/* glut.h usually has included for gl.h and glu.h */

GLfloat angle = 0.0;//旋转角度
GLfloat size = 1.0;//缩放比例

void myinit(void)
{
    /* attributes */
    glClearColor(1.0, 1.0, 1.0, 1.0); /* white background */
    //glColor3f(1.0, 0.0, 0.0); /* draw in red */
    /* set up viewing */
    /* 50.0 × 50.0 camera coordinate window with origin lower left */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 50.0, 0.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
}

void display(void)
{
    /* A triangle */
    GLfloat vertices[3][2] = { {0.0,0.0},{25.0,50.0},{50.0,0.0} };

    int i, j, k;
    int rand();       /* standard random number generator */
    GLfloat p[2] = { 7.5,5.0 };  /* an arbitrary initial point inside
                              traingle */
    glClear(GL_COLOR_BUFFER_BIT);  /* clear the window */

    glPushMatrix(); // 保存当前模型视图矩阵状态

    // 应用整体的旋转和缩放变换
    glRotatef(angle, 0.0, 0.0, 0.1); // 设定旋转轴
    glScalef(size, size, 1.0); // 缩放

    glBegin(GL_POINTS);
    /* compute and plots 5000 new points */
    for (k = 0; k < 500000; k++)
    {
        j = rand() % 3; /* pick a vertex at random */
        /* Compute point halfway between selected vertex and old point */
        p[0] = (p[0] + vertices[j][0]) / 2.0;
        p[1] = (p[1] + vertices[j][1]) / 2.0;

        //随机选择颜色
        GLfloat blue = rand() % 100 / (float)100;
        GLfloat red = rand() % 100 / (float)100;
        GLfloat green = rand() % 100 / (float)100;
        glColor3f(red, green, blue);

        glVertex2fv(p);
       

    }
    glEnd();
    glPopMatrix();
    glFlush(); /* clear buffers */
}

void update(int value)
{
    angle += 0.5; // 每次更新旋转角度
    if (angle > 360)
        angle -= 360;

    size+= 0.001; // 每次更新缩放比例
    if (size > 1.5)
        size = 1.0;

    glutPostRedisplay(); // 重新绘制
    glutTimerFunc(25, update, 0); // 设置25毫秒后再次调用update函数
}

void main(int argc, char** argv)
{
    srand(time(NULL));//按照时间设置随机种子

    /* Standard GLUT initialization */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); /* default, not
                                                 needed */
    glutInitWindowSize(500, 500); /* 500 × 500 pixel window */
    glutInitWindowPosition(0, 0); /* place window top left on display
                                 */
    glutCreateWindow("Sierpinski Gasket"); /* window title */
    glutDisplayFunc(display);
    /* display callback invoked when window opened */
    myinit(); /* set attributes */
    glutTimerFunc(25, update, 0); // 每25毫秒调用一次update函数
    glutMainLoop(); /* enter event loop */
}