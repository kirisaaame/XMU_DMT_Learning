#include <stdio.h>
#include <string.h>

int main()
{
	char t[1001];
	char s[1001];
	int i;
	char ans[1001];
	
	gets(t);
	gets(s);
	
	char *p1=t;
	char *p2=ans;
	
	if(strlen(s)>strlen(t))
	{
		printf("%s",t);
		return 0;
	}
	
	while(*p1!='\0')
	{
		if(strncmp(p1,s,strlen(s))==0)
			p1+=strlen(s);
		else 
		{
			*p2=*p1;
			p1++;p2++;
		}
	}
	*p2='\0';
	
	for(i=0;i<strlen(ans);i++)
		putchar(ans[i]);
		
	return 0;
}