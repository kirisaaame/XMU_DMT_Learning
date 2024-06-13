#include <stdio.h>
#include <string.h>
int main()
{
	char ch;
	
	while ((ch = getchar())!= '#')
		putchar(ch);
		
	return 0;
}