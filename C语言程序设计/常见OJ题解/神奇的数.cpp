#include <stdio.h>

int main()
{
	int n,i,j,sum,s[1000];
	
	while(scanf("%d",&n)!=-1)
	{
		j=0;
		sum=0;
		for(i=1;i<n;i++)
			if(n%i==0)
			{
				s[j++]=i;
				sum+=i;
			}	
		if(sum==n)
		{
			printf("%d, its factors are ",n);
			for(i=0;i<j;i++)
				printf("%d ",s[i]);	
			printf("\b\n");
		}
		else
			printf("no\n");
	}
	
	return 0;
}