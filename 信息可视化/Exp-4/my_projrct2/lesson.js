import { MeshBuilder, Vector3, StandardMaterial, Color3, Color4 } from "@babylonjs/core";

export default async (scene, anu) => {
  if (!anu) {
    console.error("lesson: anu 未传入");
    return scene;
  }

  // 读取 iris.csv
  const res = await fetch("/iris.csv");       // 若 csv 和 index.html 同级，也可用 fetch("iris.csv")
  const text = await res.text();

  // 简单解析 CSV → 数组（跳过表头）
  const iris = text.trim().split("\n").slice(1).map(line => {
    const [sepalLength, sepalWidth, petalLength, petalWidth, species] = line.split(",").slice(1);
    return {
      sepalLength: +sepalLength, sepalWidth: +sepalWidth,
      petalLength: +petalLength, petalWidth: +petalWidth,
      species
    };
  });

  // 绑定容器
  const cot = anu.bind("cot");

  // 用 box 代替 sphere
  const boxes = cot.bind("box", { size: 1 }, iris);

  boxes
    // 位置：用三个特征映射到 x/y/z
    .prop("position", (d, n, i) => new Vector3(d.sepalLength, d.sepalWidth, d.petalWidth))
    // 统一把方块缩小一些，避免太大遮挡
    .prop("scaling", new Vector3(0.1, 0.1, 0.1))
    // 命名（可在 Inspector 里检索）
    .prop("name", (d, n, i) => "iris_box:" + i)
    // 可见的轮廓线（可按需关闭）
    .prop("renderOutline", true);

  return scene;
}
