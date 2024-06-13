#include <stdio.h>

int main()
{
	int i=0,ar[100]={0};
	
	while(scanf("%d",&ar[i])!=0 && ar[i]!=0)
		i++;
	for(i-=1;i>=0;i--)
		printf("%d ",ar[i]);
		
	return 0;
}