import "@babylonjs/inspector";
import * as BABYLON from "@babylonjs/core";
import * as anu from "@jpmorganchase/anu";
import "@babylonjs/core/Materials/standardMaterial.js";
import { Vector3 } from "@babylonjs/core";
import installInteractions from "./interactions.js";

// ===== DOM & Canvas =====
const app = document.querySelector("#app");
const canvas = document.createElement("canvas");
canvas.style.width = "100vw";
canvas.style.height = "100vh";
canvas.style.display = "block";
app.appendChild(canvas);

// ===== Engine & Scene =====
const engine = new BABYLON.Engine(canvas, true);
let scene = new BABYLON.Scene(engine);

// ===== Light & Camera =====
new BABYLON.HemisphericLight("light1", new BABYLON.Vector3(0, 10, 0), scene);
const camera = new BABYLON.ArcRotateCamera(
  "Camera",
  -(Math.PI / 4) * 3,
  Math.PI / 4,
  18,
  new BABYLON.Vector3(0, 0, 0),
  scene
);
camera.position = new BABYLON.Vector3(-15, 12, -25);
camera.attachControl(canvas, true);

// 可选：环境（关闭地面，避免遮挡散点）
scene.createDefaultEnvironment({ createGround: false, createSkybox: false });

// ===== 安装动作系统交互示例 =====
function setupInteractions() {
  // 清理旧的 onPointerDown 绑定（如果场景重建过）
  scene.onPointerDown = null;
  try {
    if (typeof anu.setScene === "function") {
      anu.setScene(scene);
    }
  } catch {}
  installInteractions(scene);
}

setupInteractions();

// ===== 渲染循环 / Resize =====
engine.runRenderLoop(() => scene.render());
window.addEventListener("resize", () => engine.resize());

// ===== Inspector：Shift + I 显示/隐藏 =====
window.addEventListener("keydown", (ev) => {
  if (ev.key === "I" && ev.shiftKey) {
    if (scene.debugLayer.isVisible()) scene.debugLayer.hide();
    else scene.debugLayer.show();
  }
});

// Extra: R 重置场景（仅动作系统示例）
window.addEventListener("keydown", async (ev) => {
  const key = ev.key.toLowerCase();
  if (key === "r") {
    // 重建一个干净的场景并重新安装交互
    scene.dispose();
    scene = new BABYLON.Scene(engine);
    new BABYLON.HemisphericLight("light1", new BABYLON.Vector3(0, 10, 0), scene);
    const camera = new BABYLON.ArcRotateCamera(
      "Camera",
      -(Math.PI / 4) * 3,
      Math.PI / 4,
      18,
      new BABYLON.Vector3(0, 0, 0),
      scene
    );
    camera.position = new BABYLON.Vector3(-15, 12, -25);
    camera.attachControl(canvas, true);
    scene.createDefaultEnvironment({ createGround: false, createSkybox: false });
    setupInteractions();
  }
});
