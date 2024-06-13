#include <stdio.h>

int main()
{
	int a,b,n;
	double money;
	scanf("%d%d",&a,&b);
	money=a+0.1*b;
	n=(int)(money/1.90);
	printf("%d\n",n);
	
	return 0;
	
}