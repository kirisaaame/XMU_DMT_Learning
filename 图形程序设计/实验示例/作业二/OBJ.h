#ifndef OBJ_H
#define OBJ_H


#include <stdio.h>


class Mesh
{
public:
	int numVertices;
	int numFaces;
	int numTexcoords;  

	float* vertices;
	int* faces;
	float* facetnorms; // facet normals
	float* texcoords;

	Mesh();
	~Mesh();

public:
	void compute_normal();
	void unitize();
};

Mesh* readOBJ(const char* filename);
void drawMesh(Mesh* pMesh);


#endif
