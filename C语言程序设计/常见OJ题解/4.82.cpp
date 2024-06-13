#include <stdio.h>
#include <cstring>
int main()
{
	int length;
	char name[30];
	printf("Please enter your name:\n");
	scanf("%s",name);
	length=strlen(name);
	printf("""\"%s\"\n""",name);
	printf("""\"%20s\"\n""",name);
	printf("""\"%-20s\"\n""",name);
	printf("""\"%*s\"\n""",length+3,name);

	
	return 0;
}