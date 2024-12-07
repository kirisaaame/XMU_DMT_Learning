# The Multiplicable Weight Algorithm

- The Experts Problem
- Weighed Majority Algorithm
- Lower Bound for Deterministic Algorithms
- Randomized Weighed Majority Algorithm

## The Experts Problem

假设现在有$n$位专家对$T$天的做出预测
在第$t$天，第$i$位专家给出的预测值是$out_i^t$
你做出一个预测 $guess^t$

做出预测之后，你将看到当天的实际结果$out^t$

**how to choose your guess on each days?**

### A Simpler Version

假设存在一个完美的专家总是做出准确的预测。

并且假设所有的专家都针对一个二值问题做预测（例如股票，预测涨或者跌）
我们能否找到一个犯错次数不超过$[\log_2n]$ 的方法呢?

### Majority-and-halving algorithm

每天，我们选出投票最多的专家预测值。如果该预测结果是错的，就去除所有做出这个预测的专家。
因此不超过$[\log_2n]$ 次错误次数，就可以找到那个完美的专家。

**同样地，这一样适用于预测非二值化问题的情况。**

### No Perfect Expert

事实上，在更实际的问题中几乎不可能存在这样的一个“完美的专家”。这个时候我们的算法应该是什么样子的呢？

我们假设最好的专家在此时也会犯$M$次错误，那么我们将执行$M$次上面的简单算法。当某次算法丢弃了场上所有的专家之后，我们让所有的专家重新加入并且继续执行。这种情况下，我们最多执行$(M+1)(\log_2n+1)$次错误，也就是$O(M\log n)$次错误

在这个问题中，我们发现$M$似乎是一个下界，$\log n$似乎也是一个下界，我们能不能将复杂度改为这两个下界相加，而不是这两个下界相乘的形式？

## Weighed Majority Algorithm

下面的加权算法就可以做到这一点。我们先来看看这个算法的流程是什么：

1. 给每位专家分配一个初始为1的权重。
2. 每次做出预测时，我们统计做出每个预测的所有专家的权重和
3. 当某些专家做出了错误的预测时，将其权重减半。

接下来我们证明如下定理：

**在最好的专家产生M次错误的情况下，我们最多犯$2.41(M+\log_2n)$次错误。**

证明：

设$X$是所有专家的权重和。
当我们每次预测错误的时候，都有$X_{new} \leq \frac{3}{4}X_{old}$
这是因为至少$\frac{1}{2}X$的权重被减半了,所以总权重至少减少了$\frac{1}{4}X$。
而我们没有犯错的时候，$X_{new} \leq X_{old}$，这是显而易见的。

假设我们到某个阶段总共犯了$m$次错误，并且由于最好的专家最多犯$M$次错误，因此有：

$$
    (\frac{1}{2})^M \leq X\leq (\frac{3}{4})^m
$$

也就是

$$
    (\frac{4}{3})^m \leq 2^M \cdot n
$$

两边取对数就有：
$$
    m\leq \frac{M+\log_2n}{\log_2\frac{4}{3}} = 2.41(M+\log_2n)
$$

一般来说，我们可以忽略$log_2n$，所以犯的错误上界的数量一般取决于最好的专家犯几次错误。

### Improved Weighed Majority Algorithm

改进后的算法唯一的改动是：当一个专家在第$t$天犯错时，我们将其权重乘$1-\epsilon$

改进后的算法复杂度算法是一样的：

$$
    (1-\epsilon)^M \leq (1-\frac{\epsilon}{2})^mn
$$

两边同时取对数：
$$
    M\ln(1-\epsilon) \leq m \ln(1-\epsilon/2) + \ln n
$$

也就是

$$
    m \ln \frac{1}{1-\epsilon/2} \leq M \ln \frac{1}{1-\epsilon} + \ln n
$$

又有
$$\ln\frac{1}{1-\epsilon/2}\geq  \frac{\epsilon}{2}\\
\ln \frac{1}{1-\epsilon} \leq \epsilon + \epsilon^2
$$

可得：
$$
    m\leq 2M(1+\epsilon)+\frac{2\ln n }{\epsilon}
$$

## Lower Bound for Deterministic Algorithms

关于上述确定算法的下界有如下定理：如果最好的专家犯M次错误，那么加权主元算法最多犯$2(1+\epsilon)M + O(\frac{\log_2n}{\epsilon})$次错误。

关于这个下界的解释是这样的：如果我们想要找到那个最好的专家，由于最好的专家会犯M次错误，因此我们至少也要试错2M次。

## Randomized Weighed Majority Algorithm

那么怎样做的比上面的下界更好？答案是采用不确定的算法，也就是下面讲到的随机加权主元算法。

该算法的流程如下：

1. 对所有专家赋予一个权重
2. 在每一天做出预测时（假设是0,1）我们有$\frac{预测1的专家权重}{总权重}$的概率预测1，反之预测0。
3. 预测错误时的处理方式不变。

这个随机算法的期望复杂度将会是$(1+\epsilon)M+\frac{\ln n}{\epsilon}$
，证明如下：

假设某一天预测错误的所有专家的权重占比和为$F_t$

那么我们期望的犯错次数就是$\Sigma_tF_t$

那么我们预测错误时的权重和满足:
$$
    X_{new} = (1-F_t)X_{old} + F_t\cdot X_{old}(1-\epsilon)
$$

也就是
$$
    X_{final} \geq (1-\epsilon)^M\\
    X_{final}\leq n\cdot(1-\epsilon\cdot F_t)
$$

转化得到
$$
(1-\epsilon)^M \leq n\cdot e^{-\epsilon\Sigma_tF_t}
$$

也就是说：
$$
    \epsilon\Sigma_tF_t \leq M\frac{1}{1-\epsilon} + \ln n
$$

加入常见不等式$\ln \frac{1}{1-\epsilon} \leq \epsilon  + \epsilon   ^2$可以得到：

$$
    \Sigma_tF_t \leq M (1+\epsilon) + \frac{\ln n}{\epsilon}
$$
