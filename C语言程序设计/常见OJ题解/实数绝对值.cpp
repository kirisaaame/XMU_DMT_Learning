#include <stdio.h>
int main(void)
{
	double n;
	while (scanf("%lf",&n)==1)
	{
		if (n>0)
		printf("%.2lf\n",n);
		if (n<0)
		printf("%.2lf\n",-n);
		if (n==0)
		printf("0.00\n");
	}
	
	return 0;
}