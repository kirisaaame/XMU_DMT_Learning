//这是回溯算法的代码实现（递归方式）。
//回溯算法的思维在于：分步处理。对于每一步，依次查找解或者最优解
//如果发现穷尽了，返回上一步并且撤回这一步所做的操作
//目标问题：组合问题。
#include <stdio.h>
int used[100]={0};
int ans[100];
int k=1;
void combination(int n, int m, int s)
{
	int i;
	//s大于m,输出取数结果
	if (s>m)
		
		{
			for(i=1;i<=m;i++)
				printf("%d ",ans[i]);
			printf("\n");
			return ;//找不到合适的了，退回上一步
		}
	else 
	{
		for(i=k;i<=n;i++)//依次尝试
		{
			if(used[i]==1)//用过了
				continue;
			else 
			{
				ans[s]=i;//取第s个数为i
				k=i+1;//我希望升序排序，下一个数从i+1开始
				used[i]=1;//用过了
				combination(n,m,s+1);//下一次尝试
				//如果回来，说明该部分尝试穷尽了
				used[i]=0;
			
				//回溯，让下一个数			
			}
		}
	}
}

int main()
{
	//现在要在n个数里面取m个数
	int n,m;
	scanf("%d%d",&n,&m);
	
	combination(n,m,1);//取第一个数
	
	return 0;
}