#include <stdio.h>
int main(void)
{
	int n,sum,i;
	while (scanf("%d",&n)!=-1)
	{
		sum=1;
		for (i=0;i<n-1;i++)
			sum=(sum+1)*2;
			printf("%d\n",sum);
	}
	return 0;
}