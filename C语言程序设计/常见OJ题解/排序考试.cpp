#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i=0;i< n; i++)
	{
		int p;
		cin >> p;
		vector<int> data(p);
		for (int j=0;j<p;j++)
		{
			int num; 
			cin >> num;
			data.at(j)=num;
		}
		sort(data.begin(),data.end(),less<int>());
		for(int i=0;i<p-1;i++)
			cout << data.at(i) << " ";
		cout <<data.at(p-1);
		cout << endl;
	}
}