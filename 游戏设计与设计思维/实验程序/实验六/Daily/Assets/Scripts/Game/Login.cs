using UnityEngine;
using TMPro;
using UnityEngine.SceneManagement;

public class Login : MonoBehaviour
{
    //×¢²áÐÅÏ¢
    public TMP_InputField inputName;
    public TMP_InputField inputPaswd;

    private string currentUsername;

    public void OnClick()
    {
        if (inputName.text.Trim() == "account" && inputPaswd.text.Trim() == "123456")
        {
            currentUsername = inputName.text.Trim();
            Debug.Log("µ±Ç°µÇÂ¼ÕËºÅ£º" + currentUsername);
            SceneManager.LoadScene("Menu");
        }
        else
        {
            Debug.Log("µÇÂ¼Ê§°Ü!");
        }
    }
}
