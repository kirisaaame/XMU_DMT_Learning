#include <stdio.h>

int main()
{
	int n,m,i,step=0,count=0;
	int num[1001]={0};
	
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		num[i]=i;
	i=0;
	while(count!=n)
	{
		i++;step++;
		if(i>n) i-=n;
		while(num[i]==0)
		{
		  	i++;
			if(i>n) i-=n;
		}
		if(step!=3) continue;
		else
		{
			count++;
			if(count!=n) printf("%d ",num[i]);
			else printf("%d",num[i]);
			num[i]=0;
			step-=3;
		}
	}
}