#include <stdio.h>
#define RATE1 0.4463
#define RATE2 0.4663
#define RATE3 0.5663
#define NUM1 150
#define NUM2 400
int main()
{
	int n;
	float money;
	
	scanf("%d",&n);
	if (n<=NUM1)
		money=n*RATE1;
	else if(n>NUM1 && n<=NUM2)
		money=NUM1*RATE1+(n-NUM1)*RATE2;
	else
		money=NUM1*RATE1+(NUM2-NUM1)*RATE2+(n-NUM2)*RATE3;
		
	printf("%0.1f",money);
		
	return 0;
}