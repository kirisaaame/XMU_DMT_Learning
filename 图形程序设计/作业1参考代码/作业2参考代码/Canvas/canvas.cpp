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
#define NUMBERPRIMITIVES 6//可用图元数量

// 全局变量
static int width, height; // OpenGL窗口大小
static float pointSize = 3.0; // 点的大小
static int primitive = INACTIVE; // 当前选择的图元
static int pointCount = 0; // 已指定点的数量
static int tempX, tempY; // 点击的点的坐标
static int isGrid = 1; // 是否显示网格
static int isPolyline = 0; // 是否绘制折线
static float currentColor[3] = { 0.0, 0.0, 0.0 }; // 当前颜色
static GLenum currentMode = GL_LINE;

// 点类
class Point
{
public:
	//带参构造函数
	Point(float xVal, float yVal, float sizeVal,float color[3])
	{
		x = xVal; y = yVal; size = sizeVal;
		this->color[0] = color[0];
		this->color[1] = color[1];
		this->color[2] = color[2];
	}
	Point() {};//默认构造函数
	void drawPoint(void); // 绘制点的函数
	float getX(void) { return x; } // 获取点的x坐标
	float getY(void) { return y; } // 获取点的y坐标

private:
	float x, y; // 点的x，y坐标
	float size; // 点的大小
	float color[3]; // 点的颜色
};

// 绘制点的函数
void Point::drawPoint()
{
	glPointSize(size);//设置点的大小
	glColor3fv(color);//设置颜色
	glBegin(GL_POINTS);
	glVertex3f(x, y, 0.0);
	glEnd();
}


// 点的容器
std::vector<Point> points;

// 遍历点数组的迭代器
std::vector<Point>::iterator pointsIterator;

// 绘制所有点的函数
void drawPoints(void)
{
	// 遍历点数组，绘制每个点
	for (auto point : points) { point.drawPoint(); }
}

//线类
class Line
{
public:
	//带参构造函数
	Line(float x1Val, float y1Val, float x2Val, float y2Val,float color[3])
	{
		x1 = x1Val; y1 = y1Val; x2 = x2Val; y2 = y2Val;
		this->color[0] = color[0];
		this->color[1] = color[1];
		this->color[2] = color[2];
	}
	Line() {};//默认构造函数
	void drawLine();// 绘制线的函数
private:
    float x1, y1, x2, y2; // 线段的两个端点的x，y坐标
	float color[3]; // 线的颜色
};


// 绘制线的函数
void Line::drawLine()
{
	glColor3fv(color);//设置颜色
	glBegin(GL_LINES);
	glVertex3f(x1, y1, 0.0);
	glVertex3f(x2, y2, 0.0);
	glEnd();
}

// 线的容器
std::vector<Line> lines;

// 绘制所有线的函数
void drawLines(void)
{
	// 遍历线数组，绘制每条线
	for (auto line : lines) { line.drawLine(); }
}

// 矩形类
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
    float x1, y1, x2, y2; // 矩形的两个对角点的x，y坐标
	float color[3]; // 矩形的颜色
	GLenum Mode; // 矩形的模式
};

// 绘制矩形的函数
void Rect::drawRectangle()
{
	glPolygonMode(GL_FRONT_AND_BACK, Mode);//设置为线框模式
	glColor3fv(color);//设置颜色
	glRectf(x1, y1, x2, y2);
}

// 矩形的容器
std::vector<Rect> rectangles;

// 绘制所有矩形的函数
void drawRectangles(void)
{
	// 遍历矩形数组，绘制每个矩形
	for (auto rectangle : rectangles) { rectangle.drawRectangle(); }
}

// 折线类
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
	// 折线点的容器
std::vector<Point> polylinePoints;
		void drawPolyline();
	private:
		float color[3]; // 折线的颜色
		
};

// 绘制折线的函数
void polyline::drawPolyline()
{
	glBegin(GL_LINE_STRIP);
	glColor3fv(color);//设置颜色
	for(auto point : polylinePoints)
	{
		glVertex3f(point.getX(), point.getY(), 0.0);
	}
	glEnd();
}



std::vector<polyline> polylines;

// 绘制所有折线的函数
void drawPolylines(void)
{
	// 遍历折线数组，绘制每条折线
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
		float x1, y1, x2, y2; // 圆心和边界点的x，y坐标
		float color[3]; // 圆的颜色
		GLenum Mode; // 圆的模式
};

void Circle::drawCircle()
{
	float radius = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	if (Mode == GL_LINE) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glBegin(GL_LINE_LOOP); // 线框模式

	}
	else if (Mode == GL_FILL) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glBegin(GL_POLYGON); // 填充模式
	}
	glColor3fv(color); // 设置颜色
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
		float x1, y1, x2, y2; // 六边形的两个对角点的x，y坐标
		float color[3]; // 六边形的颜色
		GLenum Mode; // 六边形的模式
};

void Hexagon::drawHexagon()
{
	float radius = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	if (Mode == GL_LINE) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glBegin(GL_LINE_LOOP); // 线框模式

	}
	else if (Mode == GL_FILL) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glBegin(GL_POLYGON); // 填充模式
	}
	glColor3fv(color);//设置颜色
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

// 在左侧选择区域 绘制点选择框的函数
void drawPointSelectionBox(void)
{
	// 如果当前选择的图元是点，高亮显示
	if (primitive == POINT) glColor3f(1.0, 1.0, 1.0); // 高亮
	else glColor3f(0.8, 0.8, 0.8); // 不高亮
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glRectf(0.0, 0.9*height, 0.1*width, height);//绘制矩形

	// 绘制黑色边界
	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRectf(0.0, 0.9*height, 0.1*width, height);

	// 绘制点图标
	glPointSize(pointSize);
	glColor3fv(currentColor);
	glBegin(GL_POINTS);
	glVertex3f(0.05*width, 0.95*height, 0.0);
	glEnd();
}

// 在左侧选择区域 绘制线选择框的函数
void drawLineSelectionBox(void)
{
	if (primitive == LINE) glColor3f(1.0, 1.0, 1.0); // Highlight.
	else glColor3f(0.8, 0.8, 0.8); // No highlight.
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glRectf(0.0, 0.8*height, 0.1*width, 0.9*height);

	// 绘制黑色边界
	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRectf(0.0, 0.8*height, 0.1*width, 0.9*height);

	// 绘制线图标
	glColor3fv(currentColor);
	glBegin(GL_LINES);
	glVertex3f(0.025*width, 0.825*height, 0.0);
	glVertex3f(0.075*width, 0.875*height, 0.0);
	glEnd();
}

// 在左侧选择区域 绘制矩形选择框的函数
void drawRectangleSelectionBox(void)
{
	if (primitive == RECTANGLE) glColor3f(1.0, 1.0, 1.0); // Highlight.
	else glColor3f(0.8, 0.8, 0.8); // No highlight.
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glRectf(0.0, 0.7*height, 0.1*width, 0.8*height);

	// 绘制黑色边界
	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRectf(0.0, 0.7*height, 0.1*width, 0.8*height);

	// 绘制矩形图标
	glColor3fv(currentColor);
	glPolygonMode(GL_FRONT_AND_BACK, currentMode);
	glRectf(0.025*width, 0.735*height, 0.075*width, 0.765*height);
	glEnd();
}

//在左侧选择区域 绘制折线选择框的函数
void drawPolylineSelectionBox(void)
{
	if (primitive == POLYLINE) glColor3f(1.0, 1.0, 1.0); // Highlight.
	else glColor3f(0.8, 0.8, 0.8); // No highlight.
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glRectf(0.0, 0.6*height, 0.1*width, 0.7*height);

	// 绘制黑色边界
	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRectf(0.0, 0.6*height, 0.1*width, 0.7*height);

	// 绘制折线图标
	glColor3fv(currentColor);
	glBegin(GL_LINE_STRIP);
	glVertex3f(0.025*width, 0.65*height, 0.0);
	glVertex3f(0.05*width, 0.675*height, 0.0);
	glVertex3f(0.075*width, 0.65*height, 0.0);
	glEnd();
}

// 在左侧选择区域 绘制圆选择框的函数
void drawCircleSelectionBox(void)
{
	if (primitive == CIRCLE) glColor3f(1.0, 1.0, 1.0); // Highlight.
	else glColor3f(0.8, 0.8, 0.8); // No highlight.
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glRectf(0.0, 0.5*height, 0.1*width, 0.6*height);

	// 绘制黑色边界
	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRectf(0.0, 0.5*height, 0.1*width, 0.6*height);

	// 绘制圆图标
	glColor3fv(currentColor);
	if (currentMode == GL_LINE) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glBegin(GL_LINE_LOOP); // 线框模式

	}
	else if (currentMode == GL_FILL) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glBegin(GL_POLYGON); // 填充模式
	}
	for (int i = 0; i < 360; i++)
	{
		float angle = i * 3.1415926 / 180;
		glVertex2f(0.05*width + 0.025*width * cos(angle), 0.55*height + 0.025*height * sin(angle));
	}
	glEnd();
}

//在左侧选择区域 绘制六边形选择框的函数
void drawHexagonSelectionBox(void)
{
	if (primitive == HEXAGON) glColor3f(1.0, 1.0, 1.0); // Highlight.
	else glColor3f(0.8, 0.8, 0.8); // No highlight.
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glRectf(0.0, 0.4*height, 0.1*width, 0.5*height);

	// 绘制黑色边界
	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRectf(0.0, 0.4*height, 0.1*width, 0.5*height);

	// 绘制六边形图标
	glColor3fv(currentColor);
	if (currentMode == GL_LINE) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glBegin(GL_LINE_LOOP); // 线框模式

	}
	else if (currentMode == GL_FILL) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glBegin(GL_POLYGON); // 填充模式
	}
	for (int i = 0; i < 6; i++)
	{
		float angle = i * 3.1415926 / 3;
		glVertex2f(0.05*width + 0.025*width * cos(angle), 0.45*height + 0.025*height * sin(angle));
	}
	glEnd();
}

// 绘制非活动区域的函数
void drawInactiveArea(void)
{
	glColor3f(0.6, 0.6, 0.6);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glRectf(0.0, 0.0, 0.1*width, (1 - NUMBERPRIMITIVES*0.1)*height);

	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRectf(0.0, 0.0, 0.1*width, (1 - NUMBERPRIMITIVES*0.1)*height);
}

// 绘制临时点的函数
void drawTempPoint(void)
{
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(pointSize);
	glBegin(GL_POINTS);
	glVertex3f(tempX, tempY, 0.0);
	glEnd();
}

// 绘制网格的函数
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

// 显示回调函数
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3fv(currentColor);//设置颜色

	// 绘制左侧选择区域
	drawPointSelectionBox();
	drawLineSelectionBox();
	drawRectangleSelectionBox();
	drawInactiveArea();
	drawPolylineSelectionBox();
	drawCircleSelectionBox();
	drawHexagonSelectionBox();

	// 绘制图元
	drawPoints();
	drawLines();
	drawRectangles();
	drawPolylines();
	drawCircles();
	drawHexagons();

	// 绘制临时点
	if (((primitive == LINE) || (primitive == RECTANGLE)) &&
		(pointCount == 1)) drawTempPoint();
	if(((primitive == CIRCLE) && pointCount == 1)) drawTempPoint();
	if(((primitive == HEXAGON) && pointCount == 1)) drawTempPoint();
	if (isGrid) drawGrid();

	glutSwapBuffers();
}

// 选择图元的函数
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

// 鼠标控制函数
void mouseControl(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)//鼠标左键按下
	{
		y = height - y; // 变换y坐标

		if (x < 0 || x > width || y < 0 || y > height); //检查是否在窗口内

		// 检查是否在左侧选择区域
		else if (x < 0.1 * width)
		{
			pickPrimitive(y);
			pointCount = 0;
		}

		// 检查是否在绘图区域
		else
		{
			if (primitive == POINT) points.push_back(Point(x, y, pointSize,currentColor));//添加点
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
	else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) //鼠标中键按下
	{
		if (isPolyline)
		{
			isPolyline = 0;
		}
	}
	glutPostRedisplay();
}

// 窗口大小改变时的回调函数
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// 设置正交投影
	glOrtho(0.0, (float)w, 0.0, (float)h, -1.0, 1.0);

	// 更新窗口大小
	width = w;
	height = h;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// 键盘输入回调函数
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

// 清除所有图元的函数
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

//右键菜单回调函数
void rightMenu(int id)
{
	if (id == 1)
	{
		clearAll();
		glutPostRedisplay();
	}
	if (id == 2) exit(0);
}

//网格菜单回调函数
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
		std::cout << "请输入颜色值（0-1）" << std::endl;
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

// 创建右键菜单
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

// 初始化函数
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	makeMenu(); // 创建右键菜单
}

//打印交互信息
void printInteraction(void)
{
	std::cout << "Interaction:" << std::endl;
	std::cout << "Left click on a box on the left to select a primitive." << std::endl
		<< "Then left click on the drawing area: once for point, twice for line or rectangle." << std::endl
		<< "Right click for menu options." << std::endl;
}

// 主程序
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