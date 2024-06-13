//第二讲：基础算法
//简单的基础算法，大致对应NOIP1或者
#include <bits/stdc++.h>
using namespace std;
bool state[200];
//枚举全排列
int DFS(int k,int n)
{   
    if (k==n)
        return 1;
    else 
    {
        int sum=0;
        for (int i=0;i<n;i++)
            if (!state[i])
            {
                sum+=DFS(k+1,n);
            }
        return sum;
    }
}
//迭代加深搜索：空间限制比较大，但是有时候需要求最优解
// 搜索剪枝：1.若当前状态已经不满足题目要求，则不继续扩展。2.最优型剪枝：当前解已经不满足最优解条件
//迭代加深搜索，记忆化搜索，启发式搜索

//记忆化搜索：递归到相同状态时，直接返回储存数组的结果


//贪心：Greedy Algorithm ：沿着一条看上去最优秀的路径走到底，永不后悔。这和回溯产生了根本性区别。
//每一次根据当前步骤确定临界条件。

//找零钱问题
int LeastChange(int n)
{
    int change[6] = {100,50,20,10,5,1};
    int num=0;
    int i=0;
    while(n)
    {
        while(n>=change[i])
        {
            num++;
            n-=change[i];
        }
        i++;
    }
    return num;
    //注意：该贪心算法在大纸币面值小于小纸币面值两倍的情况下可能不正确。
}
//证明贪心正确性:边界情况递归到一般情况
//求解最大子序列的和

//反证法
//背包问题(可以任意分割物品的情况)
/*
    1.找出单位价值最高的物品，往里塞，直到背包被塞满;
    2.接着找出单位价值最高的物品，往里塞；
    ...
    3.计算总价值;
*/

//合并石头问题
//贪心：每次合并最小的两堆

//二分和三分
//binary search
void BinarySearch()
{
    int l,r;
    cin >> l >> r;
    char c;
    int num = l+r >>1;
    //cout << num;
    c=getchar();
    while(c!='=')
    {
        if (c == '>')
        {
            r = num;
            num = l+r >>1;
        }
        else if (c == '<')
        {
            l = num;
            num = l+r >>1;
        }
        c = getchar();
    }
    cout << num;
}
//使用二分之前，需要目标只有一个，或者问题只有唯一的分界点 











int main()
{
    BinarySearch();
}