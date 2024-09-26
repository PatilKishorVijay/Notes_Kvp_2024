#include<iostream>
using namespace std;

template<class T>
class node
{
public:
	T data;
	node* next;
	node(T x) :next(nullptr)
	{
		data = x;
	}
};

template<class T>
class stack
{
	node<T>* top;
	static int cnt;
public:
	stack() :top(nullptr) {}

	void push(T x)
	{
		node<T>* temp = new node<T>(x);
		temp->next = top;
		top = temp;
		cout << x << " pushed" << endl;
		cnt++;
	}


	void pop()
	{
		if (!top)
			return;
		else
		{
			node<T>* temp = top;
			top = top->next;
			T d = temp->data;
			cout << d << " popped out " << endl;
			cnt--;
			delete temp;
		}
	}

	int peek()
	{
		if (!top)
			return -1;
		else
			return top->data;
	}

	bool isEmpty()
	{
		if (!top)
	return 1;
	}

	int getSize()
	{
		return cnt;
	}
};
template<class T>
int stack<T>::cnt = 0;



int main()
{
	stack<int>s1;

	s1.push(12);
	s1.push(23);
	s1.push(34);
	s1.push(45);

	int size = s1.getSize();

	for (int i = 0; i < size; i++)
		s1.pop();

	stack<string>s2;
	s2.push("kishor");
	s2.push("ojas");
	s2.push("jayu");

	for (int i = 0; i < 3; i++)
		s2.pop();
}
