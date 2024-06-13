#include <iostream>
#include <stack>
template <typename T>
class SStack
{
	T *base;
	int top;
	int Maxsize;
public:
	SStack();
	void Push(T e);
	T pop();
	bool IsFull();
	bool IsEmpty();
	T GetTop();
	~SStack();
};
template<typename T>
SStack<T>::SStack()
{
	Maxsize = 100;
	base = new T[Maxsize];
	if(!base)
	{
		std::cout << "Malloc error!" << endl;
		std::exit(-1);
	}
	top=0;
}
template <typename T>
void SStack<T>:: Push(T e)
{
	base[top++] = e;
}

template <typename T>
T SStack<T>::pop()
{
	return base[--top];
}

template <typename T>
bool SStack<T>::IsFull()
{
	if (top == Maxsize)
		return true;
	return false;
}
template<typename T>
bool SStack<T>:: IsEmpty()
{
	if (top==0)
		return true;
	return false;
}

template <typename T>
T SStack<T>:: GetTop()
{
	return base[top-1];
}

/*Stack By linklist:
 Can get the class defined in headfile:<stack>
 */

void Converse(int n)
{
	std::stack<int> s;
	int p;
	std::cin >> p;
	do{
		s.push(n%p);
		n/=p;
	}
	while (n);

	while (!s.empty())
	{
		std::cout << s.top();
		s.pop();
	}
}//
std::stack<char> edit()
{
	std::string str;
	std::stack<char> s,;
	int i;
	std::getline(std::cin,str);
	for (i=0;i<str.size();i++)
		if(str[i]!='#')
			s.push(str[i]);
		else s.pop();
	return s;
}

//!important:use stack to solve a maze
std::stack<int[2]> Solve_a_maze()
{

}

//get a value of an expression
//difficult:how to find the rank, number symbol and operation symbol

int solve_exp()
{
	std::stack<int>
}
