
#include <stdio.h>
#include <string.h>
int main()
{
	char* p1, * p2, str[50] = "abc";
	p1 = "abc", p2 = "abc";
	strcpy(str + 1, strcat(p1, p2));
	printf("%s\n", str);


}