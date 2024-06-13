#include <stdio.h>
int main()
{
	int d,count=0;
	scanf("%d",&d);
	while(d!=1)
	{
		if(d%2==0)
			d/=2;
		else
			d=3*d+1;
		count++;
	}
	printf("%d\n",count);
	
	return 0;
}