#include <bits/stdc++.h>
//已完成的c++版本的高精度加法
using namespace std;
string hyplus(string s1,string s2)
{
	int len1, len2, lenmax;
	
	int i,j;

	
		len1 = s1.size();
		len2 = s2.size();
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
			a[i] += b[i];
			if (a[i] > 9)
			{
				a[i + 1] += 1;
				a[i] %= 10;
			}
		}//相加*/
	string c;
		if (a[lenmax] != 0)
			for (i = lenmax; i >= 0; i--)
				c+=a[i]+'0';
		else
			for (i = lenmax - 1; i >= 0; i--)
				c+=a[i]+'0';
	
	return c;
}

int main()
{
	string a,b;
	cin>>a;
	cin>>b;
	string c=hyplus(a,b);
	cout << c<<endl;
	
	return 0;
}
