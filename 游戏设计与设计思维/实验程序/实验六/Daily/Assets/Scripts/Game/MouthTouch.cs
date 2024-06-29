using UnityEngine;
using cakeslice;

public class MouseAndTouch : MonoBehaviour
{
    public Camera cameraToUse; // 指定用于发射射线的相机
    private GameObject selectedObject; // 获取鼠标或手指选中的物体

    void Update()
    {
        // 鼠标检测
        if (Input.GetMouseButtonDown(0))
        {
            RaycastHit hit = CastRay(cameraToUse); // 创建屏幕发射射线

            if (hit.collider != null)
            {
                if (hit.collider.CompareTag("Ground")) // 如果点击地面
                {
                    // 如果有选中的物体
                    if (selectedObject != null)
                    {
                        // 将选中的物体移动到点击位置
                        MoveSelectedObjectTo(hit.point);
                    }
                }
                else if (hit.collider.CompareTag("highLight")) // 如果点击高亮物体
                {
                    // 获取点击到的物体
                    selectedObject = hit.collider.gameObject;
                    // 选中则将高亮脚本设置为True激活状态
                    selectedObject.GetComponent<Outline>().enabled = true;
                }
            }
        }
    }

    private RaycastHit CastRay(Camera cam)
    {
        Vector3 screenFar = new Vector3(Input.mousePosition.x, Input.mousePosition.y, cam.farClipPlane);
        Vector3 screenNear = new Vector3(Input.mousePosition.x, Input.mousePosition.y, cam.nearClipPlane);
        Vector3 worldFar = cam.ScreenToWorldPoint(screenFar); // 屏幕到碰撞点的向量
        Vector3 worldNear = cam.ScreenToWorldPoint(screenNear); // 屏幕发射点的向量
        RaycastHit hit;
        Physics.Raycast(worldNear, worldFar - worldNear, out hit);

        return hit;
    }

    private void MoveSelectedObjectTo(Vector3 destination)
    {
        if (selectedObject != null)
        {
            selectedObject.transform.position = destination;
            selectedObject.GetComponent<Outline>().enabled = false; // 移动后取消高亮状态
            selectedObject = null;
        }
    }
}
