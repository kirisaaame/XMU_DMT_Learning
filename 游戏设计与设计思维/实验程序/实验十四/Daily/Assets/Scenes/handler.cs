using System;
using System.IO;
using System.Text;
using UnityEngine;

public class JokeMerger : MonoBehaviour
{
    // �ļ�·��
    private string[] jokeFilePaths = new string[]
    {
        @"C:\Users\admin\Desktop\��ҵ\��Ϸ���\ʵ��ʮ��\file1.txt",
        @"C:\Users\admin\Desktop\��ҵ\��Ϸ���\ʵ��ʮ��\file2.txt",
        @"C:\Users\admin\Desktop\��ҵ\��Ϸ���\ʵ��ʮ��\file3.txt",
        @"C:\Users\admin\Desktop\��ҵ\��Ϸ���\ʵ��ʮ��\file4.txt",
        @"C:\Users\admin\Desktop\��ҵ\��Ϸ���\ʵ��ʮ��\file5.txt"
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
                    writer.WriteLine(content + "\n&\n");  // ʹ��&���ŷָ�Ц��
                }
                else
                {
                    Debug.LogError("�ļ�·��������: " + filePath);
                }
            }
        }
    }
}
