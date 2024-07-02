using UnityEngine;
using System.IO;
using System.Xml;

public class Script_Exp1410 : MonoBehaviour 
{
    void Start()
    {
        //xml字符串
        string xml ="<?xml version=\"1.0\" encoding=\"UTF-8\"?><XmlRoot><Group username=\"雨松momo\" password=\"123456\" /></XmlRoot>";

        //读取字符串xml
        XmlDocument xmlDoc = new XmlDocument();
        xmlDoc.LoadXml(xml);
        //遍历节点
        XmlNode nodes = xmlDoc.SelectSingleNode("XmlRoot");
        foreach (XmlNode node in nodes.ChildNodes)
        {
            string username = node.Attributes["username"].Value;
            string password = node.Attributes["password"].Value;
            Debug.LogFormat("username={0} password={1}", username, password);
            //修改其中一条数据
            node.Attributes["password"].Value = "88888888";
        }

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
