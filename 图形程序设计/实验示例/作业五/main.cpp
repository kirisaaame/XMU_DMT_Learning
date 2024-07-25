#include "OBJ.h"
#include "Smoothing.h"
#include <iostream>

int main()
{
    // 读入带噪声的3D模型
    Mesh* pNoisyMesh = readOBJ(".\\Noisy Mesh\\cube_n2.obj");

    // 创建一个输出Mesh对象
    Mesh* pDenoisedMesh = new Mesh;

    // 对模型进行拉普拉斯平滑去噪
    laplacial_smoothing(pNoisyMesh, pDenoisedMesh);

    // 保存去噪后的3D模型
    writeOBJ(".\\Noisy Mesh\\denoised_cube.obj", pDenoisedMesh);
    std::cout << "输出完成" << std::endl;

    // 释放内存
    delete pNoisyMesh;
    delete pDenoisedMesh;

    return 0;
}
