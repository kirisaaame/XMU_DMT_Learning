#include <stdio.h>

int main()
{
	int n,i,j,num[100],max,temp;
	
	
	while((scanf("%d",&n))!=-1)
	{
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
	if (num[0]==num[n-1])
		printf("-1\n");
	else 
		max=num[0];
		i=1;
		while(num[i]==max) i++;
		printf("%d\n",num[i]);
	}
	
	return 0;
}