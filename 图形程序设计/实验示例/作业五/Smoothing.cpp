#include "Smoothing.h"

void laplacial_smoothing(Mesh* pInputMesh, Mesh* pOutputMesh)
{
    // 拉普拉斯平滑参数
    float lambda = 0.5f;
    int iterNum = 25;

    // 复制输入网格到输出网格
    *pOutputMesh = *pInputMesh;

    // 计算邻居信息
    pOutputMesh->compute_neighbors();

    // 进行迭代
    for (int iter = 0; iter < iterNum; ++iter)
    {
        // 备份当前顶点位置
        std::vector<Point> originalVertices = pOutputMesh->vertices;

        // 遍历所有顶点
        for (int i = 0; i < pOutputMesh->vertices.size(); ++i)
        {
            Point& vertex = pOutputMesh->vertices[i];
            const std::vector<int>& neighbors = pOutputMesh->vertex_neighbors[i];

            // 计算邻居的平均位置
            Point average(0.0f, 0.0f, 0.0f);
            for (int neighborIdx : neighbors)
            {
                average.x += originalVertices[neighborIdx].x;
                average.y += originalVertices[neighborIdx].y;
                average.z += originalVertices[neighborIdx].z;
            }
            average.x /= neighbors.size();
            average.y /= neighbors.size();
            average.z /= neighbors.size();

            // 更新顶点位置
            vertex.x = vertex.x + lambda * (average.x - vertex.x);
            vertex.y = vertex.y + lambda * (average.y - vertex.y);
            vertex.z = vertex.z + lambda * (average.z - vertex.z);
        }
    }
}
