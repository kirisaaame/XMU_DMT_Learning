#include <stdio.h>

int main()
{
	int n,i,k;
	int count1=0,count2=0;
	double sum1=0.0,sum2=0.0;
	
	scanf("%d %d",&n,&k);
	
	for (i=1;i<=n;i++)
	{
		if(i%k==0)
			{
				sum1+=i;
				count1++;
			}
		else
		{
			sum2+=i;
			count2++;
		}
	}
	
	printf("%.1f %.1f",sum1/count1,sum2/count2);
	
	return 0;
}