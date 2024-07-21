#include "Smoothing.h"

void laplacial_smoothing(Mesh* pInputMesh, Mesh* pOutputMesh)
{
    // ������˹ƽ������
    float lambda = 0.5f;
    int iterNum = 25;

    // �������������������
    *pOutputMesh = *pInputMesh;

    // �����ھ���Ϣ
    pOutputMesh->compute_neighbors();

    // ���е���
    for (int iter = 0; iter < iterNum; ++iter)
    {
        // ���ݵ�ǰ����λ��
        std::vector<Point> originalVertices = pOutputMesh->vertices;

        // �������ж���
        for (int i = 0; i < pOutputMesh->vertices.size(); ++i)
        {
            Point& vertex = pOutputMesh->vertices[i];
            const std::vector<int>& neighbors = pOutputMesh->vertex_neighbors[i];

            // �����ھӵ�ƽ��λ��
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

            // ���¶���λ��
            vertex.x = vertex.x + lambda * (average.x - vertex.x);
            vertex.y = vertex.y + lambda * (average.y - vertex.y);
            vertex.z = vertex.z + lambda * (average.z - vertex.z);
        }
    }
}
