// import { MeshBuilder, Vector3, StandardMaterial, Color3, CreateBox } from "@babylonjs/core"
import { MeshBuilder, Vector3, StandardMaterial, Color3, Color4, CreateBox } from "@babylonjs/core";
import { extent, scaleLinear, map } from "d3"; 

export default async(scene, anu) => {
  if (!anu) {
    console.error("lesson: anu 未传入");
    return scene;
  }
  let res = await fetch("/iris.csv");
  let text = await res.text();
  // 简单解析 CSV → 数组
  let iris = text.trim().split("\n").slice(1).map(line => {
    let [sepalLength, sepalWidth, petalLength, petalWidth, species] = line.split(",").slice(1);
    return {
      sepalLength: +sepalLength,
      sepalWidth: +sepalWidth,
      petalLength: +petalLength,
      petalWidth: +petalWidth,
      species
    };
  });

let cot = anu.bind('cot');
let spheres = cot.bind('sphere', { diameter: 1 }, iris);

  return scene;
}

