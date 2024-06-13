#include <stdio.h>
int main(void)
{
	int daynum,wknum,dnum;
	printf("Please enter number of days:");
	scanf("%d",&daynum);
	wknum=daynum/7;
	dnum=daynum%7;
	printf("%d days are %d weeks, %d days.",daynum,wknum,dnum);
	
	return 0;
	
}