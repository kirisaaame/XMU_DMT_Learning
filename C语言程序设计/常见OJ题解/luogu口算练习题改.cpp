#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	int n,i,sum;
	char ar[20],ans[50][30],cal;
	
	scanf("%d",&n);
	
	for (i=0;i<n;i++)
	{
		int j=0,len=0;
		int num1=0,num2=0;
		scanf("%s",ar);
		if (isalpha(ar[0]))
		{
			j+=2;
			if(ar[0]=='a')
				cal='+';
			else if (ar[0]=='b')
				cal='-';
			else if (ar[0]=='c')
				cal='*';	
		}
		while(ar[j]!=' ')
			{
				j++;
				num1=num1*10+ar[j]-'0';
			}
		j++;
		while(ar[j]!='\0')
		{
			j++;
			num2=num2*10+ar[j]-'0';
		}
		if (cal=='+')
			sum=num1+num2;
		if (cal=='-')
			sum=num1-num2;
		if(cal=='*')
			sum=num1*num2;
		sprintf(ans[i],"%d%c%d=%d",num1,cal,num2,ans);
	}
	
	for (i=0;i<n;i++)
	{
		if(i==(n-1))
			printf("%s\n%d",ans[i],strlen(ans[i]));
		else 
			printf("%s\n%d\n",ans[i],strlen(ans[i]));
	}
	
	return 0;
}