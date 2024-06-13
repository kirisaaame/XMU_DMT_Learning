#include <stdio.h>

int main()
{
	int x,n,i,distance=0;
	
	scanf("%d%d",&x,&n);
	
	for(i=x;i<x+n;i++)
		{
			if (i%7==6 || i%7==0);
			else distance+=250;
		}
	printf("%d\n",distance);
	
	return 0;
}