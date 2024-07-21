#include "OBJ.h"
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Mesh::Mesh()
{
    vertices = NULL;
    faces = NULL;
    facetnorms = NULL;
    numVertices = 0;
    numFaces = 0;
    numTexcoords = 0;
}

Mesh::~Mesh()
{
    if (vertices != NULL)
        delete[] vertices;
    if (faces != NULL)
        delete[] faces;
    if (facetnorms != NULL)
        delete[] facetnorms;
}

void Mesh::compute_normal()
{
    if (numVertices == 0) return;

    if (facetnorms != NULL)
        delete[] facetnorms;

    facetnorms = new float[numVertices * 3];
    memset(facetnorms, 0, sizeof(float) * numVertices * 3);

    // �򵥼���ÿ������ķ���Ϊ�����귽��ĵ�λ����
    for (int i = 0; i < numVertices; i++) {
        float x = vertices[3 * i + 0];
        float y = vertices[3 * i + 1];
        float z = vertices[3 * i + 2];
        float length = sqrt(x * x + y * y + z * z);
        if (length > 0.0f) {
            facetnorms[3 * i + 0] = x / length;
            facetnorms[3 * i + 1] = y / length;
            facetnorms[3 * i + 2] = z / length;
        }
    }
}


// ���������������е����ֵ
static float max(float a, float b)
{
    return (b > a) ? b : a;
}

// ���ظ������ľ���ֵ
static float abs(float f)
{
    return (f < 0) ? -f : f;
}

void Mesh::unitize()
{
    if (vertices == NULL)
        return;

    float maxx, minx, maxy, miny, maxz, minz;
    float cx, cy, cz, w, h, d;
    float scale;

    // ��ȡ���/��Сֵ
    maxx = minx = vertices[0];
    maxy = miny = vertices[1];
    maxz = minz = vertices[2];
    for (int i = 0; i < numVertices; i++)
    {
        if (maxx < vertices[3 * i + 0])
            maxx = vertices[3 * i + 0];
        if (minx > vertices[3 * i + 0])
            minx = vertices[3 * i + 0];

        if (maxy < vertices[3 * i + 1])
            maxy = vertices[3 * i + 1];
        if (miny > vertices[3 * i + 1])
            miny = vertices[3 * i + 1];

        if (maxz < vertices[3 * i + 2])
            maxz = vertices[3 * i + 2];
        if (minz > vertices[3 * i + 2])
            minz = vertices[3 * i + 2];
    }

    // ����ģ�͵Ŀ�ȡ��߶Ⱥ����
    w = abs(maxx) + abs(minx);
    h = abs(maxy) + abs(miny);
    d = abs(maxz) + abs(minz);

    // ����ģ�͵�����
    cx = (maxx + minx) / 2.0;
    cy = (maxy + miny) / 2.0;
    cz = (maxz + minz) / 2.0;

    // ���㵥λ����������
    scale = 2.0 / max(max(w, h), d);

    // Χ�����Ľ���ƽ�ƣ�Ȼ������
    for (int i = 0; i < numVertices; i++)
    {
        vertices[3 * i + 0] -= cx;
        vertices[3 * i + 1] -= cy;
        vertices[3 * i + 2] -= cz;
        vertices[3 * i + 0] *= scale;
        vertices[3 * i + 1] *= scale;
        vertices[3 * i + 2] *= scale;
    }

    return;
}

Mesh* readPLY(const char* filename)
{
    Mesh* pModel = new Mesh;
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    char line[200];
    int numVertices = 0;
    bool header = true;

    // ���� PLY �ļ�ͷ
    while (header && fgets(line, 200, file))
    {
        if (strncmp(line, "element vertex", 14) == 0) {
            sscanf(line + 14, "%d", &numVertices);
        }
        if (strncmp(line, "end_header", 10) == 0) {
            header = false;
        }
    }

    // �����ڴ�
    pModel->numVertices = numVertices;
    pModel->vertices = new float[numVertices * 3];

    // ��ȡ��������
    float fx, fy, fz;
    int vcnt = 0;
    while (fgets(line, 200, file))
    {
        sscanf(line, "%f %f %f", &fx, &fy, &fz);
        pModel->vertices[vcnt * 3 + 0] = fx;
        pModel->vertices[vcnt * 3 + 1] = fy;
        pModel->vertices[vcnt * 3 + 2] = fz;
        vcnt++;
    }

    fclose(file);

    // ���������ȡ�Ķ�������
    printf("Number of vertices read: %d\n", numVertices);
    return pModel;
}

void drawMesh(Mesh* pMesh, bool displayNormals, bool displayColors)
{
    
    glBegin(GL_POINTS); // ʹ�õ�ģʽ����
    for (int i = 0; i < pMesh->numVertices; i++)
    {

        if (displayColors) {
            glDisable(GL_LIGHTING); // ���ù�����ȷ����ɫ��ʾ��ȷ
            glColor3f(pMesh->vertices[3 * i + 0], pMesh->vertices[3 * i + 1], pMesh->vertices[3 * i + 2]);
        }
        glVertex3fv(&pMesh->vertices[3 * i]); // ����ÿ������
    }
    glEnd();

    if (displayNormals && pMesh->facetnorms != NULL) {
        glDisable(GL_LIGHTING); // ���ù�����ȷ����ɫ��ʾ��ȷ
        glBegin(GL_LINES);
        for (int i = 0; i < pMesh->numVertices; i++) {
            float start[3] = { pMesh->vertices[3 * i + 0], pMesh->vertices[3 * i + 1], pMesh->vertices[3 * i + 2] };
            float end[3] = {
                start[0] + pMesh->facetnorms[3 * i + 0] * 0.1f,
                start[1] + pMesh->facetnorms[3 * i + 1] * 0.1f,
                start[2] + pMesh->facetnorms[3 * i + 2] * 0.1f
            };
            glColor3f(0.0f, 1.0f, 0.0f); // �ú�ɫ��ʾ����
            glVertex3fv(start);
            glVertex3fv(end);
        }
        glEnd();
    }
}

