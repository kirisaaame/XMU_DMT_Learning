#include<stdio.h>
#include<string.h>
int main()
{
	char s1[111], s2[111];
	int len1, len2, lenmax;
	
	int i,j;

	while (scanf("%s%s",s1,s2) != EOF)//如何输入
	{
		
		len1 = strlen(s1);
		len2 = strlen(s2);
		if (len1 > len2)lenmax = len1;
		else lenmax = len2;
      int a[111]={0}, b[111]={0};

		for (i = len1 - 1, j = 0; i >= 0; i--, j++)
			a[j] = s1[i]-'0';
		for (i = len2 - 1, j = 0; i >= 0; i--, j++)
			b[j] = s2[i]-'0';
		//字符数组逆序转化为整型数组，对齐位数，方便相加

		for (i = 0; i < lenmax ; i++)
		{
			a[i] -= b[i];
			if (a[i] <0)
			{
				a[i + 1] -= 1;
				a[i] += 10;
			}
		}//相加

		if (a[lenmax-1] != 0)
			for (i = lenmax-1; i >= 0; i--)
				printf("%d", a[i]);
		else
			for (i = lenmax - 2; i >= 0; i--)
				printf("%d", a[i]);
		printf("\n");
		//判断和是否进位，逆序输出
	}
	return 0;
}
