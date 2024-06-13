#include <stdio.h>
#include <string.h>

int main()
{
	char ops[10][10]={'\0'},x;
	int cnt=0,i,j,flag=0;
	
	for(i=0;i<10;i++)
	{
		if (flag)
			break;
		for (j=0;j<10;j++)
		{
			scanf("%c",&x);
			if(x=='\n')
				flag=1;
			else
				ops[i][j]=x;
			if(flag)
				break;
		}
	}
	flag=0;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(ops[i][j]>='0' && ops[i][j]<='9' ||flag==1)
			{
				flag=1;
				if(ops[i][j]=='.')
				{
					putchar(ops[i][j]);
					continue;
				}
				if(!(ops[i][j]>='0' && ops[i][j]<='9'))
					flag=0;
				if (flag==1)
					putchar(ops[i][j]);
				if(flag==0)
					printf("\n");
			}
		}
	}
	
	return 0;
}