#include <stdio.h>
#include <math.h>
int main()
{
	int n,i,j,flag,count=0,sum;
	
	scanf("%d",&n);
		for (i=2;sum<n;i++)
		{
			flag=0;
			for(j=2;j<=sqrt(i);j++)
				if (i%j==0)
					flag=1;
			if (!flag)
			{
				sum+=i;
				if (sum<=n)
				{
					count++;
					printf("%d\n",i);
				}
			}
		}
	printf("%d\n",count);
	
	return 0;
}