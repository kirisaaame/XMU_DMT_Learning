using UnityEngine;
using System.IO;
using System.Xml;

public class Script_Exp1409: MonoBehaviour 
{
    void Start()
    {
        //创建XmlDocument
        XmlDocument xmlDoc = new XmlDocument();
        XmlDeclaration xmlDeclaration = xmlDoc.CreateXmlDeclaration("1.0", "UTF-8", null);
        xmlDoc.AppendChild(xmlDeclaration);

        //节点中写入数据
        XmlElement root = xmlDoc.CreateElement("XmlRoot");     
        xmlDoc.AppendChild(root);                          
        XmlElement group = xmlDoc.CreateElement("Group");     
        group.SetAttribute("username", "雨松momo");           
        group.SetAttribute("password", "123456");
        root.AppendChild(group);

        //读取节点并输出xml字符串
        using (StringWriter stringwriter = new StringWriter())
        {
            using (XmlTextWriter xmlTextWriter = new XmlTextWriter(stringwriter))
            {
                xmlDoc.WriteTo(xmlTextWriter);
                xmlTextWriter.Flush();
                Debug.Log(stringwriter.ToString());
            }
        }
    }
}
