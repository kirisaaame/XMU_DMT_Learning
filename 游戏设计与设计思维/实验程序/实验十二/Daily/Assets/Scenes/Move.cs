using UnityEngine;
using UnityEngine.AI;

public class Move : MonoBehaviour
{
    public Transform ball; // 小球的Transform组件
    private NavMeshAgent navMeshAgent; // 导航代理组件

    void Start()
    {
        navMeshAgent = ball.GetComponent<NavMeshAgent>();

        // 检查是否成功获取了 NavMeshAgent 组件
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
                // 点击位置
                Vector3 targetPosition = hitInfo.point;

                // 移动小球到点击位置
                MoveBall(targetPosition);
            }
        }
    }

    void MoveBall(Vector3 targetPosition)
    {
        // 设置小球的目标位置
        navMeshAgent.SetDestination(targetPosition);
    }
}
