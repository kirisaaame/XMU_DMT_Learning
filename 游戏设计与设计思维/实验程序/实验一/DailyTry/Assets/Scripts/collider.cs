using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class collider : MonoBehaviour
{

    // Use this for initialization
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {

    }

    private void OnCollisionEnter(Collision collision)
    {
        Debug.Log("开始碰撞:" + collision.collider.gameObject.name);
    }

    private void OnCollisionStay(Collision collision)
    {
        Debug.Log("持续碰撞:" + collision.collider.gameObject.name);
    }

    private void OnCollisionExit(Collision collision)
    {
        Debug.Log("结束碰撞:" + collision.collider.gameObject.name);
    }
}

