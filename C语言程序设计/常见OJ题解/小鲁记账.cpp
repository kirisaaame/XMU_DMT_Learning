#include<cstdio>
int main(void)
{
	int n,a,b,c;
	float d;
	while(scanf("%d",&n) && n!=0)
	{
		a=0; b=0; c=0;
		for (int i =1;i<=n;i++)
		{scanf("%f",&d);
		if (d==0) b++;
		else if(d<0) a++;
		else c++;
		
		}
		printf("%d %d %d\n",a,b,c);
	}
	return 0;
}