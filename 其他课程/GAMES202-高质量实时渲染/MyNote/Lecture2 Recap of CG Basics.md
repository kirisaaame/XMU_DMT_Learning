# Contents

(*p.s:可以挑战Assignment 0了*)

- Basic GPU Hardware Pipeline
- OpenGL
- OpenGL Shading Language (GLSL)
- The Rendering Equation

## 基本GPU渲染管线 (Basic GPU Hardware Pipeline)

1. **顶点处理 (Vertex Processing)**
   在这一部分（顶点着色器）进行顶点位置的变换(Transform部分)。如果进行Gauroud着色的话，也是在顶点着色器进行处理。
2. **三角形处理 (Triangle Processing)**
部分渲染引擎可能采用四边形处理，但是常用的是三角形处理。我们使用VBO进行顶点数据的存储，然后使用VAO对VBO进行解释，指定VBO中数据分别属于哪种顶点属性。我们还声明一个顶点索引数组EBO，对三角形的不同顶点编号，方便绘制时调用。
3.****光栅化 (Rasterization)**
由片元着色器（Fragment Shader）进行这一阶段的处理。前面提到的深度测试（Depth Test : Z-buffering），着色模型(Shading Model)：比如说Blinn Phong Shading。等等都在这一步完成
4.**片元处理 (Fragment Processing)**
包括纹理映射和插值等等都在这一步完成，并且同样在片元着色器完成。
5.**帧缓存操作 (Framebuffer Operations)**
片元着色器将处理好的所有片元写进帧缓存，进行后处理(Postprocessing)然后渲染在屏幕上。比如说双缓冲等方法的应用等。

## OpenGL

OpenGL类似于图形学开发的前端语言，和DirectX，Vulkan一样。这是因为OpenGL这样的语言只负责操控CPU向GPU发送指令，至于如何执行则在GPU独立实现（比如现在的可编程GPU，PGPU）

OpenGL相比DirectX，Vulkan有几个比较落后的地方：

- OpenGL是完全C风格的。也就是说，OpenGL是完全面向过程的，没有面向对象的方法。
- OpenGL编写的Shader以.vx，.fx的独特文件形式进行存储，进行调试非常困难，无法断点调试。
- OpenGL不同版本不是依次迭代的，有很多不同的版本有各自独立的特性（像glut和glad就非常不同），而像DirectX这样的则有专人维护迭代版本，而且还向下兼容。

## 着色语言GLSL

GLSL是OpenGL的着色器语言，对应DirectX中的HLSL，其组成包含以下部分：

1. **模型/物体 的声明**
2. **VBO（顶点数据缓存）**
3. **VAO（顶点属性缓存）**
4. **EBO（顶点索引缓存）**
5. **数学部分（坐标转换(transformation)，插值等等计算函数）**
6. **渲染参数传递（纹理绑定、着色器复用，多着色器）**
7. **帧缓存和显示（垂直同步，双缓冲）**

使用GLSL的一般过程是：

1. **创建并编辑着色器**
2. **编译着色器**
3. **绑定着色器和工程**
4. **连接着色器和物体**
5. **使用着色器进行渲染**
*p.s.:垂直同步防止画面撕裂，让游戏帧率小于等于显示器的刷新率。*

## Kajiya的渲染方程 (The Rendering Equation)

### 标准Kajiya渲染方程

Kajiya的渲染方程如下：
$$
    L_o (p,\omega_0) = L_e (p,\omega_0) + \int _{H^2}f_r(p,w_i ,w_o)L_i(p,\omega_i)cos\theta_id\omega_i
$$
解释：

- **$ L_o (p,\omega_0)$：视图中所见的光，即最终渲染结果**
- **$L_e (p,\omega_0)$：向目标方向的自发光项**
- **$f_r(p,w_i ,w_o)$：常数项，物体的BRDF，由物体材质和表面纹理决定。**
- **$L_i(p,\omega_i)$：所有方向的辐照度量。**
- **$cos\theta_i$：余弦项，面收到的能量和与面的夹角余弦成正比。**

也就是将每个角度的入射光叠加进行积分，然后和BRDF相乘得出结果，最后加上一个自发光项。

### 实时渲染中的渲染方程

$$
L_o (p,\omega_0) = \int _{\Omega}f_r(p,w_i ,w_o)L_i(p,\omega_i)dV(p,\omega_i)
$$

解释：将发光项去掉了揉进积分里面。

但是在实时渲染之中，这样的方程还面临两个严重问题:

1. 直接光照的时候，如何简化这个积分的计算？（加速计算）
2. 间接光照的时候，如何进行全局光照的递归？（递归的控制）

## 总结

本节课对GAMES101的知识中学到的重点进行了一点总结（和本系列课程有关的）。后面将围绕结尾的两个问题展开部分讨论。首先，我们先将关注点转向阴影和全局光照。
