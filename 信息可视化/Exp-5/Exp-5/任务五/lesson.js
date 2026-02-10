import { extent, scaleLinear, csvParse } from "d3";
import * as BABYLON from "@babylonjs/core";
import "@babylonjs/core/Materials/standardMaterial.js";

// lesson(scene, anu) -> loads iris.csv and creates a 3D scatter using anu binding
export default async function lesson(scene, anu) {
  // Ensure anu knows about the current scene if the API is available
  try {
    if (anu && typeof anu.setScene === "function") {
      anu.setScene(scene);
    }
  } catch {}
  // load CSV from public
  // In Vite, files under /public are served at the root: "/iris.csv"
  const res = await fetch("/iris.csv");
  if (!res.ok) throw new Error("无法加载 iris.csv: " + res.statusText);
  const text = await res.text();

  // Use robust CSV parser that handles quotes and header names
  const raw = csvParse(text);
  let iris = raw.map((d) => ({
    sepalLength: +d["Sepal.Length"],
    sepalWidth: +d["Sepal.Width"],
    petalLength: +d["Petal.Length"],
    petalWidth: +d["Petal.Width"],
    species: d["Species"],
  }));

  // Filter out any rows with missing values
  iris = iris.filter(
    (d) =>
      Number.isFinite(d.sepalLength) &&
      Number.isFinite(d.sepalWidth) &&
      Number.isFinite(d.petalLength) &&
      Number.isFinite(d.petalWidth)
  );

  console.log("iris count:", iris.length);

  if (!iris.length) {
    console.error("iris 数据为空，检查 CSV 路径或格式");
    return;
  }

  // compute extents
  const extentX = extent(iris, (d) => d.sepalLength);
  const extentY = extent(iris, (d) => d.petalLength);
  const extentZ = extent(iris, (d) => d.sepalWidth);

  const scaleX = scaleLinear().domain(extentX).range([-10, 10]).nice();
  const scaleY = scaleLinear().domain(extentY).range([-10, 10]).nice();
  const scaleZ = scaleLinear().domain(extentZ).range([-10, 10]).nice();

  console.log("extents", { extentX, extentY, extentZ });

  // create parent transform node
  const cot = anu.bind("cot");
  const spheres = cot.bind("sphere", { diameter: 0.5 }, iris);

  spheres
    .positionX((d, n, i) => scaleX(d.sepalLength))
    .positionY((d, n, i) => scaleY(d.petalLength))
    .positionZ((d, n, i) => scaleZ(d.sepalWidth))
  .material((d, n, i) => new BABYLON.StandardMaterial("myMaterial" + i, scene))
    // 只用红/绿两种颜色：这里按物种做二分类（setosa -> 绿，其他 -> 红）
    .diffuseColor((d) => (d.species === "setosa" ? BABYLON.Color3.Green() : BABYLON.Color3.Red()));

  // create axes using anu helper if available
  try {
    anu.createAxes(
      "axes",
      {
        scale: { x: scaleX, y: scaleY, z: scaleZ },
        parent: cot,
      }
    );
  } catch (e) {
    console.warn("anu.createAxes not available, skipping axes", e);
  }

  return { iris, scaleX, scaleY, scaleZ };
}
