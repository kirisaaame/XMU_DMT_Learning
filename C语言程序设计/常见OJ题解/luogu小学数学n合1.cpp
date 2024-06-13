#include <stdio.h>
#include <cmath>
#define PI 3.141593
int main()
{	int t;
	scanf("%d",&t);
	if (t==1)
	printf("I love Luogu!\n");
	else if (t==2)
	printf("6 4\n");
	else if (t==3)
	printf("3\n12\n2\n");
	else if (t==4)
	printf("166.667\n");
	else if (t==5)
	printf("15\n");
	else if (t==6)
	printf("%.4f\n",sqrt(6.*6.+9.*9.));
	else if (t==7)
	printf("110\n90\n0\n");
	else if (t==8)
	printf("%.4f\n%.4f\n%.4f\n",PI*2*5,PI*5*5,PI*5*5*5*4/3);
	else if (t==9)
	printf("22\n");
	else if (t==10)
	printf("%d\n",9);
	if(t == 11)  
	printf("33.3333\n");
	else if(t == 12) 
	printf("%d\n%c\n", 'M' - 'A' + 1, 'A' + 18 - 1);
	else if (t==13)
	printf("16\n");
	else if (t==14)
	printf("50\n");
	
	
}