#include <stdio.h>
#define SLEN 40
#define LIM 5
int main()
{
	const char *mytalents[LIM]=
	{
		"Adding numbers swiftly","Multiplying  accurately","stashing data","Following instuctions to the letter",
		"Understanding the C language"
	};
	char yourtalents[LIM][SLEN]={
	"Walking in a straight line","sleeping","Watching television","Mailing letters","Reading mails"};
	int i;
	
	puts("Let's compare talents.");
	printf("%-36s  %-25s\n","My Talents","Your Talents");
	for (i=0;i<LIM;i++)
		printf("%-36s  %-25s\n",mytalents[i],yourtalents[i]);
	printf("\n sizeof mytalents: %zd, sizeof yourtalents: %zd\n",sizeof(mytalents),sizeof(yourtalents));
	
	return 0;
}