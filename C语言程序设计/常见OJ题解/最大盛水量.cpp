#include <stdio.h>

int main()
{
	int n,i,j,k,num[1000],temp,max;
	
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);
	
	max=num[0]>=num[1]?num[1]:num[0];
	
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			{
			if((j-i)*(num[i]>=num[j]?num[j]:num[i])>max)
			max=(j-i)*(num[i]>=num[j]?num[j]:num[i]);
			}
	printf("%d\n",max);
}