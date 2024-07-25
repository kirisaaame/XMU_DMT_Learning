#include "OBJ.h"
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

Mesh::Mesh()
{
	vertices = NULL;
	faces = NULL;
	facetnorms = NULL;
	texcoords = NULL;
}

Mesh::~Mesh()
{
	if (vertices != NULL)
		delete vertices;
	if (faces != NULL)
		delete faces;
	if (facetnorms != NULL)
		delete facetnorms;
	if (texcoords != NULL)
		delete texcoords;
}

// compute the cross product of two vectors
static void cross(float* u, float* v, float* n)
{
	n[0] = u[1] * v[2] - u[2] * v[1];
	n[1] = u[2] * v[0] - u[0] * v[2];
	n[2] = u[0] * v[1] - u[1] * v[0];
	return;
}

// normalize a vector
static void normalize(float* v)
{
	float l;
	l = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	v[0] /= l;
	v[1] /= l;
	v[2] /= l;
	return;
}

void Mesh::compute_normal()
{
	if (facetnorms != NULL)
		delete facetnorms;

	float u[3];
	float v[3];
	float n[3];

	facetnorms = new float[numFaces * 3];

	for (int i = 0; i < numFaces; i++) 
	{
		int idx0, idx1, idx2;
		idx0 = faces[3 * i + 0];
		idx1 = faces[3 * i + 1];
		idx2 = faces[3 * i + 2];

		u[0] = vertices[3 * idx1 + 0] - vertices[3 * idx0 + 0];
		u[1] = vertices[3 * idx1 + 1] - vertices[3 * idx0 + 1];
		u[2] = vertices[3 * idx1 + 2] - vertices[3 * idx0 + 2];

		v[0] = vertices[3 * idx2 + 0] - vertices[3 * idx0 + 0];
		v[1] = vertices[3 * idx2 + 1] - vertices[3 * idx0 + 1];
		v[2] = vertices[3 * idx2 + 2] - vertices[3 * idx0 + 2];

		cross(u, v, n);
		normalize(n);
		facetnorms[3 * i + 0] = n[0];
		facetnorms[3 * i + 1] = n[1];
		facetnorms[3 * i + 2] = n[2];
	}

	return;
}

// returns the maximum of two floats 
static float max(float a, float b)
{
	if (b > a)
		return b;
	return a;
}

// returns the absolute value of a float 
static float abs(float f)
{
	if (f < 0)
		return -f;
	return f;
}

void Mesh::unitize()
{
	if (vertices == NULL)
		return;

	float maxx, minx, maxy, miny, maxz, minz;
	float cx, cy, cz, w, h, d;
	float scale;

	/* get the max/mins */
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

	/* calculate model width, height, and depth */
	w = abs(maxx) + abs(minx);
	h = abs(maxy) + abs(miny);
	d = abs(maxz) + abs(minz);

	/* calculate center of the model */
	cx = (maxx + minx) / 2.0;
	cy = (maxy + miny) / 2.0;
	cz = (maxz + minz) / 2.0;

	/* calculate unitizing scale factor */
	scale = 2.0 / max(max(w, h), d);

	/* translate around center then scale */
	for (int i = 0; i <numVertices; i++) 
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

Mesh* readOBJ(const char* filename)
{
	Mesh *pModel = new Mesh;
	FILE *file = fopen(filename, "r");
	char line[200];
	int numVertices = 0;
	int numFaces = 0;
	int numTexcoords = 0;

	// 第一次遍历，计算顶点数和面数
	while (true)
	{
		fgets(line, 200, file); // 读取一行
		if (feof(file) != 0) // 如果到达文件尾部，
			break;
		if (line[0] == '#')
			continue;
		if (line[0] == 'v') // if the first charactor is 'v', this is the vertex command
			numVertices++;
		if (line[0] == 'f') // if the first charactor is 'f', this is the face command
			numFaces++;
		if (line[0] == 'v' && line[1] == 't') // if the first charactor is 't', this is the texcoord command
			numTexcoords++;
	}

	// allocate memory
	pModel->numVertices = numVertices;
	pModel->numFaces = numFaces;
	pModel->numTexcoords = numTexcoords;
	pModel->vertices = new float[numVertices * 3]; // allocate memory to store all vertices
	pModel->faces = new int[numFaces * 3]; // allocate memory to store all faces
	pModel->texcoords = new float[numTexcoords * 2]; // allocate memory to store all texcoords
	rewind(file); // reset the file pointer to the head of the file


    // the second pass
	float fx, fy, fz;
	int idx0, idx1, idx2;
	float u, v;
	int vcnt = 0, fcnt = 0, tcnt = 0;


	while (true)
	{
		fgets(line, 200, file); // fgets routine reads a line in the file
		if (feof(file) != 0) // if come to the end of the file, break
			break;
		if (line[0] == '#') 
			continue;
		if (line[0] == 'v')
		{
			sscanf(line, "v %f %f %f", &fx, &fy, &fz);
			pModel->vertices[vcnt * 3 + 0] = fx;
			pModel->vertices[vcnt * 3 + 1] = fy;
			pModel->vertices[vcnt * 3 + 2] = fz;
			vcnt++;
		}
		if (line[0] == 'f') // if the first charactor is 'f', this is the face command
		{
			sscanf(line, "f %d %d %d", &idx0, &idx1, &idx2);
			pModel->faces[fcnt * 3 + 0] = idx0 - 1;
			pModel->faces[fcnt * 3 + 1] = idx1 - 1;
			pModel->faces[fcnt * 3 + 2] = idx2 - 1;
			fcnt++;
		}
		if (line[0] == 'v' && line[1] == 't') // if the first charactor is 't', this is the texcoord command
		{
			sscanf(line, "vt %f %f", &u, &v);
			v = 1.0f - v;
			pModel->texcoords[tcnt * 2 + 0] = u;
			pModel->texcoords[tcnt * 2 + 1] = v;
			tcnt++;
		}
	}

	fclose(file);
	return pModel;
}

void drawMesh(Mesh* pMesh)
{
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < pMesh->numFaces; i++)
	{
		int idx0 = pMesh->faces[3 * i + 0];
		int idx1 = pMesh->faces[3 * i + 1];
		int idx2 = pMesh->faces[3 * i + 2];

		glNormal3fv(&pMesh->facetnorms[3 * i]);

		glTexCoord2fv(&pMesh->texcoords[2 * idx0]);
		glVertex3fv(&pMesh->vertices[3 * idx0]);

		glTexCoord2fv(&pMesh->texcoords[2 * idx1]);
		glVertex3fv(&pMesh->vertices[3 * idx1]);

		glTexCoord2fv(&pMesh->texcoords[2 * idx2]);
		glVertex3fv(&pMesh->vertices[3 * idx2]);
	}

	glEnd();

	return;
}