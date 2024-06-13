#include <iostream>
using namespace std;

int main()
{
	int p,e,i,d;
	int times=1;
	while (cin>>p>>e>>i>>d)
	{
		if(p==-1&&e==-1&&i==-1&&d==-1) return 0;
		for (int j=1;j<21253;j++)
		{
			int day = j+d;
			int a = day-p,b = day-e, c = day-i;
			if(a>0&&b>0&&c>0&&a%23==0&&b%28==0&&c%33==0)
			{
				cout << "Case " << times << ": the next triple peak occurs in " << j << " days.\n";
				times++;
				break;
			}
		}

	}
}