#include <stdio.h>

int main()
{
	int i,n,target,num[100000];
	
	scanf("%d%d",&n,&target);
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);
	
	int lower=0,upper=n-1,mid=(lower+upper)/2,found=0;
		

	
	while (lower<upper)
		{
			if (num[mid]<target)
			{
				lower=mid;
				mid=(lower+upper)/2;
			}
			else if (num[mid]>target)
			{
				upper=mid;
				mid=(lower+upper)/2;
			}
			else
				{
					printf("%d",mid+1);
					found=1;
					break;
				}
		}
	if(!found)
		printf("Error!\n");
		
	return 0;
}