#include <stdio.h>
int main()
{
	int n,h,max,min,num,i,j;
	double sum;
	scanf("%d",&n);
	double score[n];
	for(i=0;i<n;i++)
	{
		min=100;
		max=0;
		sum=0;
		scanf("%d",&h);
		for(j=0;j<h;j++)
			{
				scanf("%d",&num);
				sum+=num;
				if(num>max) max=num;
				if(num<min) min=num;
			}
		score[i]=(sum-min-max)/(h-2);
	}
	for (i=0;i<n;i++)
		printf("%.2lf\n",score[i]);
		
	return 0;