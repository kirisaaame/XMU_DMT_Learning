using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using System;

public class Script_Exp1403  {

	[MenuItem("Excel/Json")]
	static void LoadJson () 
	{
		Data data = new Data ();
		data.name = "Data";
		data.subData.Add (new SubData (){ intValue = 1, boolValue = true, floatValue = 0.1f, stringValue = "one" });
		data.subData.Add (new SubData (){ intValue = 2, boolValue = true, floatValue = 0.1f, stringValue = "two" });

		string json =  JsonUtility.ToJson (data);
		Debug.Log (json);
		data = JsonUtility.FromJson<Data> (json);
		Debug.LogFormat ("name = {0}", data.name);
		foreach (var item in data.subData) {
			Debug.LogFormat ("intValue = {0} boolValue = {0} floatValue = {0} stringValue = {0}",
				item.intValue, item.boolValue, item.floatValue, item.stringValue);
		}
	}

	[Serializable]
	public class Data
	{
		public string name;
		public List<SubData> subData =new List<SubData>();
	}

	[Serializable]
	public class SubData
	{
		public int intValue;
		public bool boolValue;
		public float floatValue;
		public string stringValue;
	}
}
