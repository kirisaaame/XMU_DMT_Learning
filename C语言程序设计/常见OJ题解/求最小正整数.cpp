#include <stdio.h>
/* q:请编写一个程序，对给定的若干个 0 ~ 9 数字，进行排列使得到的
正整数尽可能小（0 不能做首位数字）。
输入格式：第一行给出数字个数 n（n  100）；第二行给出 0 ~ 9 范围内的 n 个数
字（至少含 1 个非 0 数字），中间用一个空格分隔。
输出格式：给出可构成的最小正整数。*/
int main()
{
	int n,i,j,tmp;
	scanf("%d",&n); 
	int k[n];       //读取第一个数
	for(i=0;i<n;i++)
		scanf("%d",&k[i]);//读取第二行数并存储
	for(i=0;i<n;i++)
		if(k[i]==0) k[i]=10; //把0变成10方便选出第一个数
	for(i=n-1;i>0;i--)
		if(k[i]<k[i-1]) 
			tmp=k[i],k[i]=k[i-1],k[i-1]=tmp; //选出最高位的数
	for(i=0;i<n;i++)
		if(k[i]==10) k[i]=0; //把0变回来
	for(i=1;i<n;i++)
		{
			for(j=n-1;j>i;j--)
			{
				if(k[j]<k[j-1]) 
			tmp=k[j],k[j]=k[j-1],k[j-1]=tmp; //冒泡排序
		}
	}
		for(i=0;i<n;i++)
		printf("%d",k[i]);
		
	return 0;
}