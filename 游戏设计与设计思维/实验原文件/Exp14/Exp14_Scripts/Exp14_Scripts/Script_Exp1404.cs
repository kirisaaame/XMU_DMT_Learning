using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Script_Exp1404 : MonoBehaviour  
{

	void Start()
	{
		PlayerPrefs.SetInt ("MyInt", 100);
		PlayerPrefs.SetFloat ("MyFloat", 200f);
		PlayerPrefs.SetString ("MyString", "雨松MOMO");

		Debug.Log(PlayerPrefs.GetInt ("MyInt", 0));
		Debug.Log(PlayerPrefs.GetFloat ("MyFloat", 0f));
		Debug.Log(PlayerPrefs.GetString ("MyString", "没有返回默认值"));


		//判断是否有某个key
		if (PlayerPrefs.HasKey ("MyInt")) {
		
		}
		//删除某个Key
		PlayerPrefs.DeleteKey ("MyInt");

		//删除所有Key
		PlayerPrefs.DeleteAll ();

		//强制保存数据
		PlayerPrefs.Save ();
	}

}
