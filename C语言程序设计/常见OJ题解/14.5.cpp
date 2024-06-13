#include <stdio.h>
#define FUNDLEN 50

struct funds{
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(double x, double y)
{
	return (x+y);
}

int main()
{
	struct funds stan={
		"Garlic-Melon Bank",
		4032.27,
		"Lucky's savings and Loan",
		8543.94
	};
	
	printf("Stan has a total of $%.2f.\n",sum(stan.bankfund, stan.savefund));
	
	return 0;
}