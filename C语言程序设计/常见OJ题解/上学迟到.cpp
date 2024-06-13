#include <stdio.h>
#define PI 3.1415
int main()
{
	int height,radius,n;
	double v;
	n=1;
	scanf("%d%d",&height,&radius);
	v=PI*radius*radius*height;
	while (n*v<20000.0)
		n++;
	printf("%d",n);
	
	return 0;
	
}