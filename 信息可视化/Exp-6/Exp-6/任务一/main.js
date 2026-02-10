import * as anu from '@jpmorganchase/anu';
import "@babylonjs/core/Debug/debugLayer";
import "@babylonjs/inspector";
import { HemisphericLight, ArcRotateCamera, Vector3, Scene,Color4, Engine, Color3} from '@babylonjs/core';
import { AdvancedDynamicTexture, TextBlock, Control } from '@babylonjs/gui';

// import { MeshBuilder, Vector3, StandardMaterial, Color3,  CreateBox } from "@babylonjs/core";


//Grab DOM element where we will attach our canvas. #app is the id assigned to an empty <div> in our index.html 
const app = document.querySelector('#app');
//Create a canvas element and append it to #app div
const canvas = document.createElement('canvas');
app.appendChild(canvas);

//initialize babylon engine, passing in our target canvas element, and create a new scene
const babylonEngine = new Engine(canvas, true)

//create a scene object using our engine
const scene = new Scene(babylonEngine)


//Add lights and a camera
new HemisphericLight('light1', new Vector3(0, 10, 0), scene)
const camera = new ArcRotateCamera("Camera", -(Math.PI / 4) * 3, Math.PI / 4, 10, new Vector3(0, 0, 0), scene);
camera.position = new Vector3(-10, 10, -20)
camera.attachControl(canvas, true)


// 不再加载 lesson 示例，避免出现额外的球体

// ===== HUD 文本（GUI）：支持中文，初始显示学号姓名；按下显示课程；松开清空 =====
const ui = AdvancedDynamicTexture.CreateFullscreenUI('hud', true, scene);
const hudText = new TextBlock('hudText');
hudText.text = '李林江-37220222203661';
hudText.color = 'white';
hudText.fontSize = 22;
hudText.fontFamily = "Microsoft YaHei, 'Noto Sans SC', 'PingFang SC', 'Hiragino Sans GB', 'Source Han Sans SC', 'Microsoft JhengHei', 'Arial Unicode MS', sans-serif";
hudText.textHorizontalAlignment = Control.HORIZONTAL_ALIGNMENT_LEFT;
hudText.textVerticalAlignment = Control.VERTICAL_ALIGNMENT_TOP;
hudText.paddingLeft = '12px';
hudText.paddingTop = '12px';
ui.addControl(hudText);

canvas.addEventListener('pointerdown', () => {
  hudText.text = '信息可视化';
  hudText.color = 'red';
});
window.addEventListener('pointerup', () => {
  hudText.text = '';
});


//Render the scene we created
babylonEngine.runRenderLoop(() => {
  scene.render()
})

//Listen for window size changes and resize the scene accordingly 
window.addEventListener("resize", function () {
  babylonEngine.resize();
});


scene.debugLayer.show({embedMode: true});


// hide/show the Inspector with i
window.addEventListener("keydown", (ev) => {
    if (ev.key == 'I') {
        if (scene.debugLayer.isVisible()) {
            scene.debugLayer.hide();
        } else {
            scene.debugLayer.show({embedMode: true});
        }
    }
});
