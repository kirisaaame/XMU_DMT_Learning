#include <stdio.h>

int main()
{
	int n,i,j,k,flag,num[100],count=0;;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);
	for(i=0;i<n;i++)
		{
			flag=0;
			for(j=0;j<n;j++)
			if (num[j]>=num[i]);
			else
				for(k=j+1;k<n;k++)
					if(num[j]+num[k]==num[i])
						flag=1;
			count+=flag;
		}
	
	printf("%d",count);
	
	return 0;
}