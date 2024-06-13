#include <stdio.h>
int main()
{
	int a;
	int n;
	int sum;
	scanf("%d\n",&a);
	scanf("%d",&n);
	while (n<=0)
		scanf("%d",&n);
	sum=n*(2*a+n-1)/2;
	printf("%d",sum);
	
	return 0;
}