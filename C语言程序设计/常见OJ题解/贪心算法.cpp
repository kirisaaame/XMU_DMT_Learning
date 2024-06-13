//这是贪心算法的代码实现。
//贪心算法的思维在于：着眼当下。先把当下能够满足条件的操作了
//再去考虑这样操作之后接下来会怎样
//而且贪心算法永不反悔，这和回溯算法相反。
//目标问题：花坛种花
#include <stdio.h>

int main()
{
	int huatan[102]={0};
	int n,i,count=0;
	
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
		scanf("%d",&huatan[i]);//获取花坛数据
	
	i=1;
	while(i<=n)
	{
		if (huatan[i]==1)//花坛有花了
			i+=2;
		else if(huatan[i+1]==1)//花坛右边有花
			i+=3;
		else if(huatan[i-1]==1)//花坛左边有花
			i++;
		else
		{
			count++;
			huatan[i]=1;
			i+=2;
		}//满足条件，种一朵
	}
	printf("%d\n",count);
	
	return 0;
}