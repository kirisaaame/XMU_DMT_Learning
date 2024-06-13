#include <stdio.h>

void inverse(int n)
{
	int temp=0;
	if (n==0) printf("0\n");
	else if (n>=0)
	{while (n)
			{
			printf("%d",n%10);
			n/=10;
		}
	printf("\n");
}
	else 
	{
		printf("-");
		n*=-1;
		while (n)
		{
			printf("%d",n%10);
			n/=10;
		}
		printf("\n");
	}
}

int main()
{
	int T, n;
    scanf("%d", &T);
    while (T--)
    {
       scanf("%d", &n);
       inverse(n);
    }
    return 0;
}