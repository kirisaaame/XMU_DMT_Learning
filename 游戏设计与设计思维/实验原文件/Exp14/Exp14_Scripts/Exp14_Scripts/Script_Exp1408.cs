using System.Collections;
using UnityEngine;
using UnityEditor;

public class Script_Exp1408 : MonoBehaviour 
{
	void Start()
	{
		Setting setting = new Setting ();
		setting.stringValue = "测试字符串";
		setting.intValue = 10000;


		RecordUtil.Set("setting",JsonUtility.ToJson (setting));


	}

	private Setting m_Setting = null;
	void OnGUI()
	{
		if (GUILayout.Button ("<size=50>获取存档</size>")) {
			m_Setting = JsonUtility.FromJson<Setting> (RecordUtil.Get ("setting"));
		}
		if (m_Setting != null) {
			GUILayout.Label (string.Format ("<size=50> {0},{1} </size>", m_Setting.intValue, m_Setting.stringValue));
		}
	}


	void OnApplicationPause(bool pauseStatus)
	{
		//当游戏即将进入后台时，保存存档
		if (pauseStatus) {
			RecordUtil.Save ();
		}
	}



	[System.Serializable]
	class Setting
	{
		public string stringValue;
		public int intValue;
	}

}
