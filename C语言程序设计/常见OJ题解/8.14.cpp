#include <iostream>
template <typename T>
void Showarray(T arr[], int n);
template <typename T>
void Showarray(T* arr[], int n);
struct debts {
	char name[50];
	double amount;
};

int main()
{
	using namespace std;
	int things[6] = { 13,31,103,301,310,130 };
	struct debts mr_E[3] =
	{
		{"Ima Wolfe", 2400.0},
		{"Ura Foxe", 1300.0},
		{"Iby Stout", 1800.0}
	};
	double* pd[3];
	for (int i = 0; i < 3; i++)
		pd[i] = &mr_E[i].amount;

	cout << "Listing Mr.E's counts of things:\n";
	Showarray(things, 6);
	cout << "Listing Mr.E's debts:\n";
	Showarray(pd, 3);
	return 0;
}

template<typename T>
void Showarray(T arr[], int n)
{
	using namespace std;
	cout << "template A\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

template <typename T>
void Showarray(T* arr[], int n)
{
	using namespace std;
	cout << "template B\n";
	for (int i = 0; i < n; i++)
		cout << *arr[i] << " ";
	cout << endl;
}