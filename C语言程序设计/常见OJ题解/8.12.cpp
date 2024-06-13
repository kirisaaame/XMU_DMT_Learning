#include <iostream>
template <typename T>
void sswap(T &a, T &b);
template <typename T>
void sswap(T *a, T *b,int n);//为什么不能用swap？原因：标准的namespace空间中存在swap函数，和这里的swap函数
//产生了冲突
void show(int a[]);
const int Lim = 8;
int main()
{
	using namespace std;
	int i = 10, j = 20;
	cout << "i,j= " << i << ", " << j << ".\n";
	cout << "Using compiler-generated int swapper:\n";
	sswap(i,j);
	cout << "Now i,j= " << i << ", " << j << ".\n";

	int d1[Lim] = { 0,7,0,4,1,7,7,6 };
	int d2[Lim] = { 0,7,2,0,1,9,6,9 };
	cout << "Original arrays:\n";
	show(d1);
	show(d2);
	sswap(d1, d2, Lim);
	show(d1);
	show(d2);
	return 0;
}

template <typename T>
void sswap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
void sswap(T a[], T b[], int n)
{
	T temp;
	for (int i = 0; i < n; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

void show(int a[])
{
	using namespace std;
	cout << a[0] << a[1] << "/";
	cout << a[2] << a[3] << "/";
	for (int i = 4; i < Lim; i++)
		cout << a[i];
	cout << endl;
}