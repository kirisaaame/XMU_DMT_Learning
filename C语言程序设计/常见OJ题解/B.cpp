#include <bits/stdc++.h>
using namespace std;
int solve(int n, int p, string s)
{
	int small[26] = { 0 };
	int big[26] = { 0 };
	for (int i = 0; i < n; i++)
		if (islower(s[i])) small[s[i] - 'a']++;
		else if (isupper(s[i])) big[s[i] - 'A']++;
	int count = 0;
	while (1)
	{
		if (p == 0) break;
		int flag=0;
		for (int i = 0; i < 26; i++)
			if (fabs(big[i]-small[i])>1)
			{
				flag = 1;
				if (small[i] > big[i])
				{
					small[i] --; big[i] ++;
				}
				else { big[i]--; small[i]++; }
				p--;
				break;
			}
		if (flag == 0) break;
	}
	for (int i = 0; i < 26; i++)
	{
		if (small[i] > 0 && big[i] > 0)
		{
			count += min(small[i], big[i]);
			small[i] -= min(small[i], big[i]);;
			big[i] -= min(small[i], big[i]);;
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
		int k, m;
		cin >> k >> m;
		getchar();
		string s;
		cin >> s;
		cout << solve(k, m, s) << endl;
	}

	return 0;
}