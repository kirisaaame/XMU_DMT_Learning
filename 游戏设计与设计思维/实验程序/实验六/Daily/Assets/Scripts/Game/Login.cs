using UnityEngine;
using TMPro;
using UnityEngine.SceneManagement;

public class Login : MonoBehaviour
{
    //ע����Ϣ
    public TMP_InputField inputName;
    public TMP_InputField inputPaswd;

    private string currentUsername;

    public void OnClick()
    {
        if (inputName.text.Trim() == "account" && inputPaswd.text.Trim() == "123456")
        {
            currentUsername = inputName.text.Trim();
            Debug.Log("��ǰ��¼�˺ţ�" + currentUsername);
            SceneManager.LoadScene("Menu");
        }
        else
        {
            Debug.Log("��¼ʧ��!");
        }
    }
}
