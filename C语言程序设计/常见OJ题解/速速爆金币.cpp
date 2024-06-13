#include <stdio.h>

int main()
{
	int k,i=1,j,day=0,sum=0;
	
	scanf("%d",&k);
	
	while(day<k)
	{
		for(j=0;j<i;j++)
		{
			sum+=i;
			day++;
			if (day==k) break;
		}
		i++;
	}
	
	printf("%d",sum);
	
	return 0;
}