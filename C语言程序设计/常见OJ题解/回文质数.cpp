#include <stdio.h>
int main()
{
	int start,end,i,j,i1,temp,flag;
	
	scanf("%d%d",&start,&end);//获取输入
	if(start%2==0)
		start++;
	for(i=start;i<=end;i+=2)
	{
		if(i>10000000)
			break;
		temp=0;
		flag=1;
			i1=i;
			while(i1)
			{
				temp=temp*10+i1%10;
				i1/=10;
			}
			//获得回文数
		if(temp!=i)
			flag=0;
			//
		if(flag)
		{
		if(i%3==0) flag=0;
		else
		{
		for(j=2;j*j<=i;j++)
		{
			if(i%j==0)
			flag=0;
		}
		}
		}
		//判断是否是质数
		
		if(flag)
				printf("%d\n",i);
		}
	
	return 0;
	//如果这题先判断质数再判断回文数，很慢；
	//先判断回文数再判断质数就很快
}