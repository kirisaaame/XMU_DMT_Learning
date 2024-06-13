#include <stdio.h>
#include <cstring>
int main()
{
	char fn[30];
	char ln[30];
	int lln,lfn;
	printf("Please enter your first name:\n");
	scanf("%s",fn);
	printf("Now please enter your last name:\n");
	scanf("%s",ln);
    lln=strlen(ln);
	lfn=strlen(fn);
	printf("%s %s\n",ln,fn);
	printf("%*d %*d\n",lln,lln,lfn,lfn);
	printf("%s %s\n",ln,fn);sss
	printf("%-*d %-*d\n",lln,lln,lfn,lfn);
	return 0;	
	
}
