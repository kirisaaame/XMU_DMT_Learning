#include <GL/glut.h>
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT); //使用单一颜色
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix

	glTranslatef(-1.5f, 0.0f, -6.0f);						// Move 1.5 Units Left And 6.0 Units Into The Screen.
	glBegin(GL_TRIANGLES);								// Drawing Using Triangles
	glVertex3f(0.0f, 1.0f, 0.0f);					// Top
	glVertex3f(-1.0f, -1.0f, 0.0f);					// Bottom Left
	glVertex3f(1.0f, -1.0f, 0.0f);					// Bottom Right
	glEnd();											// Finished Drawing The Triangle
	glTranslatef(3.0f, 0.0f, 0.0f);						// Move Right 3 Units
	glBegin(GL_QUADS);									// Draw A Quad
	glVertex3f(-1.0f, 1.0f, 0.0f);					// Top Left
	glVertex3f(1.0f, 1.0f, 0.0f);					// Top Right
	glVertex3f(1.0f, -1.0f, 0.0f);					// Bottom Right
	glVertex3f(-1.0f, -1.0f, 0.0f);					// Bottom Left
	glEnd();

	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(0);
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100); //窗口处于屏幕左上角的位置
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
