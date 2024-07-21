#ifndef OBJ_H
#define OBJ_H

#include <stdio.h>
#include <vector>
using namespace std;

// the struct for vertex, each vertex has x,y,z coordinates
struct Point
{
	float x, y, z;
	int vidx;
	Point() { x = y = z = 0.0; }
	Point(float xi, float yi, float zi) {x = xi; y = yi; z = zi;}
};

// the struct for face, each face is a triangle and has three vertex indexs
struct Face
{
	int idx0, idx1, idx2;
	Face() { idx0 = idx1 = idx2 = 0; };
	Face(int i0, int i1, int i2) { idx0 = i0; idx1 = i1; idx2 = i2; }
};

// the struct for normal
struct Normal
{
	float nx, ny, nz;
	Normal() { nx = 1.0f; ny = nz = 0.0f; };
	Normal(float* n) { nx = n[0]; ny = n[1]; nz = n[2]; }
};

// the class for Mesh
class Mesh
{
public:
	Mesh();
	~Mesh();

	vector<Point> vertices;
	vector<Face> faces;
	vector<vector<int>> vertex_neighbors;
	vector<vector<int>> vertex_face_neighbors;
	vector<Normal> vertex_normals;
	vector<Normal> face_normals;

	void compute_neighbors();
	void compute_normals();
};

Mesh* readOBJ(char *sFileName);

void writeOBJ(char *sFileName, Mesh *pMesh);





#endif
