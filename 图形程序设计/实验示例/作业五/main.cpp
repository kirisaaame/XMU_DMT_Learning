#include "OBJ.h"
#include "Smoothing.h"
#include <iostream>

int main()
{
    // �����������3Dģ��
    Mesh* pNoisyMesh = readOBJ(".\\Noisy Mesh\\cube_n2.obj");

    // ����һ�����Mesh����
    Mesh* pDenoisedMesh = new Mesh;

    // ��ģ�ͽ���������˹ƽ��ȥ��
    laplacial_smoothing(pNoisyMesh, pDenoisedMesh);

    // ����ȥ����3Dģ��
    writeOBJ(".\\Noisy Mesh\\denoised_cube.obj", pDenoisedMesh);
    std::cout << "������" << std::endl;

    // �ͷ��ڴ�
    delete pNoisyMesh;
    delete pDenoisedMesh;

    return 0;
}
