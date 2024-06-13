#include <iostream>
using namespace std;
template <typename  Anytype>
void Swap(Anytype &a, Anytype &b);

int main()
{
	int i=10;
	int j=20;
	cout << "i,j= " << i << ", " << j << ".\n";
	cout << "Using compiler-generated int swapper:\n";
	Swap(i,j);
	cout << "Now i,j= " << i <<", " << j << ".\n";
	
	double x=24.5;
	double y=81.7;
	cout << "x,y= " << x << ", " << y << ".\n";
	cout << "Using compiler-generated double swapper:\n";
	Swap(x,y);
	cout << "Now x, y= " << x << ", " << y << ".\n";
	return 0;
}

template <typename Anytype>
void Swap(Anytype &a, Anytype &b)
{
	Anytype temp;
	temp =a;
	a=b;
	b=temp;
}