#include <stdio.h>

int main()
{
	int n,i,j,ar[100],num[100]={0};
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&ar[i]);//读取数据
		
	for(i=0;i<n;i++)
		for(j=0;j<i;j++)
			if(ar[j]<ar[i])
				num[i]++;
	//计算输出数据
	for(i=0;i<n;i++)
		printf("%d ",num[i]);
	//输出数据
	
	return 0;
	
}