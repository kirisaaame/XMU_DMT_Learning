#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GL/freeglut.h> 

#define INACTIVE 0
#define POINT 1
#define LINE 2
#define RECTANGLE 3
#define POLYLINE 4
#define CIRCLE 5
#define HEXAGON 6
#define NUMBERPRIMITIVES 6//����ͼԪ����

// ȫ�ֱ���
static int width, height; // OpenGL���ڴ�С
static float pointSize = 3.0; // ��Ĵ�С
static int primitive = INACTIVE; // ��ǰѡ���ͼԪ
static int pointCount = 0; // ��ָ���������
static int tempX, tempY; // ����ĵ������
static int isGrid = 1; // �Ƿ���ʾ����
static int isPolyline = 0; // �Ƿ��������
static float currentColor[3] = { 0.0, 0.0, 0.0 }; // ��ǰ��ɫ
static GLenum currentMode = GL_LINE;

// ����
class Point
{
public:
	//���ι��캯��
	Point(float xVal, float yVal, float sizeVal,float color[3])
	{
		x = xVal; y = yVal; size = sizeVal;
		this->color[0] = color[0];
		this->color[1] = color[1];
		this->color[2] = color[2];
	}
	Point() {};//Ĭ�Ϲ��캯��
	void drawPoint(void); // ���Ƶ�ĺ���
	float getX(void) { return x; } // ��ȡ���x����
	float getY(void) { return y; } // ��ȡ���y����

private:
	float x, y; // ���x��y����
	float size; // ��Ĵ�С
	float color[3]; // �����ɫ
};

// ���Ƶ�ĺ���
void Point::drawPoint()
{
	glPointSize(size);//���õ�Ĵ�С
	glColor3fv(color);//������ɫ
	glBegin(GL_POINTS);
	glVertex3f(x, y, 0.0);
	glEnd();
}


// �������
std::vector<Point> points;

// ����������ĵ�����
std::vector<Point>::iterator pointsIterator;

// �������е�ĺ���
void drawPoints(void)
{
	// ���������飬����ÿ����
	for (auto point : points) { point.drawPoint(); }
}

//����
class Line
{
public:
	//���ι��캯��
	Line(float x1Val, float y1Val, float x2Val, float y2Val,float color[3])
	{
		x1 = x1Val; y1 = y1Val; x2 = x2Val; y2 = y2Val;
		this->color[0] = color[0];
		this->color[1] = color[1];
		this->color[2] = color[2];
	}
	Line() {};//Ĭ�Ϲ��캯��
	void drawLine();// �����ߵĺ���
private:
    float x1, y1, x2, y2; // �߶ε������˵��x��y����
	float color[3]; // �ߵ���ɫ
};


// �����ߵĺ���
void Line::drawLine()
{
	glColor3fv(color);//������ɫ
	glBegin(GL_LINES);
	glVertex3f(x1, y1, 0.0);
	glVertex3f(x2, y2, 0.0);
	glEnd();
}

// �ߵ�����
std::vector<Line> lines;

// ���������ߵĺ���
void drawLines(void)
{
	// ���������飬����ÿ����
	for (auto line : lines) { line.drawLine(); }
}

// ������
class Rect
{
public:
	Rect(float x1Val, float y1Val, float x2Val, float y2Val,float color[3],GLenum mode)
	{
		x1 = x1Val; y1 = y1Val; x2 = x2Val; y2 = y2Val;
		this->color[0] = color[0];
		this->color[1] = color[1];
		this->color[2] = color[2];
		Mode = mode;
	}
	Rect() {};
	void drawRectangle();
private:
    float x1, y1, x2, y2; // ���ε������Խǵ��x��y����
	float color[3]; // ���ε���ɫ
	GLenum Mode; // ���ε�ģʽ
};

// ���ƾ��εĺ���
void Rect::drawRectangle()
{
	glPolygonMode(GL_FRONT_AND_BACK, Mode);//����Ϊ�߿�ģʽ
	glColor3fv(color);//������ɫ
	glRectf(x1, y1, x2, y2);
}

// ���ε�����
std::vector<Rect> rectangles;

// �������о��εĺ���
void drawRectangles(void)
{
	// �����������飬����ÿ������
	for (auto rectangle : rectangles) { rectangle.drawRectangle(); }
}

// ������
class polyline
{
public:
	polyline(float color[3])
	{
		this->color[0] = color[0];
		this->color[1] = color[1];
		this->color[2] = color[2];
	}
	polyline() {};
	// ���ߵ������
std::vector<Point> polylinePoints;
		void drawPolyline();
	private:
		float color[3]; // ���ߵ���ɫ
		
};

// �������ߵĺ���
void polyline::drawPolyline()
{
	glBegin(GL_LINE_STRIP);
	glColor3fv(color);//������ɫ
	for(auto point : polylinePoints)
	{
		glVertex3f(point.getX(), point.getY(), 0.0);
	}
	glEnd();
}



std::vector<polyline> polylines;

// �����������ߵĺ���
void drawPolylines(void)
{
	// �����������飬����ÿ������
	for (auto polyline : polylines) { polyline.drawPolyline(); }
}

class Circle 
{
 public:
	Circle(float x1Val, float y1Val, float x2Val, float y2Val,float color[3],GLenum mode)
	{
		x1 = x1Val; y1 = y1Val; x2 = x2Val; y2 = y2Val;
		this->color[0] = color[0];
		this->color[1] = color[1];
		this->color[2] = color[2];
		Mode = mode;
	}
	Circle() {};
	void drawCircle();
	private:
		float x1, y1, x2, y2; // Բ�ĺͱ߽���x��y����
		float color[3]; // Բ����ɫ
		GLenum Mode; // Բ��ģʽ
};

void Circle::drawCircle()
{
	float radius = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	if (Mode == GL_LINE) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glBegin(GL_LINE_LOOP); // �߿�ģʽ

	}
	else if (Mode == GL_FILL) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glBegin(GL_POLYGON); // ���ģʽ
	}
	glColor3fv(color); // ������ɫ
	for (int i = 0; i < 360; i++)
	{
		float angle = i * 3.1415926 / 180;
		glVertex2f(x1 + radius * cos(angle), y1 + radius * sin(angle));
	}
	glEnd();
}

std::vector<Circle> circles;

void drawCircles(void)
{
	for (auto circle : circles) { circle.drawCircle(); }
}

class Hexagon
{
public:
		Hexagon(float x1Val, float y1Val, float x2Val, float y2Val,float color[3],GLenum mode)
	{
		x1 = x1Val; y1 = y1Val; x2 = x2Val; y2 = y2Val;
		this->color[0] = color[0];
		this->color[1] = color[1];
		this->color[2] = color[2];
		Mode = mode;
	}
	Hexagon() {};
	void drawHexagon();
	private:
		float x1, y1, x2, y2; // �����ε������Խǵ��x��y����
		float color[3]; // �����ε���ɫ
		GLenum Mode; // �����ε�ģʽ
};

void Hexagon::drawHexagon()
{
	float radius = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	if (Mode == GL_LINE) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glBegin(GL_LINE_LOOP); // �߿�ģʽ

	}
	else if (Mode == GL_FILL) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glBegin(GL_POLYGON); // ���ģʽ
	}
	glColor3fv(color);//������ɫ
	for (int i = 0; i < 6; i++)
	{
		float angle = i * 3.1415926 / 3;
		glVertex2f(x1 + radius * cos(angle), y1 + radius * sin(angle));
	}
	glEnd();
}

std::vector<Hexagon> hexagons;

void drawHexagons(void)
{
	for (auto hexagon : hexagons) { hexagon.drawHexagon(); }
}

// �����ѡ������ ���Ƶ�ѡ���ĺ���
void drawPointSelectionBox(void)
{
	// �����ǰѡ���ͼԪ�ǵ㣬������ʾ
	if (primitive == POINT) glColor3f(1.0, 1.0, 1.0); // ����
	else glColor3f(0.8, 0.8, 0.8); // ������
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glRectf(0.0, 0.9*height, 0.1*width, height);//���ƾ���

	// ���ƺ�ɫ�߽�
	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRectf(0.0, 0.9*height, 0.1*width, height);

	// ���Ƶ�ͼ��
	glPointSize(pointSize);
	glColor3fv(currentColor);
	glBegin(GL_POINTS);
	glVertex3f(0.05*width, 0.95*height, 0.0);
	glEnd();
}

// �����ѡ������ ������ѡ���ĺ���
void drawLineSelectionBox(void)
{
	if (primitive == LINE) glColor3f(1.0, 1.0, 1.0); // Highlight.
	else glColor3f(0.8, 0.8, 0.8); // No highlight.
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glRectf(0.0, 0.8*height, 0.1*width, 0.9*height);

	// ���ƺ�ɫ�߽�
	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRectf(0.0, 0.8*height, 0.1*width, 0.9*height);

	// ������ͼ��
	glColor3fv(currentColor);
	glBegin(GL_LINES);
	glVertex3f(0.025*width, 0.825*height, 0.0);
	glVertex3f(0.075*width, 0.875*height, 0.0);
	glEnd();
}

// �����ѡ������ ���ƾ���ѡ���ĺ���
void drawRectangleSelectionBox(void)
{
	if (primitive == RECTANGLE) glColor3f(1.0, 1.0, 1.0); // Highlight.
	else glColor3f(0.8, 0.8, 0.8); // No highlight.
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glRectf(0.0, 0.7*height, 0.1*width, 0.8*height);

	// ���ƺ�ɫ�߽�
	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRectf(0.0, 0.7*height, 0.1*width, 0.8*height);

	// ���ƾ���ͼ��
	glColor3fv(currentColor);
	glPolygonMode(GL_FRONT_AND_BACK, currentMode);
	glRectf(0.025*width, 0.735*height, 0.075*width, 0.765*height);
	glEnd();
}

//�����ѡ������ ��������ѡ���ĺ���
void drawPolylineSelectionBox(void)
{
	if (primitive == POLYLINE) glColor3f(1.0, 1.0, 1.0); // Highlight.
	else glColor3f(0.8, 0.8, 0.8); // No highlight.
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glRectf(0.0, 0.6*height, 0.1*width, 0.7*height);

	// ���ƺ�ɫ�߽�
	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRectf(0.0, 0.6*height, 0.1*width, 0.7*height);

	// ��������ͼ��
	glColor3fv(currentColor);
	glBegin(GL_LINE_STRIP);
	glVertex3f(0.025*width, 0.65*height, 0.0);
	glVertex3f(0.05*width, 0.675*height, 0.0);
	glVertex3f(0.075*width, 0.65*height, 0.0);
	glEnd();
}

// �����ѡ������ ����Բѡ���ĺ���
void drawCircleSelectionBox(void)
{
	if (primitive == CIRCLE) glColor3f(1.0, 1.0, 1.0); // Highlight.
	else glColor3f(0.8, 0.8, 0.8); // No highlight.
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glRectf(0.0, 0.5*height, 0.1*width, 0.6*height);

	// ���ƺ�ɫ�߽�
	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRectf(0.0, 0.5*height, 0.1*width, 0.6*height);

	// ����Բͼ��
	glColor3fv(currentColor);
	if (currentMode == GL_LINE) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glBegin(GL_LINE_LOOP); // �߿�ģʽ

	}
	else if (currentMode == GL_FILL) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glBegin(GL_POLYGON); // ���ģʽ
	}
	for (int i = 0; i < 360; i++)
	{
		float angle = i * 3.1415926 / 180;
		glVertex2f(0.05*width + 0.025*width * cos(angle), 0.55*height + 0.025*height * sin(angle));
	}
	glEnd();
}

//�����ѡ������ ����������ѡ���ĺ���
void drawHexagonSelectionBox(void)
{
	if (primitive == HEXAGON) glColor3f(1.0, 1.0, 1.0); // Highlight.
	else glColor3f(0.8, 0.8, 0.8); // No highlight.
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glRectf(0.0, 0.4*height, 0.1*width, 0.5*height);

	// ���ƺ�ɫ�߽�
	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRectf(0.0, 0.4*height, 0.1*width, 0.5*height);

	// ����������ͼ��
	glColor3fv(currentColor);
	if (currentMode == GL_LINE) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glBegin(GL_LINE_LOOP); // �߿�ģʽ

	}
	else if (currentMode == GL_FILL) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glBegin(GL_POLYGON); // ���ģʽ
	}
	for (int i = 0; i < 6; i++)
	{
		float angle = i * 3.1415926 / 3;
		glVertex2f(0.05*width + 0.025*width * cos(angle), 0.45*height + 0.025*height * sin(angle));
	}
	glEnd();
}

// ���Ʒǻ����ĺ���
void drawInactiveArea(void)
{
	glColor3f(0.6, 0.6, 0.6);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glRectf(0.0, 0.0, 0.1*width, (1 - NUMBERPRIMITIVES*0.1)*height);

	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRectf(0.0, 0.0, 0.1*width, (1 - NUMBERPRIMITIVES*0.1)*height);
}

// ������ʱ��ĺ���
void drawTempPoint(void)
{
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(pointSize);
	glBegin(GL_POINTS);
	glVertex3f(tempX, tempY, 0.0);
	glEnd();
}

// ��������ĺ���
void drawGrid(void)
{
	int i;

	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x5555);
	glColor3f(0.75, 0.75, 0.75);

	glBegin(GL_LINES);
	for (i = 2; i <= 9; i++)
	{
		glVertex3f(i*0.1*width, 0.0, 0.0);
		glVertex3f(i*0.1*width, height, 0.0);
	}
	for (i = 1; i <= 9; i++)
	{
		glVertex3f(0.1*width, i*0.1*height, 0.0);
		glVertex3f(width, i*0.1*height, 0.0);
	}
	glEnd();
	glDisable(GL_LINE_STIPPLE);
}

// ��ʾ�ص�����
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3fv(currentColor);//������ɫ

	// �������ѡ������
	drawPointSelectionBox();
	drawLineSelectionBox();
	drawRectangleSelectionBox();
	drawInactiveArea();
	drawPolylineSelectionBox();
	drawCircleSelectionBox();
	drawHexagonSelectionBox();

	// ����ͼԪ
	drawPoints();
	drawLines();
	drawRectangles();
	drawPolylines();
	drawCircles();
	drawHexagons();

	// ������ʱ��
	if (((primitive == LINE) || (primitive == RECTANGLE)) &&
		(pointCount == 1)) drawTempPoint();
	if(((primitive == CIRCLE) && pointCount == 1)) drawTempPoint();
	if(((primitive == HEXAGON) && pointCount == 1)) drawTempPoint();
	if (isGrid) drawGrid();

	glutSwapBuffers();
}

// ѡ��ͼԪ�ĺ���
void pickPrimitive(int y)
{
	if (y < (1 - NUMBERPRIMITIVES*0.1)*height) primitive = INACTIVE;
	else if (y < (1 - 5 * 0.1)*height) primitive = HEXAGON;
	else if (y < (1 - 4 * 0.1)*height) primitive = CIRCLE;
	else if (y < (1 - 3 * 0.1)*height) primitive = POLYLINE;
	else if (y < (1 - 2 * 0.1)*height) primitive = RECTANGLE;
	else if (y < (1 - 1 * 0.1)*height) primitive = LINE;
	else primitive = POINT;
}

// �����ƺ���
void mouseControl(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)//����������
	{
		y = height - y; // �任y����

		if (x < 0 || x > width || y < 0 || y > height); //����Ƿ��ڴ�����

		// ����Ƿ������ѡ������
		else if (x < 0.1 * width)
		{
			pickPrimitive(y);
			pointCount = 0;
		}

		// ����Ƿ��ڻ�ͼ����
		else
		{
			if (primitive == POINT) points.push_back(Point(x, y, pointSize,currentColor));//��ӵ�
			else if (primitive == LINE)
			{
				if (pointCount == 0)
				{
					tempX = x; tempY = y;
					pointCount++;
				}
				else
				{
					lines.push_back(Line(tempX, tempY, x, y,currentColor));
					pointCount = 0;
				}
			}
			else if (primitive == RECTANGLE)
			{
				if (pointCount == 0)
				{
					tempX = x; tempY = y;
					pointCount++;
				}
				else
				{
					rectangles.push_back(Rect(tempX, tempY, x, y,currentColor,currentMode));
					pointCount = 0;
				}
			}
			else if (primitive == POLYLINE)
			{
				if (!isPolyline)
				{
					polylines.push_back(polyline(currentColor));
					isPolyline = 1;
				}
					polylines.back().polylinePoints.push_back(Point(x, y, pointSize,currentColor));
			}
			else if (primitive == CIRCLE)
			{
				if (pointCount == 0)
				{
					tempX = x; tempY = y;
					pointCount++;
				}
				else
				{
					circles.push_back(Circle(tempX, tempY, x, y,currentColor,currentMode));
					pointCount = 0;
				}
			}
			else if (primitive == HEXAGON)
			{
				if (pointCount == 0)
				{
					tempX = x; tempY = y;
					pointCount++;
				}
				else
				{
					hexagons.push_back(Hexagon(tempX, tempY, x, y,currentColor,currentMode));
					pointCount = 0;
				}
			}
		}
	}
	else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) //����м�����
	{
		if (isPolyline)
		{
			isPolyline = 0;
		}
	}
	glutPostRedisplay();
}

// ���ڴ�С�ı�ʱ�Ļص�����
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// ��������ͶӰ
	glOrtho(0.0, (float)w, 0.0, (float)h, -1.0, 1.0);

	// ���´��ڴ�С
	width = w;
	height = h;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// ��������ص�����
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

// �������ͼԪ�ĺ���
void clearAll(void)
{
	points.clear();
	lines.clear();
	rectangles.clear();
	polylines.clear();
	circles.clear();
	hexagons.clear();
	primitive = INACTIVE;
	pointCount = 0;
}

//�Ҽ��˵��ص�����
void rightMenu(int id)
{
	if (id == 1)
	{
		clearAll();
		glutPostRedisplay();
	}
	if (id == 2) exit(0);
}

//����˵��ص�����
void grid_menu(int id)
{
	if (id == 3) isGrid = 1;
	if (id == 4) isGrid = 0;
	glutPostRedisplay();
}

void color_menu(int id)
{
	if (id == 5)
	{
		currentColor[0] = 1.0;
		currentColor[1] = 0.0;
		currentColor[2] = 0.0;
	}
	if (id == 6)
	{
		currentColor[0] = 0.0;
		currentColor[1] = 1.0;
		currentColor[2] = 0.0;
	
	}
	if (id == 7)
	{
		currentColor[0] = 0.0;
		currentColor[1] = 0.0;
		currentColor[2] = 1.0;
	}
	if (id == 8)
	{
		currentColor[0] = 0.0;
		currentColor[1] = 0.0;
		currentColor[2] = 0.0;
	
	}
	if (id == 9)
	{
		currentColor[0] = 1.0;
		currentColor[1] = 1.0;
		currentColor[2] = 1.0;
	}
    if (id == 10)
	{
		std::cout << "��������ɫֵ��0-1��" << std::endl;
		std::cout << "R:";
		std::cin >> currentColor[0];
		std::cout << "G:";
		std::cin >> currentColor[1];
		std::cout << "B:";
		std::cin >> currentColor[2];
	}
}

void mode_menu(int id)
{
	if (id == 11)
	{
		currentMode = GL_LINE;
	}
	if (id == 12)
	{
		currentMode = GL_FILL;
	}
}

// �����Ҽ��˵�
void makeMenu(void)
{
	int sub_menu;
	sub_menu = glutCreateMenu(grid_menu);
	glutAddMenuEntry("On", 3);
	glutAddMenuEntry("Off", 4);
	int sub_menu2 = glutCreateMenu(color_menu);
	glutAddMenuEntry("Red", 5);
	glutAddMenuEntry("Green", 6);
	glutAddMenuEntry("Blue", 7);
	glutAddMenuEntry("Black", 8);
	glutAddMenuEntry("White", 9);
	glutAddMenuEntry("User_defined", 10);
	int mode = glutCreateMenu(mode_menu);
	glutAddMenuEntry("Line", 11);
	glutAddMenuEntry("Fill", 12);


	glutCreateMenu(rightMenu);
	glutAddSubMenu("Grid", sub_menu);
	glutAddMenuEntry("Clear", 1);
	glutAddMenuEntry("Quit", 2);
	glutAddSubMenu("Color", sub_menu2);
	glutAddSubMenu("Mode", mode);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// ��ʼ������
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	makeMenu(); // �����Ҽ��˵�
}

//��ӡ������Ϣ
void printInteraction(void)
{
	std::cout << "Interaction:" << std::endl;
	std::cout << "Left click on a box on the left to select a primitive." << std::endl
		<< "Then left click on the drawing area: once for point, twice for line or rectangle." << std::endl
		<< "Right click for menu options." << std::endl;
}

// ������
int main(int argc, char **argv)
{
	printInteraction();
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("canvas.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	glutMouseFunc(mouseControl);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}