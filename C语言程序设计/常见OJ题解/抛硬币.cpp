#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,*p,i,count=0;
	
	scanf("%d",&n);
	p=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		p[i]=0;
	while (1)
	{
		int flag=1;
		for(i=n-1;i>0;i--)
			if(p[i]==2)
			{
				p[i-1]++;
				p[i]=0;
			}//得出一种情况结果
			if(p[0]==2) break;
		for (i=0;i<n-1;i++)
			if (p[i]==1&&p[i+1]==1)
			{
				flag=0;
				break;
			}//如果不符合，直接退出循环，判断变量为0
		if (flag)
		{
			count++;
			for (i=0;i<n;i++)
				printf("%d",p[i]);
			printf("\n");
		}
		p[n-1]+=1;
	}
	printf("%d",count);
	
	return 0;
}