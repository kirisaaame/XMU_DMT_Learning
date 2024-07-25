#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <GL/glut.h>
#include "OBJ.h"

GLfloat eye[3] = { 0.0, 0.0, 2.0 };
GLfloat at[3] = { 0.0, 0.0, 0.0 };
GLfloat up[3] = { 0.0, 1.0, 0.0 };

GLfloat ambient[] = { 0.2, 0.2, 0.2, 1.0 };
GLfloat diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat specular[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat shininess = 65.0;
GLfloat light_position[] = { 1.0 , 1.0 , 1.0 , 0.0 };
float lx = 1;

static float angleX = 0.0, angleY = 0.0;
static int lastX = -1, lastY = -1;
static int isDragging = 0;

int rx = 0, ry = 0, rz = 0;
float px = 0, py = 0, pz = 0;
float scale = 1;
float pointSize = 2.0;
bool displayNormals = false;
bool displayColors = false;

Mesh* pModel = NULL;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (pModel == NULL) {
        pModel = readPLY("default_original.ply");  
        if (pModel != NULL) {
            pModel->unitize();
            pModel->compute_normal();
        }
    }

    if (pModel != NULL) {
        light_position[0] = lx;
        
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);

        glPushMatrix();
        glScalef(scale, scale, scale);
        glRotatef(angleX, 1, 0, 0);
        glRotatef(angleY, 0, 1, 0);
        glTranslatef(px, py, pz);
        glPointSize(pointSize);
        drawMesh(pModel, displayNormals, displayColors);
        glPopMatrix();
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
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void redisplay_all(void)
{
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            lastX = x;
            lastY = y;
            isDragging = 1;
        }
        else {
            isDragging = 0;
        }
    }
    if (button == 3) { // Scroll up
        if (glutGetModifiers() == GLUT_ACTIVE_CTRL) {
            pointSize += 1;
        }
        else {
            scale += 0.1;
        }
        redisplay_all();
    }
    if (button == 4) { // Scroll down
        if (glutGetModifiers() == GLUT_ACTIVE_CTRL) {
            pointSize -= 1;
            if (pointSize < 1.0) pointSize = 1.0;
        }
        else {
            scale -= 0.1;
            if (scale < 0.1) scale = 0.1;
        }
        redisplay_all();
    }
}

void motion(int x, int y) {
    if (isDragging) {
        angleX += (y - lastY);
        angleY += (x - lastX);
        lastX = x;
        lastY = y;
        redisplay_all();
    }
}

void menu(int option) {
    switch (option) {
    case 1:
        displayNormals = !displayNormals;
        break;
    case 2:
        displayColors = !displayColors;
        break;
    default:
        break;
    }
    redisplay_all();
}

void createMenu() {
    glutCreateMenu(menu);
    glutAddMenuEntry("Toggle Normals", 1);
    glutAddMenuEntry("Toggle Colors", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char** argv)
{
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(512, 512);
    glutInitWindowPosition(50, 50);
    glutInit(&argc, argv);
    glutCreateWindow("PLY Point Cloud Viewer");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    createMenu();

    redisplay_all();

    glutMainLoop();

    return 0;
}
