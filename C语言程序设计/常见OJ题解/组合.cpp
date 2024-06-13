#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,m,i,j,*p;
	
	scanf("%d%d",&n,&m);
	
	p=(int *)malloc(m*sizeof(int));
	
	for(i=0;i<m;i++)
	p[i]=i+1;//p赋初始值
	
	while (1)
	{
		int flag=1;
		for(i=m-1;i>0;i--)
			if (p[i]>n-m+i+1)
			{
				p[i-1]++;
				p[i]=1;
			}
		if(p[0]>n-m+1) break;
		for (i=0;i<m;i++)
			for(j=i+1;j<m;j++)
				if(p[j]<=p[i])
					flag=0;//判断是否符合要求
		if (flag)
			{
			for (i=0;i<m;i++)
				
					printf("%d ",p[i]);
			printf("\n");
		}
		p[m-1]++;		
	}
	return 0;
}