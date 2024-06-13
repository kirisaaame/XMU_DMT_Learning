#include <stdio.h>

int main(void)
{
	int n,i,sum;
	float average;
	while (scanf("%d",&n)!=-1)
	{
		int score=0;
		int max=0,min=100;
		sum=0;
		for (i=0;i<n;i++)
		{
			scanf("%d",&score);
			if (score>max) max=score;
			if (score<min) min=score;
			sum+=score;
		}
		average=(float)(sum-max-min)/(n-2);
		printf("%.2f\n",average);
	}
}