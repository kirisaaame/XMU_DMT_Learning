#include <stdio.h>

int main()
{
	long a,b,c,max,min,m,n;
	
	scanf("%ld%ld%ld",&a,&b,&c);
	max=a;
	min=a;
	if(b>max) max=b; if(b<min) min=b;
	if (c>max) max=c; if (c<min) min=c;
	
	m=max;n=min;
	while(n>0)
    {
	if (m>n) m%=n;
	else
	{
		a=m;m=n;n=a;	
	}
	}
	max/=m;min/=m;
	//之前忘记分数约分了
	printf("%ld/%ld",min,max);
	
	return 0;
}