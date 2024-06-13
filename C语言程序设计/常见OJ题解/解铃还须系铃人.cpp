#include <stdio.h>
#include <string.h>
int main()
{
	char str[10001];
	int len,i;
	
	 gets(str);
	len=strlen(str);
	for (i=0;i<len-1;i++)
	{
		if('a'<=str[i]&&str[i]<='z')
			str[i]='z'-str[i]+'a';
		else if('A'<=str[i]&&str[i]<='Z')
			str[i]='Z'+'A'-str[i];
		else;
	}
	puts(str);
	return 0;
	}