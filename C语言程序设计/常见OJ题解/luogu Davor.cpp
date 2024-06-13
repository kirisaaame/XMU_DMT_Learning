#include <stdio.h>

int main()
{
	int n,x,k=1;
	
	scanf("%d",&n);
	n/=52;
	
	for(x=1;7*x+21<=n&&x<=100;x++)
	{
		if((n-7*x)%21==0)
			k=(n-7*x)/21;
	}
	x=(n-21*k)/7;
	printf("%d\n%d",x,k);
	
	return 0;
}