#include <stdio.h>
int main()
{
	int start,end,i,j,i1,temp,flag;
	
	scanf("%d%d",&start,&end);//获取输入
	
	for(i=start;i<=end;i++)
	{
		flag=1;
		for(j=2;j*j<=i;j++)
		{
			if(i%j==0)
			flag=0;
		}
		//判断是否是质数
		if(flag)
		{
			i1=i;
			while(i1)
			{
				temp=temp*10+i1%10;
				i1/=10;
			}
			//获得回文数
			if(temp!=i)
				flag=0;
			//若不是回文质数，返回0
			if(flag)
				printf("%d",i);
		}
	}
	
	return 0;
}