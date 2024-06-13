#include <stdio.h>

int main()
{
	long n,nega=1,temp=0;
	
	scanf("%ld",&n);
	

	if(n<0)
		{
			n*=-1;
			nega=-1;
		}
	while(n)
	{
		temp=temp*10+n%10;
		n/=10;
	}
	temp*=nega;
	
	printf("%ld",temp);
	
	return 0;
}