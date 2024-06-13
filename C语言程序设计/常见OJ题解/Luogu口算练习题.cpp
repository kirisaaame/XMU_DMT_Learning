#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	char s[50][111];
	char opt;
	int i,j,k,x,y,ans,ans_temp;
	int flag;

	scanf("%d", &n);
	getchar();

	for (i = 0; i < n; i++)
	{
		gets(s[i]);
		j = 0; k = 0; flag = 1; x = 0; y = 0;
		if (s[i][0] == 'a') {  opt = '+'; j += 2; }
		if (s[i][0] == 'b') {  opt = '-'; j += 2; }
		if (s[i][0] == 'c') {  opt = '*'; j += 2; }

		for (; s[i][j] != '\0'; j++)
		{
			if (s[i][j] != ' ')
			{
				k++;
				if (flag == 1)
					x = x * 10 + s[i][j] - '0';
				if (flag == 2)
					y = y * 10 + s[i][j] - '0';

			}
			if (s[i][j] == ' ' && s[i][j + 1] != '\0')
			{
				flag = 2;
				switch (opt)
				{
				case '+':k++;  break;
				case '-':k++;  break;
				case '*':k++;  break;
				}
				//准备输出第二个数
			}
			

			if (s[i][j+1] == '\0')
			{
				switch (opt)
				{
				case '+':ans = x + y; k++; break;
				case '-':ans = x - y; k++;  break;
				case '*':ans = x * y; k++; break;
				}
				//准备输出结果


				if (ans < 0)k++;
				ans_temp = ans;
				if(ans==0)k++;
				while (ans_temp)
				{
					k++;
					ans_temp /= 10;
				}
				//计算结果位数
			}
		}
		if(i==n-1)
		printf("%d%c%d=%d\n%d", x, opt, y, ans, k);
		else
		printf("%d%c%d=%d\n%d\n", x, opt, y, ans, k);

	}




	return 0;
}
