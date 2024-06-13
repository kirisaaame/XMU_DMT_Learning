#include <stdio.h>

int main()
{
	int small,mid,big,temp;
	//短边，中边和长边
	scanf("%d%d%d",&small,&mid,&big);
	
	if (small>mid)
	{
		temp=small;
		small=mid;
		mid=temp;
	}
	if(mid>big)
	{
		temp=big;
		big=mid;
		mid=temp;
	}
	if (small>mid)
	{
		temp=small;
		small=mid;
		mid=temp;
	}
	//排序
	if (small+mid<=big)
	{
		printf("Not triangle \n");
		return 0;
	}
	if(small*small+mid*mid==big*big)
		printf("Right triangle \n");
	if(small*small+mid*mid>big*big)
		printf("Acute triangle \n");
	if(small*small+mid*mid<big*big)
		printf("Obtuse triangle \n");
	if(small==mid || mid==big)
		printf("Isosceles triangle \n");
	if(small==big)
		printf("Equilateral triangle \n");
	//不同的判定，不细讲
	return 0;
}