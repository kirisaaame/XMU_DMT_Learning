#include <stdio.h>
#define EX 60
int main()
{
	int input,hours,minutes;
	scanf("%d",&input);
	while (input>0)
	{
		hours=input/EX;
		minutes=input%EX;
		printf("%d minutes is %d hours and %d minutes.",input,hours,minutes);
		scanf("%d",&input);
	}
	
	return 0;
}