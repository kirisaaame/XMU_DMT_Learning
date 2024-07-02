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
        //��ȡ�������
        float Horizontal = Input.GetAxis("Horizontal");
        //��ȡ��ֱ����
        float Vertical = Input.GetAxis("Vertical");

        //����ADWS�����������ƶ���
        //ͨ������Time.deltaTime���Ϳ�����������ÿ��moveSpeed��λ���ٶ���ǰ�ƶ�
        transform.Translate(new Vector3(Horizontal * Time.deltaTime * moveSpeed, 0, Vertical * Time.deltaTime * moveSpeed));

        //��������״̬���ƶ������ת
        if (Input.GetMouseButton(0))
        {
            //ͨ����ȡ���XY���ƶ���ֵ����������ת
            transform.Rotate(new Vector3(Input.GetAxis("Mouse X") * Time.deltaTime * rotateSpeed, Input.GetAxis("Mouse Y") * Time.deltaTime * rotateSpeed));
        }

        //ͨ����ȡ����м�����ֵ������������
        transform.localScale += Vector3.one * Input.GetAxis("Mouse ScrollWheel");
    }
}