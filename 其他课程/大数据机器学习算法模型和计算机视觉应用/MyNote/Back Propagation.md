# Back Propagation

- Recap
- Univariate Chain Rule
- Multivariate Chain Rule
- Back Propagation
- Computational Cost

## Recap: Neural Network 神经网络

在各种各样的应用中，我们已经看到了神经网络的强大，尤其是多层级的神经网络，在一层层的处理中逐渐贴近最终的结果。那么在多层级的神经网络中，最重要的就是每一层的结果是如何传递到下一层的。在这当中，最核心的一个算法就是**反向传播**。

反向传播是一种快速计算梯度的方法，使用了反向模式自动微分技术，比起简单的神经网络具有更广泛的应用空间。

## Recap: Gradient Descent 梯度下降

为了得到极小值，我们选定一个初始点开始迭代，在每次迭代中，我们确定一个**学习率$\eta$**作为步长，求出目标损失函数在该点的梯度，然后沿着梯度反方向移动点得到下一个迭代点。重复此过程直到达到预期学习成果或者最大步数。这就是梯度下降法。

但是在实际的神经网络中，对于每个训练数据都算梯度的话，训练数据一大就算的很慢，这个时候 SGD 作为一种技巧派上了用场。

在只有一个训练数据的情况下，梯度的计算依然可能变得非常麻烦，因为一个梯度可能涉及很多的变量，这就是反向传播的原理。

## Univariate Chain rule 变量链式法则

单变量链式法则的公式表述如下：
$$
    \frac{d}{dt}f(x(t)) = \frac{df}{dx}\cdot\frac{dx}{dt}
$$
这个公式可以拓展到多层嵌套的情况。上面的公式告诉我们，对于一个复杂的函数，我们可以采用变量替换的方式来计算其微分。比如说下面的函数:
$$
    L = \frac{1}{2}(\sigma(\omega x+b)-t)^2
$$
我们可以令
$$
    z = \omega x +b
    y = \sigma(z)
    L = \frac{1}{2}(y-t)^2
$$
那么计算出来的结果就是：
$$
    \frac{dL}{dy} = (y-t)\\
    \frac{dy}{dz} = \sigma'(z)\\
    \frac{dz}{dw} = x\\
    \frac{dz}{db} = 1
$$
那么结果就是：
$$
    \frac{dL}{dw} = x \sigma'(\omega x+b)(\sigma(\omega x+b)-t)\\
    \frac{dL}{db} = \sigma'(\omega x+b)(\sigma(\omega x+b)-t)\\
$$
(注意：我们的目标是求模型参数，也就是$w$和$b$)

根据上面的规则，我们可以写出一个变量之间的**计算图**，如果 A 是 B 的组成变量之一，那么我们就连一条 A——>B 的边。由此我们可以画出上面示例的计算图：

![Computational graph](/img/Computational_Graph.png)

当我们计算损失函数的时候，我们根据计算图正向计算；计算导数时则反过来。下文中我们用标记$\bar{A}$来表示计算损失函数对$A$的导数。

## Multivariate Chain Rule 多变量链式法则

这里的“多变量”不是指的有多个变量（上面的“单变量”实际上有三个变量）。这里指的是每个变量在计算图上有多条路径前往损失函数。上面给出的计算图中，每个变量都只有一条路通往损失函数（或者说，那是一个计算树），而下面这幅图不一样：

![Computational Graph 2](/img/Computational_Graph_2.png)

该图对应添加正则项的损失函数$L(h) = \frac{1}{2}(\sigma(\omega x +b)-t)^2 + \frac{1}{2}\lambda ||\omega^2||$

另外一种常见的回归函数多类逻辑回归也属于这种情况：
$$
    z_t = \sum_j w_{tj}x_j+b_t\\
    y_k = \frac{e^{z_k}}{\sum_t e^{z_t}}\\
    L = -\sum_k \log y_k
$$

![Computational graph 2](/img/multi_logistic_graph.png)

其实对应的多变量链式法则也很简单：
$$
    \frac{d}{dt}f(x(t),y(t)) = \frac{df}{dx}\frac{dx}{dt} + \frac{df}{dy}\frac{dy}{dt}
$$
这个公式可以拓展到多层嵌套的情况。

也就是说：
$$
    \bar{t} = \bar{x}\frac{dx}{dt} + \bar{y}\frac{dy}{dt}
$$

## Back Propagation 反向传播

假设每层对应的处理结果是$\bar{A}$，我们发现其都由下一层的处理结果得出，我们只需要计算对应的边$\frac{dB}{dA}$即可。所以在已知损失函数的情况下，我们从最后一层的导数算起，根据计算图逐步回推，最后计算出整个计算图的导数。这种反向计算的方式就叫**反向传播**。

反向传播的过程可以总结如下：假设$v_1,v_2,\dots,v_n$代表一个计图的拓扑结构（从左到右）

1.根据输入变量和损失函数，写出计算图
2. 前向过程
对节点中的每个$v_i$,根据其亲节点的值和函数关系计算出该节点的值。
3.反向过程
对节点中的每个$v_i$，根据其子节点中的导数和导数关系计算出该节点的导数。

最后反向传播到所有节点时，我们就得出了损失函数关于输入变量的偏导数。将这些偏导数组成一个向量，我们就得到了梯度。这就是反向传播的原理。

在梯度下降法中，我们每次迭代的方程是：
$$
    h_{i+1} = h_i - \eta\nabla L(h)
$$
很明显未知量是$\nabla L(h)$，因此在前向过程中，我们计算出$L(h)$的值；在后向工程中，我们计算出$\nabla L(h)$。因此我们就完成了一个数据的一次迭代。

下面以单变量链式法则中提到的式子来说明反向传播是如何工作的。其损失函数为：
$$
    L(h) = \frac{1}{2}(\sigma(\omega x + b) - t)^2
$$
假设训练和初始模型参数：
$$
    x = x_0\\
    y = y_0\\
    \omega = \omega_0\\
    b = b_0
$$
首先计算前向过程，很容易得到
$$
    L(h) = \frac{1}{2}(\sigma_0(\omega_0 x_0 + b_0) - t_0)^2
$$
我们仍然令：
$$
    z = \omega x + b\\
    y = \sigma(z)
$$
接下来根据计算图反向传播，得到：
$$
    \bar{y} = (y_0-t_0) = \sigma_0(\omega_0 x_0 + b_0) - t_0\\
    \bar{z} = \bar{y}\cdot\sigma'(z_0) = \sigma'(\omega_0 x_0 + b_0)(\sigma_0(\omega_0 x_0 + b_0) - t_0)\\
    \bar{\omega} = \bar{z}\cdot x_0 = x_0\sigma'(\omega_0 x_0 + b_0)(\sigma_0(\omega_0 x_0 + b_0) - t_0)\\
    \bar{b} =1\cdot \bar{z} = \sigma'(\omega_0 x_0 + b_0)(\sigma_0(\omega_0 x_0 + b_0) - t_0)
$$
因此得到梯度为：
$$
    \nabla L(h) = \sigma'(\omega_0 x_0 + b_0)(\sigma_0(\omega_0 x_0 + b_0) - t_0)<x_0,1>
$$

### Matrix form 矩阵形式

上面的过程也可以写成矩阵形式便于加速计算，如下图所示：

![Matrix Form Computational Graph](/img/matrix_form_computational_graph.png)

(其中$\bold{x,b,z,h,y,t}是n\times 1向量，\bold{W}是n\times n矩阵$)。

## Computational Cost

事实上，反向传播的权重复杂度和层数成线性关系，和每层的单元数成平方关系，因为一条边就代表一次计算，而边的数量满足上述规律。
