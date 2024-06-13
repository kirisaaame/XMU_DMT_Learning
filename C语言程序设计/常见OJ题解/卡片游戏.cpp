#include <stdio.h>

int main()
{
	int n,i,j,flag=0;
	long sum;
	long num[1000];
	
	scanf("%d%ld",&n,&sum);
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);//获取卡片上面的数并记录
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
				if (num[i]+num[j]==sum)
					flag=1;//如果找到两个数的和是所求数，特征值为1.
	if (flag==1)
		printf("Yes\n");
	else printf("No\n");
	
	return 0;
		
}