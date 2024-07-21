#include "OBJ.h"

Mesh::Mesh()
{

}

Mesh::~Mesh()
{
}

Mesh* readOBJ(char *sFileName)
{
	Mesh *pModel = new Mesh;
	char line[200];
	int numVertices = 0;
	int numFaces = 0;
	FILE *file = fopen(sFileName, "r"); // open a file
	
	// the fist pass: count the number of vertices and the number of faces
	while (true)
	{
		fgets(line, 200, file); // fgets routine reads a line in the file
		if (feof(file) != 0) // if come to the end of the file, break
			break;
		if (line[0] == 'v') // if the first charactor is 'v', this is the vertex command
			numVertices++;
		else if (line[0] == 'f') // if the first charactor is 'f', this is the face command
			numFaces++;
	}
	

	// allocate memory
	pModel->vertices.resize(numVertices);
	pModel->faces.resize(numFaces); 
	rewind(file); // reset the file pointer to the head of the file

	// the second pass: read the xyz coordinates for each vertex, and the three indexs for each face
	for (int i = 0; i < numVertices; i++)
	{
		float x, y, z;
		fscanf(file, "v %f %f %f\n", &x, &y, &z);
		pModel->vertices[i].x = x;
		pModel->vertices[i].y = y;
		pModel->vertices[i].z = z;
	}
	for (int i = 0; i < numFaces; i++)
	{
		int i0, i1, i2;
		fscanf(file, "f %d %d %d\n", &i0, &i1, &i2);
		// Note that the index starts from 1 in the OBJ file format, but starts from 0 in this program.
		pModel->faces[i].idx0 = i0 - 1; 
		pModel->faces[i].idx1 = i1 - 1;
		pModel->faces[i].idx2 = i2 - 1;
	}

	
	fclose(file);
	return pModel; // return the pointer to a Mesh instance
}

void writeOBJ(char *sFileName, Mesh *pMesh)
{
	FILE *file = fopen(sFileName, "w");
	for (int i = 0; i < pMesh->vertices.size(); i++)
	{
		fprintf(file, "v %f %f %f\n", pMesh->vertices[i].x, pMesh->vertices[i].y, pMesh->vertices[i].z);
	}
	for (int i = 0; i < pMesh->faces.size(); i++)
	{
		fprintf(file, "f %d %d %d\n", pMesh->faces[i].idx0 + 1, pMesh->faces[i].idx1 + 1, pMesh->faces[i].idx2 + 1);
	}

	fclose(file);
	return;
}

void Mesh::compute_neighbors()
{
	if (vertex_neighbors.empty() != true)
		vertex_neighbors.clear();
	if (vertex_face_neighbors.empty() != true)
		vertex_face_neighbors.clear();

	vertex_neighbors.resize(vertices.size());
	vertex_face_neighbors.resize(vertices.size());

	for (int i = 0; i < faces.size(); i++)
	{
		int idx0 = faces[i].idx0;
		int idx1 = faces[i].idx1;
		int idx2 = faces[i].idx2;

		vertex_neighbors[idx0].push_back(idx1);
		vertex_neighbors[idx0].push_back(idx2);
		vertex_face_neighbors[idx0].push_back(i);

		vertex_neighbors[idx1].push_back(idx0);
		vertex_neighbors[idx1].push_back(idx2);
		vertex_face_neighbors[idx1].push_back(i);

		vertex_neighbors[idx2].push_back(idx0);
		vertex_neighbors[idx2].push_back(idx1);
		vertex_face_neighbors[idx2].push_back(i);
	}

	return;
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


void Mesh::compute_normals()
{
	if (vertex_normals.empty() != true)
		vertex_normals.clear();
	if (face_normals.empty() != true)
		face_normals.clear();

	vertex_normals.resize(vertices.size());
	face_normals.resize(faces.size());

	float u[3];
	float v[3];
	float n[3];

	for (int i = 0; i < faces.size(); i++)
	{
		int idx0 = faces[i].idx0;
		int idx1 = faces[i].idx1;
		int idx2 = faces[i].idx2;

		u[0] = vertices[idx1].x - vertices[idx0].x;
		u[1] = vertices[idx1].y - vertices[idx0].y;
		u[2] = vertices[idx1].z - vertices[idx0].z;

		v[0] = vertices[idx2].x - vertices[idx0].x;
		v[1] = vertices[idx2].y - vertices[idx0].y;
		v[2] = vertices[idx2].z - vertices[idx0].z;

		cross(u, v, n);
		normalize(n);
		face_normals[i] = Normal(n);
	}

	return;
}
