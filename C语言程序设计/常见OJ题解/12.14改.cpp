#include <stdio.h>
#include <stdlib.h>
#define P printf("%d\n",__LINE__);

int main()
{
	double *ptd;
	int max;
	int number;
	int i=0;
	
	puts("What is the maximum number of type double entries?");
	scanf("%d",&max);
	/*}
		puts("Number not correctly entered -- bye.");
		exit(EXIT_FAILURE);
	}*/
	ptd=(double*) malloc(max * sizeof(double));
	/*if (ptd=NULL)
	{
		puts("memory allocation failed. Goodbye.");
		exit(EXIT_FAILURE);
	}*/
	puts("Enter the values (q to quit):");
	
while (i<max && scanf("%lf",&ptd[i])==1)

		++i;
	
	printf("Here are your %d entries:\n",number=i);
	for(i=0;i<number;i++)
	{
		printf("%7.2f",ptd[i]);
		if(i%7==6)
		putchar('\n');
	}
	if (i%7==0)
		putchar('\n');
	
	puts("Done.");
	free(ptd);
	
	return 0;
}
