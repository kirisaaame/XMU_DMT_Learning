#include <stdio.h>
int  main(void)
{
    int n,i,a,b,c;
	scanf("%ld",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		while(a)
		{
		if(a>=b)
		a=a%b;
		else
		{c=a;a=b;b=c;}
		}
		printf("%d",b);
	}
	return 0;
}
	