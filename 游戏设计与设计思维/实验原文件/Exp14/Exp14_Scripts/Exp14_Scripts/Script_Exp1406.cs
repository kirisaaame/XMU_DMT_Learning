using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using System.IO;
using System.Text;

public class Script_Exp1406 
{
	[MenuItem("Tool/File")]
	static void Start()
	{
		string path = Path.Combine (Application.dataPath, "test.txt");
		//文件如果存在删除它
		if (File.Exists (path)) {
			File.Delete (path);
		}

		//写入文件
		StringBuilder sb = new StringBuilder ();
		sb.AppendFormat ("第一行:{0}", 100).AppendLine ();
		sb.AppendFormat ("第二行:{0}", 200).AppendLine ();
		File.WriteAllText (path,sb.ToString());

		//读取文件
		Debug.Log (File.ReadAllText (path));
	}
}
