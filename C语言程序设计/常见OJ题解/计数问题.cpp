#include <stdio.h>

int main()
{
	int n,x,i,n1,count[10]={0};
	
	scanf("%d%d",&n,&x);
	
	for(i=1;i<=n;i++)
	{
		n1=i;
		while(n1)
		{
			count[n1%10]++;
			n1/=10;
		}
	}
	
	printf("%d",count[x]);
	
	return 0;
}