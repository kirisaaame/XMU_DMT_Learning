#include <stdio.h>

int main()
{
	int cash=0,cost,i,output=12,flag=1,deposit=0;

	for(i=1;i<=12;i++)
	{
		cash+=300;
		scanf("%d",&cost);
		if(cash<cost)
		{
			//if(i<=output)
			output=-1*i;
			flag=0;
		}
		cash-=cost;
		if(cash>=100)
		{
			deposit+=(cash/100)*100;
			cash%=100;
		}
	}
	if(flag)
		printf("%.0f",deposit*1.2+cash);
	else
		printf("%d",output);
	
		
	return 0;
}