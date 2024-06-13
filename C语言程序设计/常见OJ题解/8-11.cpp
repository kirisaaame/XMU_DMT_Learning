//使用函数模板来进行自动类型转换

#include <iostream>
template <typename T>
void swap(T& a, T& b);

int main()
{
	using namespace std;
	int i = 10;
	int j = 20;
	cout << "i, j = " << i << ", " << j << ".\n";
	swap(i,  j);
	cout << "Now i, j = " << i << ", " << j << ".\n";

	double x = 24.5;
	double y = 81.7;
	cout << "x, y = " << x << ", " << y << ".\n";
	swap(x, y);
	cout << "Now x, y = " << x << ", " << y << ".\n";
	cin.get();
	return 0;
}

template <typename T>
void swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}