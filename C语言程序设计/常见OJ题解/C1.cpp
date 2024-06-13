#include <bits/stdc++.h>
using namespace std;
void solve(vector<long>s, long n)
{
	 long long sum = 0;
	vector <long > k(n,0);
	for (int i = 0; i < n; i++)
	{
		if (s[i])
		{
			k[i] = s[i];
		}
		else
		{
			long max = 0;
			for (int j = 0; j < n; j++)
				if (k[j] > max)max = k[j];
			sum += max;
			for (int j = 0; j < n; j++)
				if (k[j] == max)
				{
					k[j] = 0;
					break;
				}
		}
	}
	cout << sum << endl;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a;
		cin >> a;
		vector<long> s(a);
		for (int i = 0; i < a; i++)
			cin >> s[i];
		solve(s, a);
	}

	return 0;
}