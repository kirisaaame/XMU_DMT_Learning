using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

public class HelperAxes : MonoBehaviour
{
    // �����᳤��
    public float axisLength = 1.0f;

    // �������С
    public float cubeSize = 0.1f;

    // ����������
    private void OnDrawGizmos()
    {
        DrawAxes();
    }

    // ��ʾȫ������ϵ
    [MenuItem("Custom/Show Global Axes")]
    public static void ShowGlobalAxes()
    {
        GameObject globalAxes = GameObject.Find("GlobalAxes");
        if (globalAxes == null)
        {
            globalAxes = new GameObject("GlobalAxes");
            HelperAxes helperAxes = globalAxes.AddComponent<HelperAxes>();
            helperAxes.DrawAxes();
        }
        else
        {
            HelperAxes helperAxes = globalAxes.GetComponent<HelperAxes>();
            if (helperAxes != null)
            {
                helperAxes.DrawAxes();
            }
        }
    }

    // ����ȫ������ϵ
    [MenuItem("Custom/Hide Global Axes")]
    public static void HideGlobalAxes()
    {
        GameObject globalAxes = GameObject.Find("GlobalAxes");
        if (globalAxes != null)
        {
            DestroyImmediate(globalAxes);
        }
    }

    // ����������
    public void DrawAxes()
    {
        // ���� X ��
        Debug.DrawLine(transform.position, transform.position + transform.right * axisLength, Color.red);
        Gizmos.DrawCube(transform.position + transform.right * axisLength, new Vector3(cubeSize, cubeSize, cubeSize));

        // ���� Y ��
        Debug.DrawLine(transform.position, transform.position + transform.up * axisLength, Color.green);
        Gizmos.DrawCube(transform.position + transform.up * axisLength, new Vector3(cubeSize, cubeSize, cubeSize));

        // ���� Z ��
        Debug.DrawLine(transform.position, transform.position + transform.forward * axisLength, Color.blue);
        Gizmos.DrawCube(transform.position + transform.forward * axisLength, new Vector3(cubeSize, cubeSize, cubeSize));
    }
}
