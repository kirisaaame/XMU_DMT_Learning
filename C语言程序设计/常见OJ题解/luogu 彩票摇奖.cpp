#include <stdio.h>

int main()
{
	int n,i,j,k,prize[7],num[7],count,get[7]={0};
	
	scanf("%d",&n);
	for(i=0;i<7;i++)
		scanf("%d",&prize[i]);
	for(i=0;i<n;i++)
	{
		count=0;
		for(j=0;j<7;j++)
		{
			scanf("%d",&num[j]);
			for(k=0;k<7;k++)
				if(prize[k]==num[j])
					count++;
		}
		if (count==0);
		else get[7-count]++;
			
	}
	for (i=0;i<6;i++)
		printf("%d ",get[i]);
	printf("%d",get[6]);
	
	return 0;
}