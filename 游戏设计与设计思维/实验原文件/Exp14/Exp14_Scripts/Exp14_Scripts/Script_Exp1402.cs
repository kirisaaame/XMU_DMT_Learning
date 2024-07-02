using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using System.IO;
using OfficeOpenXml;
using System;

public class Script_Exp1402  {

	[MenuItem("Excel/Write Excel")]
	static void LoadExcel () 
	{
		//创建Excel文件
		string path = Application.dataPath+ "/Excel/"+DateTime.Now.ToString("yyyy-MM-dd--hh-mm-ss")+".xlsx";
		var file = new FileInfo(path);
	
		using (ExcelPackage excel = new ExcelPackage (file)) {
			//向表格中写入数据
			ExcelWorksheet worksheet = excel.Workbook.Worksheets.Add("sheet1");
			worksheet.Cells[1, 1].Value = "Company name1";
			worksheet.Cells[1, 2].Value = "Address1";

			worksheet = excel.Workbook.Worksheets.Add("sheet2");
			worksheet.Cells[1, 1].Value = "Company name2";
			worksheet.Cells[1, 2].Value = "Address2";
			//保存
			excel.Save();
		}
		AssetDatabase.Refresh ();
	}
}
