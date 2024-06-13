#include <stdio.h>

void change(int *a,int *b,int flag)
{
	int *p;
	if (flag>0)
	{
		if(*a<0) *a*= (-1);
		if(*b<0) *b*=-1;
	}
	if (flag<0)
	{
		*p=*a;
		*a=*b;
		*b=*p;
	}
}

int main()
{
    int t,a,b,flag;
    void change(int *a,int *b,int flag);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d",&a,&b,&flag);
        change(&a,&b,flag);
        printf("%d %d\n",a,b);
    }
    return 0;
}