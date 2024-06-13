#include <stdio.h>
#define SIZE 4
int main()
{
	int no_data[SIZE];
	int i;
	for (i=0;i<SIZE;i++)
		printf("%2d%14d\n",i,no_data[i]);
		
	return 0;
}