#include <stdio.h>

void GetInfo(double r, double result[])
{
	const double PI=3.14159;
	result[0]=2.0*PI*r;
	result[1]=PI*r*r;
	result[2]=4.0*PI*r*r;
	result[3]=4.0/3.0*PI*r*r*r;
}

int main() 
{
  double r, result[4];
  scanf("%lf", &r);
  GetInfo(r, result);
  printf("%.2f\n%.2f\n%.2f\n%.2f", result[0], result[1], result[2], result[3]);
  return 0;
}