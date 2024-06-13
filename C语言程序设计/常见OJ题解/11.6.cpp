#include <stdio.h>
#define STLEN 81
int main()
{
	char words[STLEN];
	
	puts("Enter a string, please.");
	gets(words);
	printf("Your string twice: \n");
	printf("%s\n",words);
	puts(words);
	printf("Done.\n");
	
	return 0;
	
}
