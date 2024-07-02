using UnityEngine;
using UnityEngine.UI;

public class GameUIController : MonoBehaviour
{
    public Slider healthSlider; // Ѫ��Slider
    public Text healthText;     // Ѫ���ٷֱ��ı�
    public Slider controlSlider; // ������Slider
    public Camera Camera1; // ���������

    private void Update()
    {
        // ����Ѫ����ʾ
        UpdateHealthUI();

        // ���¿�������ʾ
        UpdateControlUI();
    }

    // ����Ѫ����ʾ
    private void UpdateHealthUI()
    {
        // ���赱ǰѪ���Ǵ�0��100֮���ֵ�����Ը���ʵ�������޸�
        int healthValue = 75; // ���赱ǰѪ��Ϊ75

        healthSlider.value = healthValue ; // ��Ѫ��ӳ�䵽Slider��ֵ��Χ��0~1��
        healthText.text = healthValue.ToString() + "%"; // ����Ѫ���ٷֱ��ı�
    }

    private void UpdateControlUI()
    {
        // ��ȡ��ǰ��������ֵ
        float controlValue = controlSlider.value;

        // ����������ֵӳ�䵽�����������С�ķ�Χ�����磬��5��15��
        float cameraFOV = Mathf.Lerp(30f, 90f, controlValue);

        // �����������������С
        Camera1.fieldOfView = cameraFOV;
    }

    // ��������ֵ�����仯ʱ����
    public void OnControlSliderValueChanged()
    {
        UpdateControlUI();
    }


}
