#include <stdio.h>
#include <math.h>

int main(void)
{
	int n,x1,y1,x2,y2,i,j;
	float distance;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			if (x1+y1<x2+y2)
			{
				distance=0;
				for (j=x1+y1;j<x2+y2;j++)
				distance+=sqrt(j*j+(j+1)*(j+1));
				distance+=(x2+y1)*sqrt(2);
				for (j=x1+y1+1;j<x2+y2;j++)
				distance+=j*sqrt(2);
				printf("%.3f\n",distance);
			}
			else if(x1+y1==x2+y2)
			{
				distance=sqrt((x1-x2)*(x1-x2))*sqrt(2);
				printf("%.3f",distance);
			}
		    else 
			{
				distance=0;
				for (j=x2+y2;j<x1+y1;j++)
				distance+=sqrt(j*j+(j+1)*(j+1));
				distance+=(x1+y2)*sqrt(2);
				for (j=x2+y2+1;j<x1+y1;j++)
				distance+=j*sqrt(2);
				printf("%.3f\n",distance);
			}
			
			
	}
	
	return 0;
}