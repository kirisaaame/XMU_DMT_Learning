#include <stdio.h>
int main()
{
  	int y,m,d,i,sum;
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
		while(scanf("%d%d%d",&y,&m,&d)!=-1)
	{
	if ((y%4&&!y%100||y%400))
		{
		a[1]=29;
	}
		sum=0;
			for (i=0;i<m-1;i++)
			sum=sum+a[i];
			sum=sum+d;
			printf("%d\n",sum);}
  
	return 0;
}
