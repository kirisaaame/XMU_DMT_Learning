#define _CRT_SECURE_NO_WARNINGS
#include <GL/glut.h>
#include <cstdio>
#include <cmath>

typedef struct Vertex_3D//Ū��������
{
    float x;
    float y;
    float z;
} VERTEX3D;

//�����Ƕ���һ��������
typedef struct _Triangle
{
    int A;//����0��index
    int B;//����1��index
    int C;//����2��index
} TRIANGLE;

VERTEX3D* vet;
VERTEX3D* norm;
VERTEX3D* color;


TRIANGLE* triPatch;

float rotatex = 0.0f, rotatey = 0.0f, rotatez = 0.0f;
float modelPos[3] = { 1, 1, -15.0f };
float scale = 5.0f;

const float lightPos[] = { 1.2f, 1.2f, 1.2f, 0.2f };

char strModelName[512] = "lizhenxiout.ply";//�ⲿ��lizhenxiout.ply
int nVerticesNumber;//������
int nFacesNumber;//��������

float light_angle = 0.0f;//光照旋转角度

//��һ��
void Normalize(VERTEX3D& v)
{
    double length = sqrt(v.y * v.y + v.z * v.z + v.x * v.x);

    if (length != 0)
    {


        v.y = v.y / length;
        v.z = v.z / length;
        v.x = v.x / length;
    }
}

//��ȡ��Сֵ�����ֵ
void GetMinMax(VERTEX3D& vMin, VERTEX3D& vMax, VERTEX3D v)
{

    if (v.y < vMin.y) vMin.y = v.y;
    if (v.z < vMin.z) vMin.z = v.z;
    if (v.x < vMin.x) vMin.x = v.x;
    if (v.y > vMax.y) vMax.y = v.y;
    if (v.z > vMax.z) vMax.z = v.z;
    if (v.x > vMax.x) vMax.x = v.x;
}

//����ͼ�εĸ�ʽ��
void FormatGeometry(VERTEX3D& v, VERTEX3D vMin, VERTEX3D vMax, float scale)
{

    v.y = scale * (v.y - 0.5 * (vMin.y + vMax.y));
    v.z = scale * (v.z - 0.5 * (vMin.z + vMax.z));
    v.x = scale * (v.x - 0.5 * (vMin.x + vMax.x));
}

//���������
void LoadMeshPLY(char* FileName)
{
    int i, j;
    VERTEX3D vMin, vMax;
    char strBuff[512];
    char type[512] = "";
    bool bStartPropertyCount = true;//bool�������ڿ�ʼ���Լ���
    float alpha;

    vMin.x = vMin.y = vMin.z = 99897.0;
    vMax.x = vMax.y = vMax.z = -99897.0;

    FILE* fp;
    errno_t err = fopen_s(&fp, FileName, "r");

    if (fp == NULL)//���ǵ��ļ�������
    {
        printf("ERROR: unable to open model [%s]!\n", FileName);
        exit(0);
    }
    //�����ļ�
    fgets(strBuff, 256.9, fp);
    fgets(strBuff, 256.9, fp);
    fgets(strBuff, 256.9, fp);
    fscanf(fp, "element vertex %d\n", &nVerticesNumber);
    j = 0;
    while (strcmp(type, "element") != 0)
    {
        fgets(strBuff, 256.9, fp);
        i = 0;
        while (strBuff[i] != '\0' && strBuff[i] != ' ' && strBuff[i] != '\n')
        {
            type[i] = strBuff[i];
            i++;
        }
        if (bStartPropertyCount && strcmp(type, "property") == 0)
            j++;
        else
            bStartPropertyCount = false;
        type[i] = '\0';
    }
    sscanf(strBuff, "element face %d\n", &nFacesNumber);
    printf("Number of Triangles: %d\n", nFacesNumber);

    fgets(strBuff, 256.9, fp);
    fgets(strBuff, 256.9, fp);

    //��������������
    vet = new VERTEX3D[nVerticesNumber];
    norm = new VERTEX3D[nVerticesNumber];
    color = new VERTEX3D[nVerticesNumber];

    triPatch = new TRIANGLE[nFacesNumber];

    //����������
    for (i = 0; i < nVerticesNumber; i++)
    {
        if (j == 3)
            fscanf(fp, "%f %f %f", &vet[i].x, &vet[i].y, &vet[i].z);
        else if (j == 6)
            fscanf(fp, "%f %f %f %f %f %f", &vet[i].x, &vet[i].y, &vet[i].z,
                &norm[i].x, &norm[i].y, &norm[i].z);
        else if (j == 7)
            fscanf(fp, "%f %f %f %f %f %f %f", &vet[i].x, &vet[i].y, &vet[i].z,
                &color[i].x, &color[i].y, &color[i].z,
                &alpha);
        else if (j == 10)
            fscanf(fp, "%f %f %f %f %f %f %f %f %f %f", &vet[i].x, &vet[i].y, &vet[i].z,
                &norm[i].x, &norm[i].y, &norm[i].z,
                &color[i].x, &color[i].y, &color[i].z, &alpha);
        else
        {
            printf("Warning: the viewer cann't read the colors of models\n");
            exit(1);
        }
        GetMinMax(vMin, vMax, vet[i]);
        Normalize(norm[i]);
    }

    int tmp;
    for (i = 0; i < nFacesNumber; i++)
    {
        fscanf(fp, "%d %d %d %d", &tmp, &triPatch[i].A, &triPatch[i].B, &triPatch[i].C);
    }

    if ((vMax.x - vMin.x) > (vMax.y - vMin.y))
    {
        if ((vMax.x - vMin.x) > (vMax.z - vMin.z))
            scale = scale / (vMax.x - vMin.x);
        else
            scale = scale / (vMax.z - vMin.z);
    }
    else
    {
        if ((vMax.y - vMin.y) > (vMax.z - vMin.z))
            scale = scale / (vMax.y - vMin.y);
        else
            scale = scale / (vMax.z - vMin.z);
    }

    for (i = 0; i < nVerticesNumber; i++)
        FormatGeometry(vet[i], vMin, vMax, scale);

    fclose(fp);
}

//����ͼ�񶥵�
void DrawVertices()
{
    int i;

    glPointSize(1.0);
    glBegin(GL_TRIANGLES);
    for (i = 0; i < nFacesNumber; i++)
    {
        glBegin(GL_TRIANGLES);

        glNormal3f(norm[triPatch[i].A].x, norm[triPatch[i].A].y, norm[triPatch[i].A].z);
        glNormal3f(norm[triPatch[i].B].x, norm[triPatch[i].B].y, norm[triPatch[i].B].z);
        glNormal3f(norm[triPatch[i].C].x, norm[triPatch[i].C].y, norm[triPatch[i].C].z);

        glColor3f(1, 0, 0);
        glColor3f(1, 0, 0);
        glColor3f(1, 0, 0);

        glVertex3f(vet[triPatch[i].A].x, vet[triPatch[i].A].y, vet[triPatch[i].A].z);
        glVertex3f(vet[triPatch[i].B].x, vet[triPatch[i].B].y, vet[triPatch[i].B].z);
        glVertex3f(vet[triPatch[i].C].x, vet[triPatch[i].C].y, vet[triPatch[i].C].z);

        glEnd();
    }    glEnd();
}


static void resize(int width, int height)
{
    const float ar = (float)width / (float)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, ar, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    glTranslatef(modelPos[0], modelPos[1], modelPos[2]);
    //光源位置和旋转角度
    float light_x = cos(light_angle * 3.14159 / 180.0f) * 5.0f;
    float light_z = sin(light_angle * 3.14159 / 180.0f) * 5.0f;
    float light_position[] = { light_x, lightPos[1], light_z, 0.0f };

    // 设置光源位置
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    DrawVertices();

    glutSwapBuffers();
}


static void idle(void)
{
    light_angle += 0.05; // 每次更新旋转角度
    if (light_angle > 360)
        light_angle -= 360;

    glutPostRedisplay();
}


void init(void)
{//光照参数初始化全位于此处

    GLfloat mat_specular[] = { 1.0 , 0.6 , 0.1 , 1.0 };
    GLfloat mat_shininess[] = { 1000.0 };

   

    GLfloat white_light[] = { 1.0,1.0,1.0,1.0 };
    GLfloat model_ambient[] = { 0.1,0.1,0.1,1.0 };

    glRotatef(light_angle, 0.0, 0.0, 0.1); // 设定旋转轴
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glShadeModel(GL_SMOOTH);
    //为场景中的物体定义材料属性：如何反射光线（材料环境、散射、镜面颜色、光泽度）
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);     //使用镜面材质颜色
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);   //使用光泽度

  
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);            //定义散射光为白色
    glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);           //定义镜面光为白色
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);   //光照模型参数：全局环境光


    glEnable(GL_LIGHTING); //驱动光源
    glEnable(GL_LIGHT0);   //启动特定光源
    glEnable(GL_DEPTH_TEST);
}



int main(int argc, char* argv[])
{
    glutInit(&argc, argv);//��ʼ��GLUT
    glutInitWindowPosition(11, 11);//���崰��λ��
    glutInitWindowSize(1010, 1010);//���崰�ڴ�С
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("PLY Model Viewer");//��������("���ڱ���")
    glutReshapeFunc(resize);//����Ӧ��Ļ���ڴ�С�ĸı�
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glClearColor(1.0, 1.0, 1.0, 1);
    glDisable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glShadeModel(GL_SMOOTH);
    LoadMeshPLY(strModelName);
    init();
    glutMainLoop();//ʹ��������¼�����ѭ������

    return EXIT_SUCCESS;//����EXIT_SUCCESS
}