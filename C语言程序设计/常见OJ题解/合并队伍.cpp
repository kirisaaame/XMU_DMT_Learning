#include <stdio.h>

int main()
{
	int m,n,i,j,temp,ar[20000];
	
	scanf("%d%d",&m,&n);
	for(i=0;i<m+n;i++)
		scanf("%d",&ar[i]);
	for(i=0;i<m+n;i++)
		for(j=i;j<m+n;j++)
			if(ar[j]>ar[i])
			{
				temp=ar[i];
				ar[i]=ar[j];
				ar[j]=temp;
			}
	for(i=0;i<m+n;i++)
		printf("%d ",ar[i]);
	printf("\n");
		
	return 0;
}