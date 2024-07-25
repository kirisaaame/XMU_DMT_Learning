#include "OBJ.h"

int main()
{
	Mesh *pNoisyMesh = readOBJ(".\\Noisy Mesh\\cube_n2.obj");

	
	delete pNoisyMesh;
	return 1;
}