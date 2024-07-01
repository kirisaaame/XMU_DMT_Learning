using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using System.IO;
using OfficeOpenXml;

public class Script_Exp1401  {

	[MenuItem("Excel/Load Excel")]
	static void LoadExcel () 
	{
		string path = Application.dataPath+ "/Excel/test.xlsx";
		//读取Excel文件
		using (FileStream fs = new FileStream (path, FileMode.Open, FileAccess.Read, FileShare.ReadWrite)) {
			using (ExcelPackage excel = new ExcelPackage (fs)) {
				ExcelWorksheets workSheets = excel.Workbook.Worksheets;
				//遍历所有worksheets
				for (int i = 1; i <= workSheets.Count; i++) {
					ExcelWorksheet workSheet = workSheets [i];
					int colCount = workSheet.Dimension.End.Column;
					//获取当前sheet名
					Debug.LogFormat ("Sheet {0}", workSheet.Name);
					for (int row = 1, count = workSheet.Dimension.End.Row; row <= count; row++) {
						for (int col = 1; col <= colCount; col++) {
							//读取每个格子中的数据
							var text = workSheet.Cells [row, col].Text ?? "";
							Debug.LogFormat ("下标:{0},{1} 内容:{2}", row, col, text);
						}
					}
				}
			}
		}
	}
}
