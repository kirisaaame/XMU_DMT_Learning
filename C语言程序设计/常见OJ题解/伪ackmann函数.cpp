#include <stdio.h>

int A(int m,int n);

int main()
{
	int t,i,m,n;
	
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&m,&n);
		if(i==(t-1)) printf("%d",A(m,n));
		else printf("%d\n",A(m,n));
	}
	
	return 0;
	
}

int A(int m,int n)
{
	int sum=0;
	if(m==0)
	{
		if(n==0) sum=0;
		if(n>0) sum=n+1;
	}
	else
	{
		if(n==0) sum=A(m-1,1);
		if(n>0) sum=A(m-1,n-1)+n;
	}
	
	return sum;
}