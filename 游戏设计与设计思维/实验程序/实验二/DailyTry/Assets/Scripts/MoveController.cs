using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoveController : MonoBehaviour
{
    float moveSpeed = 10f;
    float rotateSpeed = 1000f;
    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        //获取横轴参数
        float Horizontal = Input.GetAxis("Horizontal");
        //获取垂直参数
        float Vertical = Input.GetAxis("Vertical");

        //键盘ADWS键控制物体移动。
        //通过乘于Time.deltaTime，就可以让物体以每秒moveSpeed单位的速度向前移动
        transform.Translate(new Vector3(Horizontal * Time.deltaTime * moveSpeed, 0, Vertical * Time.deltaTime * moveSpeed));

        //左键鼠标点击状态下移动鼠标旋转
        if (Input.GetMouseButton(0))
        {
            //通过获取鼠标XY轴移动数值控制物体旋转
            transform.Rotate(new Vector3(Input.GetAxis("Mouse X") * Time.deltaTime * rotateSpeed, Input.GetAxis("Mouse Y") * Time.deltaTime * rotateSpeed));
        }

        //通过获取鼠标中键滑动值控制物体缩放
        transform.localScale += Vector3.one * Input.GetAxis("Mouse ScrollWheel");
    }
}