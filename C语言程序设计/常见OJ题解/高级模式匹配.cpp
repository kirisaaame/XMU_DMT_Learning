#include <stdio.h>
#include <string.h>
int main()
{
	char t[1001];
	char s[1001];
	int i;
	
	gets(t);
	gets(s);
	if(strlen(s)>strlen(t))
	{
		printf("0");
		return 0;
	}
	char *p1=t;
	char *p2=s;
	
	for(i=0;i<strlen(t);i++)
	{
		if(*p2=='\0') break;
		else if(*p1==*p2)
		{
			p1++; p2++;
		}
		else p1++;
	}
	if(*p2=='\0')
		printf("1");
	else printf("0");
	
		
	return 0;
}