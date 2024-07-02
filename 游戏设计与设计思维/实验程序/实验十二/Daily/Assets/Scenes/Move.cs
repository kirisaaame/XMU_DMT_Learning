using UnityEngine;
using UnityEngine.AI;

public class Move : MonoBehaviour
{
    public Transform ball; // С���Transform���
    private NavMeshAgent navMeshAgent; // �����������

    void Start()
    {
        navMeshAgent = ball.GetComponent<NavMeshAgent>();

        // ����Ƿ�ɹ���ȡ�� NavMeshAgent ���
        if (navMeshAgent == null)
        {
            Debug.LogError("NavMeshAgent component not found on the ball object.");
        }
    }


    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            RaycastHit hitInfo;

            if (Physics.Raycast(ray, out hitInfo))
            {
                // ���λ��
                Vector3 targetPosition = hitInfo.point;

                // �ƶ�С�򵽵��λ��
                MoveBall(targetPosition);
            }
        }
    }

    void MoveBall(Vector3 targetPosition)
    {
        // ����С���Ŀ��λ��
        navMeshAgent.SetDestination(targetPosition);
    }
}
