#include <stdio.h>
#include <float.h>
int main()
{
	double nb;
	float ob;
	nb=1.0/3.0;
	ob=1.0/3.0;
	printf("%.6f %.6f\n",nb,ob);
	printf("%.12f %.12f\n",nb,ob);
	printf("%.16f %.16f\n",nb,ob);
	printf("%d %d",FLT_DIG,DBL_DIG);
	return 0;
}