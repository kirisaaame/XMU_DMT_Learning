#include <stdio.h>

int main()
{
	int s,i;
	long n;
	
	scanf("%ld",&n);
	for(i=2;i<n;i++)
	{
		if (n%i==0)
		{
			n/=i;
			s=n;
			break;//找到比较小的那一个，直接用这个数去除它
		}
	}
	printf("%d",s);
	
	return 0;
}