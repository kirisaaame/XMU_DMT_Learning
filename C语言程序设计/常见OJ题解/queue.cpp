#include <iostream>
template <class T>
struct node
{
    T data;
    node * next;
};
template <typename T>
class LQueue
{
private:
    node member;
    node * front;
    node * rear;
    int MaxSize;
public:
    LQueue();
	void push(T e);
	bool Full();
    bool Empty();
	T front();
	void pop();
};
template <class T>
class SQueue
{
	T* base;
	int Maxsize;
	int front, rear;
public:
	SQueue();
	void push(T e);
	bool Full();
    bool Empty();
	T front();
	void pop();
};

template <typename T>
void SQueue<T>::push(T e)
{
	base[rear]=e;
	rear=(rear+1)%Maxsize;
}
template <class T>
bool SQueue<T>:: Empty()
{
    return rear== front;
}
template <class T>
bool SQueue<T> :: Full()
{
	return (rear+1)%Maxsize==front;
}
template <typename T>
T SQueue<T>:: front()
{
    return base[front];
}
template <typename T>
void SQueue<T>:: pop()
{
    base[front]=0;
}
int main()
{
	;
}

