#include <stdio.h>

int main(void)
{
	int n,i;
	char a,b,c,d;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	scanf(" %c %c %c",&a,&b,&c);
	if (a>b){d=a;a=b;b=d;}
	if (b>c){d=b;b=c;c=d;}
	if (a>b){d=a;a=b;b=d;}
	printf("%c %c %c\n",a,b,c);
	}
	
	return 0;
}