//注意，要把enum变量声明成int,否则无法递增
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char * s_gets(char * st, int n);
enum spectum{red, orange,yellow,green,blue,violet};
const char * colors[]={"red","orange","yellow","green","blue","violet" };
#define LEN 30
int main()
{
	char choice[LEN];
	int color;//在这里
	bool color_is_found=false;
	
	puts("Enter a color (empty line to quit): ");
	while (s_gets(choice,LEN)!=NULL && choice[0]!='\0')
	{
		for(color =red; color<= violet ;color++)
		{
			if(strcmp(choice,colors[color])==0)
			{
				color_is_found=true;
				break;
			}
		}
		if (color_is_found)
			switch (color)
			{
				case red:puts("Roses are red.");
				break;
				case orange: puts("Poppies are orange.");
				break;
				case yellow: puts("Sunflowers are yellow.");
				break;
				case green: puts("Grass is green.");
				break;
				case blue: puts("Bluebells are blue.");
				break;
				case violet: puts("Violets are violet.");
				break;
			}
		else
			printf("I don't know about the color %s.\n",choice);
		color_is_found=false;
		puts("Next color, please(empty line to quit): ");
	}
	puts("Goodbye!");
	
	return 0;
}

char * s_gets(char *st,int n)
{
	char* ret_val;
	char * find;
	ret_val=fgets(st,n,stdin);
	if(ret_val)
	{
		find=strchr(st,'\n');
		if (find)
			*find='\0';
		else 
			while(getchar()!='\n')
				continue;
	}
	return ret_val;
}