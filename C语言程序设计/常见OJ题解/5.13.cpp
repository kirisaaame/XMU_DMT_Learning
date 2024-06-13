#include <stdio.h>
int main (void)
{
	int count, sum;
	
	count=0;
	sum=0;
	while (count++<20)
	sum=sum +count;
	printf("sum=%d\n",sum);
	
	return 0;
}