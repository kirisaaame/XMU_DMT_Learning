#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIMIT 81
void Toupper(char* str);
int punctcount (const char* str);

int main()
{
	char line[LIMIT];
	char* find;
	
	puts("Please enter a line");
	fgets(line,LIMIT,stdin);
	find=strchr(line,'\n');
	if (find)
		*find='\0';
	Toupper(line);
	puts(line);
	printf("That line has %d punctuation characters.\n",punctcount(line));
	
	return 0;
}

void Toupper(char*str)
{
	while(*str)
	{
		*str=toupper(*str);
		str++;
	}
}

int punctcount(const char *str)
{
	int ct=0;
	while (*str)
	{
		if(ispunct(*str))
			ct++;
	}
	
	return ct;
}