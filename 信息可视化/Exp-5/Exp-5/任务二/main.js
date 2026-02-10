import "@babylonjs/inspector";
import * as BABYLON from "@babylonjs/core";
import * as anu from "@jpmorganchase/anu";
import "@babylonjs/core/Materials/standardMaterial.js";
import { Vector3 } from "@babylonjs/core";
import lesson from "./lesson.js";

// ===== DOM & Canvas =====
const app = document.querySelector("#app");
const canvas = document.createElement("canvas");
canvas.style.width = "100vw";
canvas.style.height = "100vh";
canvas.style.display = "block";
app.appendChild(canvas);

// ===== Engine & Scene =====
const engine = new BABYLON.Engine(canvas, true);
const scene = new BABYLON.Scene(engine);

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

// ===== 调用 lesson.js，渲染 Iris 方块 =====
(async () => {
  try {
    await lesson(scene, anu);
  } catch (e) {
    console.error("lesson 调用失败：", e);
  }
})();

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
