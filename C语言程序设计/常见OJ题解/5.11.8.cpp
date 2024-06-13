#include <stdio.h>
int main(void)
{
	int c1,c2;
	printf("This program computes moduli.\n");
	printf("Enter an integer to serve as the second operand:");
	scanf("%d",&c2);
	printf("Now enter the first operand:");
	scanf("%d",&c1);
	printf("%d %% %d is %d\n",c1,c2,c1%c2);
	while (c1>0)
	{
		printf("Enter next number for first operand (<=0 to quit):");
		scanf("%d",&c1);
		if (c1>0)
		printf("%d %% %d is %d \n",c1,c2,c1%c2);
		
	}

	printf("Done!");
	
	return 0;
	
}