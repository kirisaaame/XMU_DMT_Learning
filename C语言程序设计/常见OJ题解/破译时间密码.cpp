#include <stdio.h>
#include <ctype.h>
int main()
{
	char t[1001]={0};
	int n=0,q,m,d;
	char *p;
	int months[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	
	gets(t);
	for(p=t;*p!='\0';p++)
		if(isdigit(*p))
		{
			n=n*10+*p-'0';
		}
	
	q=((n*3)%1131)+101;
	m=q/100;
	d=q%38;
	printf("%d %d %d %d\n",n,q,m,d);
	if(m<1 || m>12)
		printf("input error!");
	else if(d>months[m] || d<=0)
		printf("input error!");
	else printf("%d.%d",m,d);
	
	return 0;
	
}