#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81
typedef char * STRING;
char * s_gets(char * st, int n);
char showmenu();
void eatline();
void show(void(*fp)(STRING),STRING str);
void Toupper(STRING);
void Tolower(STRING);
void Transpose(STRING);
void Dummy(STRING);

int main()
{
	char line[LEN];
	char copy[LEN];
	char choice;
	void (*pfun)(STRING);
	
	puts("Enter a string (empty line to quit): ");
	while (s_gets(line,LEN)!=NULL && line[0]!='\0')
	{
		while((choice=showmenu())!='n')
		{
		switch (choice)
		{
			case 'u':pfun=Toupper; break;
			case 'l':pfun=Tolower; break;
			case 't':pfun=Transpose; break;
			case 'o':pfun=Dummy; break;
		}
		strcpy(copy,line);
		show(pfun, copy);
	
		}
	puts("Enter a string (Empty line to quit):");
}
puts("Bye!");

return 0;
}

char showmenu()
{
	char ans;
	puts("Enter menu choice:");
	puts("u) uppercase      l)lowercase");
	puts("t) transposed case o)original case");
	puts("n)next string");
	ans=getchar();
	eatline();
	while (strchr("ulton",ans)==NULL)
	{
		puts("Please enter a u, l, t, o, or n:");
		ans=getchar();
		eatline();
	}
	
	return ans;
}

void eatline()
{
	while (getchar()!='\n')
	continue;
}

void Toupper(STRING str)
{
	while(*str)
	{
		*str=toupper(*str);
		str++;
	}
}

void Tolower(STRING str)
{
	while(*str)
	{
		*str=tolower(*str);
		str++;
	}
}
void Transpose(STRING str)
{
	while(*str)
	{
		if(islower(*str))
			*str=toupper(*str);
		else if(isupper(*str))
			*str=tolower(*str);
		str++;
	}
}

void Dummy(STRING p)
{
	
}

void show(void (*fp) (STRING), char * str)
{
	(*fp) (str);
	puts(str);
}

char *s_gets(char * st, int n)
{
	char * ret_val;
	char * find;
	ret_val=fgets(st,n,stdin);
	if (ret_val)
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