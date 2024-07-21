#ifndef OBJ_H
#define OBJ_H

class Mesh
{
public:
	Mesh();
	~Mesh();
	void compute_normal();
	void unitize();
	float* vertices;
	int* faces;
	float* facetnorms;
	int numVertices;
	int numFaces;
	int numTexcoords;
};

Mesh* readPLY(const char* filename);
void drawMesh(Mesh* pMesh, bool displayNormals, bool displayColors);

#endif
