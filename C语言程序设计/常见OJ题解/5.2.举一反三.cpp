/*temperature transition*/
#include <stdio.h>
int main(void)
{
	int C=5.0;
	float F;
	while (C<18)
	{
		F=C*1.8+32;
		printf("%d in centigrade is %.1f in Fahrenheit.\n",C,F);
		C=C+1;
	}
	printf("Do you like my program?");
	
	return 0;
}