#include <stdio.h>

int main (void)
{
	int n,r,y;
	char k;
	while(scanf("%d",&n)!=-1);
	{r=0;y=0;
	while (n--)
	{
		k=getchar();
		if (k='R') r++;
		else if (k='Y') y++;
		else if (k='B'){
			if(r<7)
			{
			printf("Yellow\n");
			break;}
			else 
			{
				printf("Red\n");
				break;
			}
		}
		else if (k='L')
		{
			if(y<7)
			{
			printf("Red\n");
			break;}
			else 
			{
				printf("Yellow\n");
				break;
			}
		}
		}
	}

return 0;
}