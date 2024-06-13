#include <stdio.h>

int main()
{
	int T,t,a,b,c;
	long m,n;
	
	scanf("%d", &T);
	{
		for(int t=0;t<T;t++)
	{
		scanf("%ld%ld", &n, &m);
		if (m==0) printf("Error!\n");
		else if(n==0) printf("0\n");
		else
		{
		a=m;b=n;
		while(a)
		{
		if(a>=b)
			a=a%b;
		else
		{c=a;a=b;b=c;}
		}
		m/=b;n/=b;
		if(m==1) printf("%ld\n",n);
		else printf("%ld/%ld\n",n,m);
		}
	}
}
	return 0;
	}