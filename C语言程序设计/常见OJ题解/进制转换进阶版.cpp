#include <stdio.h>
#include <string.h>
char ch[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int convert(int n, int m, char result[])
{
	int j;
	char *c=result;
	while (n)
	{
		*c=ch[n%m];
		n/=m;
		c++;
	}
	for (j=0;j<strlen(result)/2;j++)

	{
		char temp=*(result+j);
		*(result+j)=*(result+strlen(result)-1-j);
		*(result+strlen(result)-1-j)=temp;
	}
}

int main()
{
    int n, m, T;
    char result[1024];     
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        memset(result, 0, 1024);
        convert(n, m, result);
        printf("%s\n", result);
    }    
    return 0;
}