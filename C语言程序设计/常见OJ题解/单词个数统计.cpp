#include <stdio.h>

int main()
{
	char ch;
	int words=0;
	ch=getchar();
	while(ch!='\n')
	{
		if(ch==' ')
			words++;	
		if(ch=='.')
			words++;
		ch=getchar();
	}
	printf("%d\n",words);
	
	return 0;
}