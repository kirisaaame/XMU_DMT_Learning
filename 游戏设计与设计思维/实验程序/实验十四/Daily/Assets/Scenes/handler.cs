using System;
using System.IO;
using System.Text;
using UnityEngine;

public class JokeMerger : MonoBehaviour
{
    // 文件路径
    private string[] jokeFilePaths = new string[]
    {
        @"C:\Users\admin\Desktop\作业\游戏设计\实验十四\file1.txt",
        @"C:\Users\admin\Desktop\作业\游戏设计\实验十四\file2.txt",
        @"C:\Users\admin\Desktop\作业\游戏设计\实验十四\file3.txt",
        @"C:\Users\admin\Desktop\作业\游戏设计\实验十四\file4.txt",
        @"C:\Users\admin\Desktop\作业\游戏设计\实验十四\file5.txt"
    };

    void Start()
    {
        MergeJokes();
    }

    void MergeJokes()
    {
        string jokesDirectory = Application.dataPath + "/files";
        if (!Directory.Exists(jokesDirectory))
        {
            Directory.CreateDirectory(jokesDirectory);
        }

        string mergedFilePath = Path.Combine(jokesDirectory, "merged_jokes.txt");

        using (StreamWriter writer = new StreamWriter(mergedFilePath, false, Encoding.Unicode))
        {
            foreach (string filePath in jokeFilePaths)
            {
                if (File.Exists(filePath))
                {
                    string content = File.ReadAllText(filePath, Encoding.Unicode);
                    writer.WriteLine(content + "\n&\n");  // 使用&符号分隔笑话
                }
                else
                {
                    Debug.LogError("文件路径不存在: " + filePath);
                }
            }
        }
    }
}
