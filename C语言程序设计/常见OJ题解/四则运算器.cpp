#include <stdio.h>

int main()
{
	double a,b;
	char c,d;
	scanf("%lf",&a);
	scanf("%c%c",&d,&c);
	scanf("%lf",&b);
	if (c=='+')
	printf("%.4lf\n",a+b);
	else if (c=='-')
	printf("%.4lf\n",a-b);
	else if (c=='*')
	printf("%.4lf\n",a*b);
	else 
	(b==0)?printf("Error!"):printf("%.4f\n",a/b);
	return 0;
}