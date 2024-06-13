#include <stdio.h>
const double PI=3.1415926;
int main(void)
{
	double radius,volume;
	int gpnum,i;
	scanf("%d",&gpnum);
	i=0;
	while (i<gpnum)
	{
		i++;
		scanf("%lf",&radius);
		volume=PI*radius*radius*radius*4/3;
		printf("%.3lf\n",volume);
	}
	
	return 0;
}