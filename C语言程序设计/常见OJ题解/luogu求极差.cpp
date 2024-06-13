#include <stdio.h>

int main()
{
	int n,s,i,max,min;
	
	scanf("%d",&n);
	scanf("%d",&s);
	max=s;
	min=s;//初始化max和min方便比较
	
	for (i=0;i<n-1;i++)
	{
		scanf("%d",&s);
		if (s>max) max=s;
		if (s<min) min=s;
	}
	
	max-=min;
	printf("%d",max);
	
	return 0;
}