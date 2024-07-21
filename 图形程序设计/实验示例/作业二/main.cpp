#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string>
#include <vector>
#include <GL/glew.h>
#include <GL/glut.h>
#include "OBJ.h"
#include<iostream>

// 全局变量定义
GLfloat eye[3] = { 0.0, 0.0, 2.0 };
GLfloat at[3] = { 0.0, 0.0, 0.0 };
GLfloat up[3] = { 0.0, 1.0, 0.0 };

GLfloat ambient[] = { 0.2, 0.2, 0.2, 1.0 };//环境光
GLfloat diffuse[] = { 0.8, 0.8, 0.8, 1.0 };//漫反射
GLfloat specular[] = { 0.0, 0.0, 0.0, 1.0 };//镜面反射
GLfloat shininess = 65.0;//高光指数
GLfloat light_position[] = { 1.0 , 1.0 , 1.0 , 1.0 };//光源位置
float lx = 1;
std::vector<std::string> filename = { "Bunny.obj","Cat.obj","Dog.obj","Duck.obj","Tiger.obj" };

static float angleX = 0.0, angleY = 0.0;
int rx = 0, ry = 0, rz = 0;
float px = 0, py = 0, pz = 0;
float scale = 1;
bool light = true;

GLuint tigerTextureID;
GLuint backgroundTexture;
Mesh* pModel = NULL;
// 菜单选项的标识符
GLuint loadTexture(const char* filename) {
    GLuint textureID;
    glGenTextures(1, &textureID);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char* data = stbi_load(filename, &width, &height, &nrChannels, 0);
    if (data) {
        GLenum format;
        if (nrChannels == 1)
            format = GL_RED;
        else if(nrChannels == 2)
            format = GL_RG;
        else if (nrChannels == 3)
            format = GL_RGB;
        else if (nrChannels == 4)
            format = GL_RGBA;
        else {
            std::cerr << "Unknown number of channels: " << nrChannels << std::endl;
            stbi_image_free(data);
            return 0;
        }

        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cout<< "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    return textureID;
}
void drawBackground(GLuint textureID) {
    glDisable(GL_DEPTH_TEST); // 禁用深度测试，确保背景总是被绘制在最后面
    glDisable(GL_LIGHTING);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0); glVertex2f(0.0, 0.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 0.0); glVertex2f(0.0, 1.0);
    glEnd();

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_DEPTH_TEST); // 重新启用深度测试
}

void display(void)
{
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eye[0], eye[1], eye[2], at[0], at[1], at[2], up[0], up[1], up[2]);
    glClearColor(0.2, 0.2, 0.2, 0.0);
    drawBackground(backgroundTexture);

    glEnable(GL_DEPTH_TEST);
    for (int i = 0; i < 5; i++)
    {
        if (pModel != NULL) {
            delete pModel; // 假设Mesh的析构函数会正确释放所有分配的资源
            pModel = NULL; // 避免悬挂指针
        }
        pModel = readOBJ(filename[i].c_str());
        if (pModel != NULL)
        {
            pModel->unitize();        // 缩放到合适的尺寸
            pModel->compute_normal(); // 计算法线
            if (light)
            {
                glEnable(GL_LIGHTING);
                glEnable(GL_LIGHT0);
            }
			else
            {
				glDisable(GL_LIGHTING);
				glDisable(GL_LIGHT0);
            }
            light_position[0] = lx;
            glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
            glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
            glMaterialf(GL_FRONT, GL_SHININESS, shininess);
            glLightfv(GL_LIGHT0, GL_POSITION, light_position);
            glPushMatrix();
            switch (i) {
            case 0:  // Bunny
                px = 1.0; pz = -1.5; scale = 0.5;angleX = 0; angleY = 0;
                glTranslatef(px, py, pz);
                glRotatef(angleX, rx, 1, rz);
                glRotatef(angleY, 1, ry, rz);
                glScalef(scale, scale, scale);
                break;
            case 1:  // Cat
                px = 2.5; py = -1; scale = 0.5; angleX = 90; angleY = -90;
                glTranslatef(px, py, pz);
                glRotatef(angleX, rx, 1, rz);
                glRotatef(angleY, 1, ry, rz);
                glScalef(scale, scale, scale);
                break;
            case 2:  // Dog
                px = -1.5; py = -1; pz = -0.5; scale = 4; angleY = -90;
                glTranslatef(px, py, pz);
                glRotatef(angleX, rx, 1, rz);
                glRotatef(angleY, 1, ry, rz);
                glScalef(scale, scale, scale);
                break;
            case 3:  // Duck
                px = -1.5; py = -0.5; pz = -1.5; scale = 0.2; angleX = 0; angleY = -90;
                glTranslatef(px, py, pz);
                glRotatef(angleX, rx, 1, rz);
                glRotatef(angleY, 1, ry, rz);
                glScalef(scale, scale, scale);
                break;
            case 4:  // Tiger
                px = 0.0; py = -1; scale = 1.2; angleX = 150; angleY = -90;
                glTranslatef(px, py, pz);
                glRotatef(angleX, rx, 1, rz);
                glRotatef(angleY, 1, ry, rz);
                glScalef(scale, scale, scale);
                break;
            default:
                break;
            }

            if (i == 4) {
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, tigerTextureID);
            }
            else {
                glDisable(GL_TEXTURE_2D);
            }

            drawMesh(pModel);

            glPopMatrix();
        }
        else
        {
            printf("Failed to read the model\n");
        }
    }

    glFlush();
    glutSwapBuffers();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)width / height, 1.0, 8.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eye[0], eye[1], eye[2], at[0], at[1], at[2], up[0], up[1], up[2]);
    glClearColor(0.2, 0.2, 0.2, 0.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void redisplay_all(void)
{
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    float speed = 0.1; // 控制移动速度
    float forward[3] = { at[0] - eye[0], at[1] - eye[1], at[2] - eye[2] }; // 观察方向
    float right[3] = { forward[2], 0, -forward[0] }; // 右方向，仅在xz平面计算

    // 标准化向量
    float forwardLength = sqrt(forward[0] * forward[0] + forward[2] * forward[2]);
    forward[0] /= forwardLength;
    forward[2] /= forwardLength;

    float rightLength = sqrt(right[0] * right[0] + right[2] * right[2]);
    right[0] /= rightLength;
    right[2] /= rightLength;

    switch (key) {
    case 'w': // 前进
        eye[0] += forward[0] * speed;
        eye[2] += forward[2] * speed;
        break;
    case 's': // 后退
        eye[0] -= forward[0] * speed;
        eye[2] -= forward[2] * speed;
        break;
    case 'a': // 左移
        eye[0] -= right[0] * speed;
        eye[2] -= right[2] * speed;
        break;
    case 'd': // 右移
        eye[0] += right[0] * speed;
        eye[2] += right[2] * speed;
        break;
    case 'q': // 上升
        eye[1] += speed;
        break;
    case 'e': // 下降
        eye[1] -= speed;
        break;
    }

    glutPostRedisplay();
}
void light_menu(int id)
{
if (id == 2)
	{
		light = true;
	}
	else if (id == 3)
	{
		light = false;
	}
    glutPostRedisplay();
}
void color_menu(int id)
{
    if (id == 4)
    {
        ambient[0] = 1.0;
        ambient[1] = 0.0;
        ambient[2] = 0.0;
	}
	else if(id==5)
	{
        ambient[0] = 0.0;
        ambient[1] = 1.0;
        ambient[2] = 0.0;
	}
	else if(id==6)
	{
        ambient[0] = 0.0;
        ambient[1] = 0.0;
        ambient[2] = 1.0;
	}
	else if(id==7)
	{
        std::cout << "请输入颜色值（0-1）" << std::endl;
        std::cout << "R:";
        std::cin >> ambient[0];
        std::cout << "G:";
        std::cin >> ambient[1];
        std::cout << "B:";
        std::cin >> ambient[2];
    }
    glutPostRedisplay();
}
void right_menu(int id)
{
    if (id == 1) exit(0);
    glutPostRedisplay();
}
void makemenu(void)
{
    int light = glutCreateMenu(light_menu);
    glutAddMenuEntry("On", 2);
    glutAddMenuEntry("Off", 3);
    int color = glutCreateMenu(color_menu);
    glutAddMenuEntry("Red", 4);
    glutAddMenuEntry("Green", 5);
    glutAddMenuEntry("Blue", 6);
    glutAddMenuEntry("User_defined", 7);

    glutCreateMenu(right_menu);
    glutAddSubMenu("Light", light);
    glutAddSubMenu("Color", color);
    glutAddMenuEntry("Quit", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void init(void)
{
    makemenu();
   
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(512, 512);
    glutCreateWindow("OBJ LOAD");

    glewInit();
    tigerTextureID = loadTexture("TigerTexture.bmp");
    backgroundTexture = loadTexture("Background.jpg");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();

    return 0;
}
