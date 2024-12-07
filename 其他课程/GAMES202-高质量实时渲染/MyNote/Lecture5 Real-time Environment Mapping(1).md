# Real-time Environment Mapping (1)

- Distance Field Soft Shadow
- Real-time environment Lighting
- Prefiltering
- Split Sum method

## shadow maps from signed distance field

使用有向距离场来估计shadow maps可以快速进行阴影比例的估算。

现在来看，距离场在图形学中主要有两个用法：

1. 在光线追踪中使用来减少计算判断光线是否相交的次数。（即使有多个物体，取所有物体SDF中最小的一个即可。）
2. 在计算阴影时，通过计算一个“安全角度”来判断该点的软阴影程度。（朝光源匹配求视场角，然后去除受光角度就是软阴影程度）。

那么，如何计算这个安全角度呢？
一般是用距离距离场除以距离，然后求反三角函数。

但是我们一般不用反三角函数（因为计算量很大）我们一般只用一个线性的函数$\theta = \frac{k\cdot SDF}{p-o}$去近似。

那么$k$的取值就会涉及阴影的软硬程度了。很明显，$k$越小，过渡越慢，阴影越软；$k$越大，过渡越快，阴影越硬。

### 优点和缺点

优点：

- 快（只需要查询距离场数次，进行一点简单的计算即可）
- 质量也相对比较高

缺点：

- 需要预计算
- 需要大量的存储来存储距离场
- 不好参数化（UV贴图）不好帖纹理

## Real-time Environment Lighting

如何在实时渲染中实现环境光照是一个另外的课题。我们先回忆一下以前的环境光照的知识：

### Recap: Environment Lighting

基础的环境光照假定环境光从各个方向，从无限远的方向照来，也就是无死角的方向光。我们用一个贴图来存储环境光照,也就是所谓的IBL(Image-based Lighting)。贴图又分为两种：

- 球形映射 (Spherical Map)
- 方形映射 (Cube Map)

IBL的渲染方程如下所示：
$$
    \int_{\Omega^+}L_i(p,\omega_i)f_r(p,\omega_i,\omega_o)\cos \theta_i d\omega_i
$$

*（IBL不考虑阴影和遮挡，因此删去了Visibility项。）*

我们以前计算的方法是采用蒙特卡洛积分，通过采样不同方向的光照和BRDF乘积求和得出一个结果。

该方法没有问题，是一个数值比较接近的近似解。但是在实时渲染中这个方法有几个问题：

1. 采样太慢了。蒙特卡洛积分一般在一个点要采样几百次，点的数量一多就很慢很慢。
2. 更重要的是，Shader没有办法采样。

怎么办呢？近似公式来帮忙。

### Approximation Formula

记得我们前面提到了一个近似公式：

$$
    \int_{\Omega} f(x)g(x)dx \approx \frac{\int_{\Omega} f(x)dx}{\int dx} \cdot \int_{\Omega} g(x)dx
$$

这个公式在两种条件下近似程度较好：

1. 积分域$\Omega$比较小
2. $f(x),g(x)$比较平滑

在实际中，第一种情况刚好对应Glossy的材质，第二种情况对应漫反射Diffuse的材质。

现在我们不需要计算乘积了，但是仍然剩下了两个积分项，我们需要想办法去快速计算着两个积分项。

## Prefiltering

计算$L_i$项时，因为原来是一个贴图，因此我们仍然可以采用原来PCF的方法，使用一个新的贴图进行卷积操作计算出的模糊贴图，随后再直接将一个区域的光照映射到着色点即可。

这种方式尤其适合glossy的材质，因为主要的反射光照都来自于一个特定区域。

关于滤波半径的去欸的那个，一般可以通过一个三线性插值来确定。

## Split-sum

如果遇到diffuse的情况如何应对呢？而且现在还剩下一个积分项没有解决，怎么办呢？

同样进行预计算不失为一种方法，但是$f_r(p,\omega_i,\omega_o)$的展开项是这样的：（在GAMES101的microfacet BRDF中有提到）
$$
    f_r(p,\omega_i,\omega_o) = \frac{F(i,h)G(i,o,h)D(h)}{4(n,i)(n,o)}
$$
其中$i,o,h,n$加上$\theta$是一个五维的存储，预计算需要的存储空间太大了。

这个时候人们想到了一个方法：降维。怎么降呢？分成两个步骤：

1. 5d->3d：