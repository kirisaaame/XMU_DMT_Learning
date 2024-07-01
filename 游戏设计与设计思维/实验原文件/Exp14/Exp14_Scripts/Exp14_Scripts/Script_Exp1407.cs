using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using System.Text;
using System;

public class Script_Exp1407:MonoBehaviour 
{
	//可读不可写
	string m_ResourcesTxt = string.Empty;
	//可读不可写
	string m_StreamingAssetsTxt = string.Empty;
	//可读可写
	string m_PersistentDataTxt = string.Empty;

	void Start()
	{
		m_ResourcesTxt = Resources.Load<TextAsset> ("test").text;
		m_StreamingAssetsTxt = File.ReadAllText (System.IO.Path.Combine (Application.streamingAssetsPath, "test.txt"));
	}

	void OnGUI()
	{
		GUILayout.Label (string.Format ("<size=50>Resources : {0}</size>",m_ResourcesTxt));
		GUILayout.Label (string.Format ("<size=50>StreamingAssets : {0}</size>",m_StreamingAssetsTxt));
		GUILayout.Label (string.Format ("<size=50>PersistentDataPath : {0}</size>",m_PersistentDataTxt));

		if (GUILayout.Button ("<size=50>写入并读取时间</size>")) {
			string path = Path.Combine (Application.persistentDataPath, "test.txt");
			File.WriteAllText (path,DateTime.Now.ToString());
			m_PersistentDataTxt = File.ReadAllText (path);
		}
	}
}
