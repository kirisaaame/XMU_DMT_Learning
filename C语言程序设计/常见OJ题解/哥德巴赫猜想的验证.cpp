#include <stdio.h>
#include <math.h>

void OddDiv(int n)
{
	int temp=n-4,flag=1,j;
	for(j=3;j*j<=temp;j+=2)
			if(temp%j==0)
				flag=0;
	if (flag==1)
		printf("%d=2+2+%d",n,temp);
	else{
	
	temp=n-3;
	int i,p1,p2;
	if (temp==4)
		printf("7=2+2+3");
	else
	{
		for(i=3;i<=n/2;i+=2)
		{
			flag=1;
			for(j=3;j*j<=i;j+=2)
				if(i%j==0)
					flag=0;//判断p1是素数
			if (flag==1)
				p1=i;p2=temp-p1;
			flag=1;
			for(j=3;j*j<=p2;j+=2)
				if(p2%j==0)
					flag=0;//判断p2是素数
			if (flag==1)//如果p2是素数，直接退出循环
				break;
		}
		printf("%d=3+%d+%d",n,p1,p2);
	}
	}
	
	
	
}
void EvenDiv(int n)
{
	int i,j,flag=1,p1,p2;
	if (n==4)
		printf("4=2+2");
	else
	{
		for(i=3;i<=n/2;i+=2)
		{
			flag=1;
			for(j=3;j*j<=i;j+=2)
				if(i%j==0)
					flag=0;//判断p1是素数
			if (flag==1)
				p1=i;p2=n-p1;
			flag=1;
			for(j=3;j*j<=p2;j+=2)
				if(p2%j==0)
					flag=0;//判断p2是素数
			if (flag==1)//如果p2是素数，直接退出循环
				break;
		}
		printf("%d=%d+%d",n,p1,p2);
	}
			
}

int main()
{
  int n;
  scanf("%d", &n);
  for (int i=4;i<=n;i+=2) 
  {
	EvenDiv(i);
	printf("\n");
  }
  return 0;
}