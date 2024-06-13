#include <stdio.h>
int power(int a,int b);
int main(void)
{
	int n,num,i,j;
	float sum;
	scanf("%d",&n);
	int a[n];
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);
	for (i=0;i<n;i++)
	{
		sum=0;
		for (j=0;j<a[i];j++)
		{
			sum+=power(-1,j)/(float)(j+1.0);
		}
		printf("%.2f\n",sum);
	}

	
	return 0;
}

int power(int a,int b)
{
	int sum=1,i;
	for (i=0;i<b;i++)
		sum*=a;
		
	return sum;
}