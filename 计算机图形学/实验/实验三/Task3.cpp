#include <GL/glut.h>
#include<math.h>

#define DEG_TO_RAD 0.017453
const GLfloat RR = 2.0; //camera rad
GLfloat beta = 0;
GLfloat camerax = 0.0, cameray = 0.0, cameraz = 2.0; // 相机位置
GLfloat cameraSpeed = 0.1;                          // 相机移动速度
bool isLocked = false;                             // 相机是否锁定

GLfloat brassAmbient[] = { 0.33, 0.22, 0.03, 1.0 };
GLfloat brassDiffuse[] = { 0.78, 0.57, 0.11, 1.0 };
GLfloat brassSpecular[] = { 0.99, 0.91, 0.81, 1.0 };
GLfloat brassShininess[] = { 27.8 };

GLfloat plasticAmbient[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat plasticDiffuse[] = { 0.5, 0.0, 0.0, 1.0 };
GLfloat plasticSpecular[] = { 0.7, 0.6, 0.6, 1.0 };
GLfloat plasticShininess[] = { 32.0 };

GLfloat whiteAmbient[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat whiteDiffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat whiteSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat whiteShininess[] = { 100.0 };

//材质列表
enum MaterialType { BRASS, PLASTIC, WHITE };
MaterialType currentMaterial = BRASS;

// 光源颜色
GLfloat whiteLight[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat coloredLight[] = { 1.0, 0.5, 0.5, 1.0 };

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	GLfloat mat_specular[] = { 1.0 , 0.0 , 0.0 , 1.0 };
	GLfloat mat_shininess[] = { 100.0 };

	float light_position[] = { 100.0f, 100.0f, 10.0f, 0.0f };

	GLfloat white_light[] = { 1.0,1.0,1.0,1.0 };
	GLfloat model_ambient[] = { 0.1,0.1,0.1,1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);        //定义光源的位置
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);     //使用镜面材质颜色
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);   //使用光泽度

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);        //定义光源的位置
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);            //定义散射光为白色
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);           //定义镜面光为白色
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);   //光照模型参数：全局环境光

	glEnable(GL_LIGHTING); //驱动光源
	glEnable(GL_LIGHT0);   //启动特定光源

}
//材质选择
void setMaterial(MaterialType material)
{
	switch (material)
	{
	case BRASS:
		glMaterialfv(GL_FRONT, GL_AMBIENT, brassAmbient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, brassDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, brassSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, brassShininess);
		break;
	case PLASTIC:
		glMaterialfv(GL_FRONT, GL_AMBIENT, plasticAmbient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, plasticDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, plasticSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, plasticShininess);
		break;
	case WHITE:
		glMaterialfv(GL_FRONT, GL_AMBIENT, whiteAmbient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, whiteDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, whiteSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, whiteShininess);
		break;
	}
}
//光源设置
void setLight(GLfloat* lightColor)
{
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightColor);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camerax, cameray, cameraz,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);

	glRotatef(beta, 0.0, 1.0, 0.5); // 在绘制时让正方体绕定轴旋转

	// 设置材质
	setMaterial(currentMaterial);

	// 绘制立方体的每个面
	glBegin(GL_QUADS);
	// face A
	glNormal3f(0.0, 0.0, 1.0); // 设置法向量
	glVertex3f(-1, 1, 1);
	glVertex3f(-1, -1, 1);
	glVertex3f(1, -1, 1);
	glVertex3f(1, 1, 1);

	// face B
	glNormal3f(0.0, 0.0, -1.0); // 设置法向量
	glVertex3f(-1, 1, -1);
	glVertex3f(-1, -1, -1);
	glVertex3f(1, -1, -1);
	glVertex3f(1, 1, -1);

	// face C
	glNormal3f(0.0, 1.0, 0.0); // 设置法向量
	glVertex3f(-1, 1, 1);
	glVertex3f(-1, 1, -1);
	glVertex3f(1, 1, -1);
	glVertex3f(1, 1, 1);

	// face D
	glNormal3f(0.0, -1.0, 0.0); // 设置法向量
	glVertex3f(-1, -1, 1);
	glVertex3f(-1, -1, -1);
	glVertex3f(1, -1, -1);
	glVertex3f(1, -1, 1);

	// face E
	glNormal3f(1.0, 0.0, 0.0); // 设置法向量
	glVertex3f(1, 1, 1);
	glVertex3f(1, -1, 1);
	glVertex3f(1, -1, -1);
	glVertex3f(1, 1, -1);

	// face F
	glNormal3f(-1.0, 0.0, 0.0); // 设置法向量
	glVertex3f(-1, 1, 1);
	glVertex3f(-1, -1, 1);
	glVertex3f(-1, -1, -1);
	glVertex3f(-1, 1, -1);

	glEnd();

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);

	glutSwapBuffers();
}


void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	//以下语句设置相机投影参数
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//以下两句二选一，看看效果
	//glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glOrtho(-4.0, 4.0, -4.0, 4.0, -4.0, 4.0);
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 0.3, 10.0);


	//以下语句设置相机和物体的相对方位
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}


void idlefunc()
{
	//改变动画参数
	beta += 0.05;
	if (beta > 360) beta -= 360;
	glutPostRedisplay();
}


void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w': // 前进
		camerax += cameraSpeed;
		cameray += cameraSpeed;
		cameraz += cameraSpeed;
		break;
	case 's': // 后退
		camerax -= cameraSpeed;
		cameray -= cameraSpeed;
		cameraz -= cameraSpeed;
		break;
	case 'a': // 左移
		camerax -= cameraSpeed;
		cameraz += cameraSpeed;
		break;
	case 'd': // 右移
		camerax += cameraSpeed;
		cameraz -= cameraSpeed;
		break;
	case 'q': // 上升
		cameray += cameraSpeed;
		break;
	case 'e': // 下降
		cameray -= cameraSpeed;
		break;
	case 'L': // 锁定相机
		isLocked = !isLocked;
	case 'b': // 设置黄铜材质
		currentMaterial = BRASS;
		break;
	case 'n': // 设置红色塑料材质
		currentMaterial = PLASTIC;
		break;
	case 'm': // 设置白色光亮材质
		currentMaterial = WHITE;
		break;
	case 'o': // 使用白色光源
		setLight(whiteLight);
		break;
	case 'p': // 使用彩色光源
		setLight(coloredLight);
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)
{
	/*
		1. draw cube:
			draw each face with 2 triangles
		2. adjust view point:
			modify params in gluLookAt
		3. try to move camera:
			3.1 open depth
				glEnable(GL_DEPTH_TEST);
				glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			3.2 change viewpoint dynamicly
				3.2.1 load camera in display
					glMatrixMode(GL_MODELVIEW);
					glLoadIdentity();
					gluLookAt();
				3.2.2 change angle in idlefunc
					note pre-define constant and angle2rad
			3.3 use double buffer to smooth
				glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
				glutSwapBuffers();
	*/
	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idlefunc);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}