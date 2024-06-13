#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	double sum;
	
	scanf("%d",&n);
	sum=(pow(((1+sqrt(5))/2),n)-pow((1-sqrt(5))/2,n))/sqrt(5);
	
	printf("%.2lf",sum);
	
	return 0;
}