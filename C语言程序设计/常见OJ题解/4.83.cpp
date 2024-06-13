#include <stdio.h>
int main()
{
	float number;
	scanf("%f",&number);
	printf("The input is %f or %e.\n",number,number);
	printf("The input is %+f or %E.\n",number,number);
	return 0;
}