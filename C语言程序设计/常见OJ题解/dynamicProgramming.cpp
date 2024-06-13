#include <bits/stdc++.h>
using namespace std;
/*给你一个整数数组cost,其中cost[i]是从楼梯第i个台阶向上爬需要支付的费用。
一旦你支付此费用，你可以选择向上爬一个或者两个台阶。
你可以选择从下标为0或者下标为1的台阶开始爬楼梯。
请你计算并返回达到楼梯顶部的最低花费。*/
//状态表示：dp[i]表示到达第n阶的最少费用
//状态转移：dp[i]=min(dp[i-2]+cost[i-2],dp[i-1]+cost[i-1])
//初始化：dp[0]=0,dp[1]=0
//填表顺序：i从小到大
//返回值：返回dp[n-1]
int minCost(int cost[],int l)
{
	int dp[l+1];//顶部多加一个
	dp[0]=0,dp[1]=0;
	for (int i=2;i<=l;i++)
	{
		dp[i]=min(dp[i-2]+cost[i-2],dp[i-1]+cost[i-1]);
		//cout << dp[i] << ' ';
	}
	return dp[l];
}
int maxCash(int cost[],int l);
int main()
{
	int l;
	cin >> l;
	int cost[l];
	for (int i=0;i<l;i++)
		cin >> cost[i];
	cout << maxCash(cost,l);
}
/*打家劫舍（简单）
你是一小偷，计划偷窃沿街大的房屋。每间房内都藏有一定的现金。
影响偷窃的唯一制约因素就是香菱的房屋装有相互连通的防盗系统，
如果两件香菱的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房存放金额的非负整数数组，计算不出东警报装置的情况下的最高金额。
*/
//多状态表示：对每个房屋存在偷和不偷两种情况。设为t[]和nt[]。
//状态转移：t[i]=g[i-1]+cash[i],g[i]=max(g[i-1],t[i-1])
//初始化：t[0]=cash[0],g[0]=0
//填表顺序：没有关系。
//返回值：max(t[l],nt[l])
int maxCash(int cash[],int l)
{
    int t[l],nt[l];
    t[0]=cash[0],nt[0] = 0;
    for (int i=0;i<l;i++)
        t[i]=nt[i-1]+cash[i],nt[i]=max(nt[i-1],t[i-1]);
    return max(t[l-1],nt[l-1]);
}