#include <stdio.h>
int main()
{
	int m,n,a,b,c,i,count;
	while(scanf("%d%d",&m,&n)!=-1)
	{
		count=0;
	for(i=m;i<=n;i++)
	{
		a=i/100;
		b=(i-a*100)/10;
		c=(i-100)%10;
		if (a*a*a+b*b*b+c*c*c==i)
		{
		printf("%-4d",i);
		count++;}	
	
	}
	 if (count==0)
	  printf("no");
	  	printf("\n");
}

return 0;
}