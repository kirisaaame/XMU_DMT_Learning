# Data Stream

- **Streaming Model**
- **Example Streaming Questions**
- **Heavy Hitters**
- **Algorithm 1: For Majority element**
- **Misra Gries Algorithm**
- **Applications**
- **Approximation of count**

## Streaming Model 数据流模型

数据流就是所有的数据先后到达，而不是同时存储在内存之中。在现实中，数据流或者本身占用空间很大，或者数量很多，保存所有的数据流数据是不可能的。

因此，在数据流相关问题中，我们一般比较关注**空间复杂度**，也就是节省内存的做法。

本节课提到的数据流模型简单地用**数字流**来代表数据流，也就是说数据流中地每一个元素都是一个数。

## Example Streaming Questions 经典数据流问题

我们假设每个数据需要 $b$ 位来存储，总共预计接收到 $t$ 个数据

1.**维护接收到的所有数据的总和需要的位数**

答案是$O(b + \log t)$。

为什么是这个答案呢？
一个数是 $b$ 位，$t$ 个数就是 $b+\log t$位。这个和十进制里面，十个一位数相加的结果一定是一个$1 + \log 10 =2$位数来表达一样。这就是这里为什么是元素个数取对数。
2. **维护收到的所有数据的最大值需要的位数**

很明显答案是$O(b)$。

3.**维护收到的所有数据的中位数需要的位数**

这个问题似乎有点困难。因为中位数涉及到对于所有数据进行排序。但是也不是完全没办法，请参见下文算法。

## Heavy Hitters 频繁项

给定项数 $n$ 和权重 $\epsilon$ ，请你找到数据流中所有出现次数大于 $\epsilon n$ 的项。这就是数据流中的频繁项问题。我们如何在使用内存尽可能小的情况下解决这个问题呢？

## Algorithm 1: For Majority element 主元算法

如果一个数据流中有一个数据的出现频率超过了0.5，那么这个数据就被叫做主元。我们可以先看看如何确定主元的算法，以便我们推广到频繁项。

可行的一个算法如下：
    在内存中声明一个数k和一个计数器c.
    初始化时，让k为空，让c为0.
    每当数据 $a_i$ 到达时，循环执行如下操作：
    如果 $c=0$ ,那么 $a_i \rarr k$, $1 \rarr c$；
    如果 $c\neq 0$ 且 $a_i \neq k$,那么$c--$；
    如果 $c\neq0$ 且 $a_i = k$ ,那么 $c++$；
循环执行该操作，执行完毕时的数k就可能是主元。

写成代码的形式如下：

```c
    datatype a,k;
    int c=0;
    cin >> a;
    while(a)
    {
        if(c==0)
        {
            k=a;
            c=1;
        }
        else if (c>0 && a!=k)
        {
            c--;
        }
        else 
        {
            c++;
        }
    }
```

注意，这个算法得到的结果不一定是主元，但是这个数是最可能是主元的那一个。
下面我们证明：如果数据流有主元 $a_{main}$，那么主元一定是 $k$ 。

每次读入$a_{main}$时，要么 $k \neq a_{main}, c--$ ,要么$k = a_{main}, c++$ ;因为是主元，所以必定存在某个时刻使得 $k = a_{main}$,且因为 c++ 的次数大于 c-- 的次数，因此读入所有数据之后一定满足 $k = a_{main}$。

这个算法的主要思路是，由于我们寻找主元，而一个数据流中主元最多就一个，因此我们只需要记录那个可能出现次数过半的就可以了。如果有主元，那么这个数据
一定会被记录下来。但是我们不知道记录下来的是否一定是主元。即这是一个充分不必要条件：
$$
    有主元 \rArr k是主元
$$

## Misra Gries Algorithm MG算法

MG算法是上面算法的一个拓展，用于计算 $\epsilon$ 频繁项。如果主元使用一个数来记录，那么最多可以有几个 $\epsilon$ 频繁项开一个对应大小的数组就可以了。答案是$\lceil(\frac{1}{\epsilon})\rceil -1$.为什么是这个数呢？ $\epsilon$ 带入一下 $\frac{2}{5}$ 和 $\frac{1}{2}$ 就知道了。

我们声明一个数组 $T[k]$ 负责存储数据，数组 $C[k]$负责存储计数器，算法大同小异。其伪代码形式如下：

```c
    datatype a,T[k];
    int C[k]={0};
    while(cin >> a)
    {
        if(C[j]==0)
        {
            T[j]=a;
            C[j]=1;
        }
        else if (C[j]!=0 && a!=T[j])
        {
            all C[j]--;
        }
        else if(a==T[j])
        {
            C[j]++;
        }
    }
```

### Heavy Hitters Guarantee

为什么MG算法可以保证找出所有的频繁项呢？证明方法也是和上面的算法一样。

我们在此证明：
$$
    0 \leq count_t(e) - est_t(e) \leq \frac{n}{k} +1 \leq  \epsilon\cdot n
$$
其中$count_t(e)$是某个元素$e$实际出现的次数，$est_t(e)$是指该元素的计数器次数。

等式的左边不难证明，因为我们要在实际接收到一个相同元素之后才会把计数器+1，因此实际次数-计数器次数一定大于0

等式的右边是因为每次所有计数器-1的操作都至少需要k次单个计数器+1的操作，因此减少所有计数器的操作最多只有 $\frac{n}{k+1}$ 次。

那么对于频繁项， $count_t(e) > \epsilon \cdot n$，而又有 $count_t(e) - est_t(e)  \leq  \epsilon\cdot n$，因此$est_t(e) >0$，也就是所有的频繁项一定会在列表之中。**注意，所有的频繁项一定在列表之中不代表列表中的所有项都是频繁项。**

### Space Complexity 空间复杂度

MG算法的空间复杂度就是两个数组的空间复杂度：
$$
    O(k(\log |\Sigma| +\log n))bits
$$
两个数组的长度都是$k$，数据数组每个元素需要$\log |\Sigma|$位来存储（表示数据的范围），计数器数组每隔元素需要$\log n$位来存储（表示从0到n）。

## Applications

1. Internet router may want to figure out which IP connections are heavy hitters, e.g., the ones that use more than 0.01% of your bandwidth.（寻找网络中哪些IP地址是常被访问的）

2. Or the median of the file sizes being transferred.（文件大小的中位数）

## Approximation of count 估计出现次数

