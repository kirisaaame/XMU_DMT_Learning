#include <stdio.h>
#include <string.h>
int main()
{
	int n,i,count=0;;
	char str[21];
	char mode[20][11];
	char* p;
	
	scanf("%d",&n);
	getchar();
	gets(str);
	for(i=0;i<n;i++)
	{
		gets(mode[i]);
	}
	p=str;
	while(*p!='\0')
	{
		for(i=0;i<n;i++)
			if(strncmp(p,mode[i],strlen(mode[i]))==0)
			{
				count++;
				strcpy(mode[i]," ");
			}
		*p++;
	}
	
	printf("%d",count);
	
	return 0;
}