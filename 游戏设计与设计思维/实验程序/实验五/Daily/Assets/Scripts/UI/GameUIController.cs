using UnityEngine;
using UnityEngine.UI;

public class GameUIController : MonoBehaviour
{
    public Slider healthSlider; // 血条Slider
    public Text healthText;     // 血量百分比文本
    public Slider controlSlider; // 控制条Slider
    public Camera Camera1; // 摄像机对象

    private void Update()
    {
        // 更新血量显示
        UpdateHealthUI();

        // 更新控制条显示
        UpdateControlUI();
    }

    // 更新血量显示
    private void UpdateHealthUI()
    {
        // 假设当前血量是从0到100之间的值，可以根据实际需求修改
        int healthValue = 75; // 假设当前血量为75

        healthSlider.value = healthValue ; // 将血量映射到Slider的值范围（0~1）
        healthText.text = healthValue.ToString() + "%"; // 更新血量百分比文本
    }

    private void UpdateControlUI()
    {
        // 获取当前控制条的值
        float controlValue = controlSlider.value;

        // 将控制条的值映射到摄像机正交大小的范围（例如，从5到15）
        float cameraFOV = Mathf.Lerp(30f, 90f, controlValue);

        // 设置摄像机的正交大小
        Camera1.fieldOfView = cameraFOV;
    }

    // 当控制条值发生变化时调用
    public void OnControlSliderValueChanged()
    {
        UpdateControlUI();
    }


}
