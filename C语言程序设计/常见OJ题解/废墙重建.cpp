#include <stdio.h>

int main()
{
	int n,i,a[100],sum=0,avg,max,k;
	
	while (scanf("%d",&n)!=-1)
	{
		if (n==0) break;
	max=0;
	sum=0;
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	avg=sum/n;
	for (i=0;i<n;i++)
	{
		if (avg>a[i]) 
		{
		k=avg-a[i];
		max+=k;
		}
	}
	printf("%d\n\n",max);
	}
	
	return 0;	
}