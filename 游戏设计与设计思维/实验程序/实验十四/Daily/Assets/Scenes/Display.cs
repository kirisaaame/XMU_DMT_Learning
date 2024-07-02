using System;
using System.IO;
using System.Text;
using UnityEngine;
using UnityEngine.UI;

public class DisplayJokes : MonoBehaviour
{
    public Text jokeText;
    private string[] jokes;
    private int jokeIndex = 0;

    void Start()
    {
        string mergedFilePath = Application.dataPath + "/files/merged_jokes.txt";
        if (File.Exists(mergedFilePath))
        {
            string content = File.ReadAllText(mergedFilePath, Encoding.Unicode);
            jokes = content.Split(new string[] { "\n&\n" }, StringSplitOptions.RemoveEmptyEntries);
            if (jokes.Length > 0)
            {
                DisplayJoke(jokeIndex);
            }
            else
            {
                jokeText.text = "没有找到任何笑话内容。";
            }
        }
        else
        {
            jokeText.text = "合并后的笑话文件不存在。";
        }
    }

    public void DisplayJoke(int index)
    {
        if (index < 0 || index >= jokes.Length)
        {
            jokeText.text = "没有更多笑话了！";
            return;
        }

        jokeText.text = jokes[index];
    }

    public void NextJoke()
    {
        jokeIndex++;
        if (jokeIndex >= jokes.Length)
        {
            jokeIndex = 0; // 循环显示笑话
        }
        DisplayJoke(jokeIndex);
    }

    public void PreviousJoke()
    {
        jokeIndex--;
        if (jokeIndex < 0)
        {
            jokeIndex = jokes.Length - 1; // 循环显示笑话
        }
        DisplayJoke(jokeIndex);
    }
}
