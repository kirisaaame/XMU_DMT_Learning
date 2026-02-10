import * as BABYLON from "@babylonjs/core";
import "@babylonjs/core/Materials/standardMaterial.js";
import "@babylonjs/core/Meshes/meshBuilder.js";
import { Vector3, Color3, MeshBuilder, ActionManager, ExecuteCodeAction } from "@babylonjs/core";

// 使用 Babylon 的动作系统：点击 Mesh 放大并改变颜色，再次点击还原
export default function installInteractions(scene) {
  const count = 10;

  for (let i = 0; i < count; i++) {
    const box = MeshBuilder.CreateBox(`box_${i}`, { size: 1 }, scene);
    box.position = new Vector3(
      (Math.random() - 0.5) * 8,
      (Math.random() - 0.5) * 8,
      (Math.random() - 0.5) * 8
    );

    // 基础材质
    const mat = new BABYLON.StandardMaterial(`mat_${i}`, scene);
    mat.diffuseColor = Color3.White();
    box.material = mat;

    // 启用动作管理器
    box.actionManager = box.actionManager || new ActionManager(scene);

    // 点击切换放大/颜色
    box.metadata = { toggled: false };
    box.actionManager.registerAction(
      new ExecuteCodeAction(ActionManager.OnPickTrigger, () => {
        box.metadata.toggled = !box.metadata.toggled;
        if (box.metadata.toggled) {
          box.scaling.set(1.8, 1.8, 1.8);
          mat.diffuseColor = Color3.Red();
        } else {
          box.scaling.set(1, 1, 1);
          mat.diffuseColor = Color3.White();
        }
      })
    );
  }
}
