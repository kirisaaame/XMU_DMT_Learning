using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

public class HelperAxes : MonoBehaviour
{
    // 坐标轴长度
    public float axisLength = 1.0f;

    // 立方体大小
    public float cubeSize = 0.1f;

    // 绘制坐标轴
    private void OnDrawGizmos()
    {
        DrawAxes();
    }

    // 显示全局坐标系
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

    // 隐藏全局坐标系
    [MenuItem("Custom/Hide Global Axes")]
    public static void HideGlobalAxes()
    {
        GameObject globalAxes = GameObject.Find("GlobalAxes");
        if (globalAxes != null)
        {
            DestroyImmediate(globalAxes);
        }
    }

    // 绘制坐标轴
    public void DrawAxes()
    {
        // 绘制 X 轴
        Debug.DrawLine(transform.position, transform.position + transform.right * axisLength, Color.red);
        Gizmos.DrawCube(transform.position + transform.right * axisLength, new Vector3(cubeSize, cubeSize, cubeSize));

        // 绘制 Y 轴
        Debug.DrawLine(transform.position, transform.position + transform.up * axisLength, Color.green);
        Gizmos.DrawCube(transform.position + transform.up * axisLength, new Vector3(cubeSize, cubeSize, cubeSize));

        // 绘制 Z 轴
        Debug.DrawLine(transform.position, transform.position + transform.forward * axisLength, Color.blue);
        Gizmos.DrawCube(transform.position + transform.forward * axisLength, new Vector3(cubeSize, cubeSize, cubeSize));
    }
}
