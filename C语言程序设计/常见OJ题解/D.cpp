#include <bits/stdc++.h>
using namespace std;
long solve(int n, string s)
{
	vector<string>ans(n-1);
	
	int count = 0;
	for (int i = 0; i < n - 1; i++)
	{
		string temp = "";
		int flag = 1;
		for (int j = 0; j < i; j++)
			temp += s[j];
		for (int j = i + 2; j < s.size(); j++)
			temp += s[j];
		for (int j=0;j<ans.size();j++)
			if (temp == ans[j])
			{
				flag = 0;
				break;
			}
		if (flag)
		{
			ans[count]=temp;
			count++;
		}
	}
	return count;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k ;
		getchar();
		string s;
		cin >> s;
		cout << solve(k, s) << endl;
	}

	return 0;
}