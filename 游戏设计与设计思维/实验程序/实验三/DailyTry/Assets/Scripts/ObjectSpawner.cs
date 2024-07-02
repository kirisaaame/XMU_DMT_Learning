using System.Collections;
using UnityEngine;

public class ObjectSpawner : MonoBehaviour
{
    public GameObject prefab;
    public int initialObjectCount = 5;
    public float spawnInterval = 2f;
    public int totalObjectCount = 10;
    public float minScale = 0.5f;
    public float maxScale = 2.0f;
    public float moveSpeed = 1.0f;

    private GUIStyle guiStyle = new GUIStyle();
    private GameObject lastSpawnedObject;
    private int spawnedCount = 0;
    private float lastSpawnTime = 0f;
    private Camera mainCamera;

    void Start()
    {
        mainCamera = Camera.main;
        // ������ʱ����5������
        for (int i = 0; i < initialObjectCount; i++)
        {
            SpawnObject();
        }
    }

    void Update()
    {
        // ��������ɵ���������С���ܹ���Ҫ���ɵ��������Ҿ��ϴ�����ʱ���Ѿ������˼��ʱ��
        if (spawnedCount < totalObjectCount && Time.time - lastSpawnTime >= spawnInterval)
        {
            // ����һ������
            SpawnObject();
            lastSpawnTime = Time.time;
        }

        // �������λ�úͳ���
        if (lastSpawnedObject != null)
        {
            mainCamera.transform.LookAt(lastSpawnedObject.transform);
        }
    }

    void SpawnObject()
    {
        // ��������ɵ���������С���ܹ���Ҫ���ɵ�����
        if (spawnedCount < totalObjectCount)
        {
            Vector3 randomPosition = new Vector3(Random.Range(-10f, 10f), Random.Range(0f, 10f), Random.Range(-10f, 10f));
            GameObject newObject = Instantiate(prefab, randomPosition, Quaternion.identity);
            lastSpawnedObject = newObject;
            spawnedCount++;

            // �ø�����������˶�������
            StartCoroutine(RandomMovement(newObject));
        }
    }

    IEnumerator RandomMovement(GameObject obj)
    {
        while (true)
        {
            // ����ı������λ��
            Vector3 randomDirection = new Vector3(Random.Range(-1f, 1f), Random.Range(-1f, 1f), Random.Range(-1f, 1f)).normalized;
            obj.transform.position += randomDirection * moveSpeed * Time.deltaTime;

            // ����ı����������
            float randomScale = Random.Range(minScale, maxScale);
            obj.transform.localScale = new Vector3(randomScale, randomScale, randomScale);

            yield return null;
        }
    }

    void OnGUI()
    {
        if (lastSpawnedObject != null)
        {
            Vector3 screenPos = mainCamera.WorldToScreenPoint(lastSpawnedObject.transform.position);
            GUI.Label(new Rect(screenPos.x, Screen.height - screenPos.y, 200, 100),
                "Name: " + lastSpawnedObject.name + "\nPosition: " + lastSpawnedObject.transform.position.ToString() +
                "\nSize: " + lastSpawnedObject.transform.localScale.ToString(), guiStyle);
        }
    }

    void Awake()
    {
        guiStyle.fontSize = 20;
        guiStyle.normal.textColor = Color.white;
    }
}
