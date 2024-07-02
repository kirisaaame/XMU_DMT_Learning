using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

[CustomEditor(typeof(HelperAxes))]
public class HelperAxesEditor : Editor
{
    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();

        HelperAxes helperAxes = (HelperAxes)target;

        // 创建输入框以调整坐标轴长度
        EditorGUI.BeginChangeCheck();
        float axisLength = EditorGUILayout.FloatField("Axis Length", helperAxes.axisLength);
        if (EditorGUI.EndChangeCheck())
        {
            // 更新坐标轴长度
            helperAxes.axisLength = Mathf.Max(axisLength, 0f);
        }

        // 创建输入框以调整立方体大小
        EditorGUI.BeginChangeCheck();
        float cubeSize = EditorGUILayout.FloatField("Cube Size", helperAxes.cubeSize);
        if (EditorGUI.EndChangeCheck())
        {
            // 更新立方体大小
            helperAxes.cubeSize = Mathf.Max(cubeSize, 0f);
        }
    }
}
