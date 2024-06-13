#include <stdio.h>

int main()
{
	int n,sum=1;
	
	while(scanf("%d",&n)!=-1)
    {n--;
	
	while (n--)
	{
		sum=2*(sum+1);
	}
	
	printf("%d\n",sum);
    }	
	return 0;
}