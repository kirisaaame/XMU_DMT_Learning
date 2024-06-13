#include <stdio.h>
#include <string.h>
int main()
{
	int n,i,num,sum1=0,sum2=0;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&num);
		if(i%2==0)
			sum2+=num;
		else
			sum1+=num;
	}
	printf("%d\n%d",sum1,sum2);
	
	return 0;
	
	}