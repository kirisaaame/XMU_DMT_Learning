#include <stdio.h>
#include <string.h>

int main()
{
	int n,i,j,len1,len2,cnt;
	char ar1[100001];
	char ar2[100001];
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
			cnt=0;
			scanf("%s",ar1);
			getchar();
			scanf("%s",ar2);
			len1=strlen(ar1);
			len2=strlen(ar2);
			for(j=0;j<=len1-len2;)
			{
				char cm[100000]={'\0'};
				strncpy(cm,ar1+j,len2);
				if(strcmp(cm,ar2)==0)
				{
					cnt++;
					j+=len2;
				}
				else
					j++;
			}
			printf("%d\n",cnt);
		}
		return 0;
}