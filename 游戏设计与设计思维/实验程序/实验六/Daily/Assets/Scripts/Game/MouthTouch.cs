using UnityEngine;
using cakeslice;

public class MouseAndTouch : MonoBehaviour
{
    public Camera cameraToUse; // ָ�����ڷ������ߵ����
    private GameObject selectedObject; // ��ȡ������ָѡ�е�����

    void Update()
    {
        // �����
        if (Input.GetMouseButtonDown(0))
        {
            RaycastHit hit = CastRay(cameraToUse); // ������Ļ��������

            if (hit.collider != null)
            {
                if (hit.collider.CompareTag("Ground")) // ����������
                {
                    // �����ѡ�е�����
                    if (selectedObject != null)
                    {
                        // ��ѡ�е������ƶ������λ��
                        MoveSelectedObjectTo(hit.point);
                    }
                }
                else if (hit.collider.CompareTag("highLight")) // ��������������
                {
                    // ��ȡ�����������
                    selectedObject = hit.collider.gameObject;
                    // ѡ���򽫸����ű�����ΪTrue����״̬
                    selectedObject.GetComponent<Outline>().enabled = true;
                }
            }
        }
    }

    private RaycastHit CastRay(Camera cam)
    {
        Vector3 screenFar = new Vector3(Input.mousePosition.x, Input.mousePosition.y, cam.farClipPlane);
        Vector3 screenNear = new Vector3(Input.mousePosition.x, Input.mousePosition.y, cam.nearClipPlane);
        Vector3 worldFar = cam.ScreenToWorldPoint(screenFar); // ��Ļ����ײ�������
        Vector3 worldNear = cam.ScreenToWorldPoint(screenNear); // ��Ļ����������
        RaycastHit hit;
        Physics.Raycast(worldNear, worldFar - worldNear, out hit);

        return hit;
    }

    private void MoveSelectedObjectTo(Vector3 destination)
    {
        if (selectedObject != null)
        {
            selectedObject.transform.position = destination;
            selectedObject.GetComponent<Outline>().enabled = false; // �ƶ���ȡ������״̬
            selectedObject = null;
        }
    }
}
