using UnityEngine;
using System.IO;
using System.Xml;
using UnityEditor;

public class Script_Exp1411  
{
    [MenuItem("XML/WriteXml")]
    static void WriteXml()
    {
        string xmlPath = Path.Combine(Application.dataPath, "test.xml");
        //如果xml已经存在删除它
        if(File.Exists(xmlPath))
        {
            File.Delete(xmlPath);
        }
        //创建XmlDocument
        XmlDocument xmlDoc = new XmlDocument();
        XmlDeclaration xmlDeclaration = xmlDoc.CreateXmlDeclaration("1.0", "UTF-8", null);
        xmlDoc.AppendChild(xmlDeclaration);

        //节点中写入数据
        XmlElement root = xmlDoc.CreateElement("XmlRoot");
        xmlDoc.AppendChild(root);

        //循环写入3条数据
        for (int i = 0; i < 3; i++)
        {
            XmlElement group = xmlDoc.CreateElement("Group");
            group.SetAttribute("id",i.ToString());
            group.SetAttribute("username", "雨松momo");
            group.SetAttribute("password", "123456");
            root.AppendChild(group);
        }
        //写入文件
        xmlDoc.Save(xmlPath);
        AssetDatabase.Refresh();
    }

    [MenuItem("XML/LoadXml")]
    static void LoadXml()
    {
        string xmlPath = Path.Combine(Application.dataPath, "test.xml");
        //xml文件只有存在才能读取
        if (File.Exists(xmlPath))
        {
            XmlDocument xmlDoc = new XmlDocument();
            xmlDoc.Load(xmlPath);
            //遍历节点
            XmlNode nodes = xmlDoc.SelectSingleNode("XmlRoot");
            foreach (XmlNode node in nodes.ChildNodes)
            {
                string id = node.Attributes["id"].Value;
                string username = node.Attributes["username"].Value;
                string password = node.Attributes["password"].Value;
                Debug.LogFormat("id={0} username={1} password={2}", id,username, password);
            }
        }
    }
}
