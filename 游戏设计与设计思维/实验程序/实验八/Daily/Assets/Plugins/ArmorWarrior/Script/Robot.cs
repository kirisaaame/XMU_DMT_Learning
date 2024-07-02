using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Robot : MonoBehaviour
{
    public float speed = 0.05f;//控制移动速度
    public Transform m_transform;
    void Start()
    {
        m_transform = this.transform;
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.A))
        {

            m_transform.Translate(Vector3.left * Time.deltaTime * speed);
            GetComponent<Animator>().SetTrigger("Wark");
        }

        //向右
        if (Input.GetKey(KeyCode.D))
        {

            m_transform.Translate(Vector3.right * Time.deltaTime * speed);
            GetComponent<Animator>().SetTrigger("Wark");
        }
        //向前
        if (Input.GetKey(KeyCode.W))
        {

            m_transform.Translate(Vector3.forward * Time.deltaTime * speed);
            GetComponent<Animator>().SetTrigger("Wark");
        }
        //向后
        if (Input.GetKey(KeyCode.S))
        {

            m_transform.Translate(Vector3.back * Time.deltaTime * speed);
            GetComponent<Animator>().SetTrigger("Wark");
        }
        if (Input.GetKeyDown(KeyCode.Space))
        {
            GetComponent<Animator>().SetTrigger("Jump");
        }
       
        if (Input.GetKeyDown(KeyCode.U))
        {
            GetComponent<Animator>().SetTrigger("Attack");
        }

    }

}
