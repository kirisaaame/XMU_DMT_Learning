import * as anu from '@jpmorganchase/anu';
import { scaleLinear, extent, csvParse } from 'd3';
import {
  Engine,
  Scene,
  HemisphericLight,
  ArcRotateCamera,
  Vector3,
  TransformNode,
  Animation,
} from '@babylonjs/core';
import '@babylonjs/inspector';

// ===== DOM & Canvas =====
const app = document.querySelector('#app');
const canvas = document.createElement('canvas');
canvas.style.width = '100vw';
canvas.style.height = '100vh';
canvas.style.display = 'block';
app.appendChild(canvas);

// ===== Engine & Scene =====
const engine = new Engine(canvas, true);
const scene = new Scene(engine);
new HemisphericLight('light1', new Vector3(0, 10, 0), scene);
const camera = new ArcRotateCamera('Camera', -(Math.PI / 4) * 3, Math.PI / 4, 18, new Vector3(0, 0, 0), scene);
camera.position = new Vector3(-15, 12, -25);
camera.attachControl(canvas, true);

// 让 anu 关联当前 scene（若 API 存在）
try { if (typeof anu.setScene === 'function') anu.setScene(scene); } catch {}

// ===== 辅助：按域创建/切换坐标轴（交叉淡入/淡出） =====
function createAxesGrouped(scales) {
  const start = scene.meshes.length;
  const axes = anu.createAxes('axes_' + Date.now(), { scale: scales });
  const root = new TransformNode('axesRoot_' + Date.now(), scene);
  for (let i = start; i < scene.meshes.length; i++) scene.meshes[i].parent = root;
  return { root, axes };
}

let axesRoot = null;
let axesObj = null;
let isAnimating = false;
let pendingSwitch = null; // 当动画尚未完成时缓存一次后续切换请求

function switchAxes(domains, durationMs) {
  if (isAnimating) {
    // 缓存这次切换请求，等当前动画结束后再执行，避免“松开过快仍停留在4-10”
    pendingSwitch = { domains, durationMs };
    return;
  }
  isAnimating = true;

  const scales = {
    x: scaleLinear().domain(domains.x).range([-10, 10]).nice(),
    y: scaleLinear().domain(domains.y).range([-10, 10]).nice(),
    z: scaleLinear().domain(domains.z).range([-10, 10]).nice(),
  };
  const { root: newRoot, axes: newAxes } = createAxesGrouped(scales);
  // 过渡：新轴放大，旧轴缩小后销毁
  newRoot.scaling.set(0.001, 0.001, 0.001);
  const frames = Math.max(1, Math.round(durationMs / 16.67));
  Animation.CreateAndStartAnimation(
    'grow',
    newRoot,
    'scaling',
    60,
    frames,
    newRoot.scaling.clone(),
    new Vector3(1, 1, 1),
    Animation.ANIMATIONLOOPMODE_CONSTANT
  );
  const prevRoot = axesRoot;
  const prevAxes = axesObj;
  if (prevRoot) {
    Animation.CreateAndStartAnimation(
      'shrink',
      prevRoot,
      'scaling',
      60,
      frames,
      prevRoot.scaling.clone(),
      new Vector3(0.001, 0.001, 0.001),
      Animation.ANIMATIONLOOPMODE_CONSTANT,
      undefined,
      () => {
        try { prevAxes && typeof prevAxes.dispose === 'function' && prevAxes.dispose(); } catch {}
        prevRoot.dispose();
        isAnimating = false;
        // 若在动画期间接收到新的切换请求，则立刻执行
        if (pendingSwitch) {
          const next = pendingSwitch; pendingSwitch = null;
          switchAxes(next.domains, next.durationMs);
        }
    }
    );
  } else {
    // 首次创建，无需收尾
    setTimeout(() => {
      isAnimating = false;
      if (pendingSwitch) {
        const next = pendingSwitch; pendingSwitch = null;
        switchAxes(next.domains, next.durationMs);
      }
    }, durationMs);
  }
  axesRoot = newRoot;
  axesObj = newAxes;
}

// ===== 载入 iris.csv → 计算初始域 =====
async function init() {
  let iris = [];
  try {
    const res = await fetch('/iris.csv');
    const text = await res.text();
    const raw = csvParse(text);
    iris = raw.map(d => ({
      sepalLength: +d['Sepal.Length'],
      sepalWidth: +d['Sepal.Width'],
      petalLength: +d['Petal.Length'],
      petalWidth: +d['Petal.Width'],
      species: d['Species'],
    }));
  } catch (e) {
    console.warn('读取 iris.csv 失败，使用默认域 0-10：', e);
  }

  // 按需求：松开后应回到固定域 0-10（不使用数据的真实范围）
  const baseDomain = { x: [0, 10], y: [0, 10], z: [0, 10] };

  // 首次创建轴（原始域）
  switchAxes(baseDomain, 1);

  const pressedDomain = { x: [4, 10], y: [4, 10], z: [4, 10] };
  canvas.addEventListener('pointerdown', () => switchAxes(pressedDomain, 400));
  window.addEventListener('pointerup', () => switchAxes(baseDomain, 200));
}

init();

// ===== Render & Resize & Inspector =====
engine.runRenderLoop(() => scene.render());
window.addEventListener('resize', () => engine.resize());
window.addEventListener('keydown', (ev) => {
  if (ev.key === 'I' && ev.shiftKey) {
    if (scene.debugLayer.isVisible()) scene.debugLayer.hide();
    else scene.debugLayer.show();
  }
});
