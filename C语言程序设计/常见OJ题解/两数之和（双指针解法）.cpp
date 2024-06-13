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
	for(int* p1 = data,*p2 = data+n-1;p1<p2;p1++)
    {
        while(*p1+*p2>target) p2--;
            if (*p1+*p2==target) cout << p1-data << " " << p2-data<<endl;
    }
    //两侧逼近，故时间复杂度为O(n)
    //双指针算法仅适用于有序序列，无序时不如直接枚举
}