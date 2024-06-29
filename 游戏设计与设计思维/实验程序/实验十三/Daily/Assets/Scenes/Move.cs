using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Move : MonoBehaviour
{
    private AudioSource source;
    public AudioClip clip;
    public Rigidbody rb;
    // Start is called before the first frame update
    void Start()
    {
 
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetMouseButton(0))
        {
            rb.AddForce(0, 0,120);
            source=GetComponent<AudioSource>();
            source.PlayOneShot(clip,1.0f);
        }
    }
}
