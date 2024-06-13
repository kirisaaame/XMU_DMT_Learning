#include <stdio.h>

int main()
{
	//原来价格都是靠输入
	int num,n[3]={0},c[3],i,j,price,cost;
	//7个数据7个变量
	scanf("%d",&num);
	for(i=0;i<3;i++)
	scanf("%d%d",&n[i],&c[i]);
	
	for(i=0;i<3;i++)
	{
		price=0;
		j=0;
		while(j*n[i]<num)
		{
			j++;
			price+=c[i];
		}
		if(i==0) cost=price; 
		if (price<cost)
		cost=price;
	}
	printf("%d",cost);
	
	return 0;
	
}