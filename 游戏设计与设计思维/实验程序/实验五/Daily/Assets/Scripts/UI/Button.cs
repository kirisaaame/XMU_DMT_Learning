using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Button : MonoBehaviour
{
    // Start is called before the first frame update
   public void StartGame()
    {
        SceneManager.LoadScene("Game");
    }
    public void BackHome()
    {
        SceneManager.LoadScene("Menu");
    }
}
