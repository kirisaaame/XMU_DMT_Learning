#include <stdio.h>

int main()
{
	int n,i,j,k,num[100],temp;
	
	
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);
	
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(num[i]<num[j])
			{
				temp=num[i];
				num[i]=num[j];
				num[j]=temp;
			}
	printf("%d\n",num[k-1]);