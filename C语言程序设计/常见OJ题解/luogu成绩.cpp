#include <stdio.h>

int main()
{
	int a,b,c;
	double grade;
	scanf("%d%d%d",&a,&b,&c);
	grade=0.2*a+0.3*b+0.5*c;
	printf("%.0lf\n",grade);
	
	return 0;
}