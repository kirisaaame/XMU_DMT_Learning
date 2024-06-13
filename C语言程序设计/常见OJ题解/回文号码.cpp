#include <stdio.h>
#include <string.h>

int main()
{
	int n,i,j,count=0;
	char number[12];
	
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		char cmp[12]={'\0'};
		scanf("%s",number);//录入一个电话号码
		getchar();
		for(j=0;j<11;j++)
			cmp[j]=number[10-j];//颠倒这个电话号码并且储存
		if(strncmp(number,cmp,11)==0)//比较
			count++;
	}
	printf("%d\n",count);
	
	return 0;
}