#include <stdio.h>
#include <string.h>

int main()
{
	int n,i,j,cnt=0,flag;
	char words[1000][11]={'\0'};
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		flag=1;
		scanf("%s",words[i]);
		getchar();
		for(j=0;j<i;j++)
			if(strcmp(words[j],words[i])==0)
				flag=0;
		cnt+=flag;
	}
	printf("%d\n",cnt);
	
	return 0;
}