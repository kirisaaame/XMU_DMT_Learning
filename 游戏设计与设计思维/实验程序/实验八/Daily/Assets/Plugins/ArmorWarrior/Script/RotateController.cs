using UnityEngine;
using System.Collections;

public class RotateController : MonoBehaviour {

	private Vector2 startPos;

	void Update () {
		float moveX = 0f;
		if (Input.GetMouseButtonDown (0)) {
			startPos = Input.mousePosition;
		} else if (Input.GetMouseButton (0)) {
			moveX = Input.mousePosition.x - startPos.x;
			startPos = Input.mousePosition;
		} else if (Input.GetMouseButtonUp (0)) {
			startPos = Vector2.zero;
		}
			
		transform.Rotate(0, moveX, 0, Space.World);
	}
}
