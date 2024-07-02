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

        // ����������Ե��������᳤��
        EditorGUI.BeginChangeCheck();
        float axisLength = EditorGUILayout.FloatField("Axis Length", helperAxes.axisLength);
        if (EditorGUI.EndChangeCheck())
        {
            // ���������᳤��
            helperAxes.axisLength = Mathf.Max(axisLength, 0f);
        }

        // ����������Ե����������С
        EditorGUI.BeginChangeCheck();
        float cubeSize = EditorGUILayout.FloatField("Cube Size", helperAxes.cubeSize);
        if (EditorGUI.EndChangeCheck())
        {
            // �����������С
            helperAxes.cubeSize = Mathf.Max(cubeSize, 0f);
        }
    }
}
