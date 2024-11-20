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

那么，如何计算这个