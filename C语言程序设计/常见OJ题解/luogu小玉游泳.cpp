#include <stdio.h>

int main()
{
	double s,speed=2.0;
	int count=0;
	
	scanf("%lf",&s);
	while(s>0)
	{
		s-=speed;
		speed*=0.98;
		count++;
	}
	printf("%d",count);
	
	return 0;
}