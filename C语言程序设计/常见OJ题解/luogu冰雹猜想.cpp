#include <stdio.h>

int main()
{
	int cnt=0,ar[200];//数组开大一点，不然越界
	
	scanf("%d",&ar[cnt]);
	while(ar[cnt]!=1)
	{
		if(ar[cnt]%2==0)
		{
			cnt++;
			ar[cnt]=ar[cnt-1]/2;
		}
		else 
		{
			cnt++;
			ar[cnt]=ar[cnt-1]*3+1;
		}
	}
	for(;cnt>=0;cnt--)
		printf("%d ",ar[cnt]);
		
	return 0;
	
}
