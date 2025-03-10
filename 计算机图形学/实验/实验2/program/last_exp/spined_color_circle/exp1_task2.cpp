#include <GL/glut.h>
#include <math.h> // for sine and cosine
#include <ctime>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glShadeModel(GL_FLAT); //using flat mode to render instead of smooth
}

GLfloat pi = 3.1415926535;
GLfloat spin = 0.0;
// define some color 
GLfloat color_map[7][3] = {
	{0.917, 0.0, 0.0},
	{0.067, 0.627, 0.850},
	{0.592, 0.592, 0.592},
	{0.4, 0.929, 0.2549},
	{0.968, 0.698, 0.215},
	{0.215, 0.698, 0.968},
	{0.2549, 0.929, 0.4 },
};


void draw_sector(GLfloat start_theta, GLfloat end_theta,
	GLfloat R=0.5, int n = 20,
	GLfloat center_x = 0, GLfloat center_y = 0, GLfloat z = 0.0)
{
	glBegin(GL_POLYGON);
		// center point
		glVertex3f(center_x, center_y, z);
		GLfloat delta_theta = (end_theta - start_theta) / n;
		for (int i = 0; i <= n; i++) {
			GLfloat x = center_x + R * cos(start_theta + i * delta_theta);
			GLfloat y = center_y + R * sin(start_theta + i * delta_theta);
			glVertex3f(x, y, z);
		}
		glVertex3f(center_x, center_y, z);

	glEnd();
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glPushMatrix();										// make this transform based on origin point

	glRotatef(spin, 0.0, 0.0, 1.0);			// spin 

	int n = 7;
	GLfloat start_theta = 0;
	GLfloat end_theta;
		

	for (int i = 1; i <= n; i++) {
		glColor3f(color_map[(i) % 7][0], color_map[i % 7][1], color_map[i % 7][2]);			
		end_theta = start_theta + (2 * pi) / n;			// decide start_theta
		draw_sector(start_theta, end_theta, 0.5, 20, 0, 0, -6);	// draw a sector
		start_theta = end_theta;
	}

	glPopMatrix();
	glutSwapBuffers();

}

void spinDisplay(void) {
	spin = spin + 0.05;
	if (spin > 360) {
		spin -= 360;
	}
	glutPostRedisplay();

}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 4, 10.0);
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
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100); 
	glutCreateWindow(argv[0]);
	init();
	glutIdleFunc(spinDisplay);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
