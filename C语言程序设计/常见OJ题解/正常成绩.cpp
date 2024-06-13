#include <stdio.h>

int main()
{
	int n,i,j,score[3],sum,R2,count,highcnt;
	
	while(scanf("%d",&n)!=-1)
	{
	highcnt=0;
	for(i=0;i<n;i++)
	{
		sum=0;
		R2=0;
		//every week initialize
		for(j=0;j<3;j++)
			{
			scanf("%d",&score[j]);
			sum+=score[j];
			}
		//scan scores and calculate average.
		for(j=0;j<3;j++)
		R2+=(score[j]-sum/3)*(score[j]-sum/3);
		R2/=3;
		//get R2
		if(sum/3>=80 && R2<=25)
			count++;
		else 
			count=0;
		if (count>highcnt)
			highcnt=count;	
	}
	printf("%d\n",highcnt);
}
	
	return 0;
}