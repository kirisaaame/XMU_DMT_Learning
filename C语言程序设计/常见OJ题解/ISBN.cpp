#include <stdio.h>

int main()
{
	char str[14];
	int sum=0,i;
	scanf("%s",str);
	sum+=str[0]-'0';
	for(i=2;i<5;i++)
		sum+=(str[i]-'0')*i;
	for(i=5;i<10;i++)
		sum+=(str[i+1]-'0')*i;
	sum%=11;
	if (str[12]-'0'==sum || sum==10 &&str[12]=='X')
		printf("Right\n");
	else 
		{
			for(i=0;i<12;i++)
				printf("%c",str[i]);
				if (sum<10)printf("%d\n",sum);
				else printf("X\n");
		}
		
	return 0;
	//?
}