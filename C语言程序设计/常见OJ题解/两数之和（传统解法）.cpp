#include <iostream>
using namespace std;
int main()
{
	int target,n;
	cin >> target >> n;
	int data[n];
	for (int i=0;i<n;i++)
		cin >> data[i];
		//
	for (int* p1 = data;p1<data+n;p1++)
		for(int* p2=p1+1;p2<data+n;p2++)
			if (*p1+*p2 == target)
			{
				cout << p1-data << " " <<p2-data<<endl;
				return 0;
			}

	
	
}