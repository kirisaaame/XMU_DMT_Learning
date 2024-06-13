#include<stdio.h>
#include<math.h>#
int main()
{
	double a;
	double b;
	double c;
	double s;
	double area;
	scanf("%d %d %d",&a,&b,&c);
	s=(a+b+c)/2;
	area=sqrt(s*(s-a)*(s-b)*(s-c));
	printf("a=%f\nb=%f\nc=%f\n",a,b,c);
	printf("area=%f\n",area);
	return 0;
}