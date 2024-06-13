#include <stdio.h>

int main()
{
	int n,i=0,j,ar[100000];
	
	while(scanf("%d",&n)==1 && n!=0)
		if(n%2==0) 
			ar[i++]=n;
	if (i==0)
		printf("Empty");
	else 
	{
		printf("%d",ar[0]);
		for(j=1;j<i;j++)
			printf(" %d",ar[j]);
	}
		
	return 0;
}