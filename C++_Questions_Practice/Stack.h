#pragma once
#include"Common.h"

template<class T>
class Node
{public:
	Node* prev;
	Node* next;
	T data;

	Node(T x):data(x)
	{
		prev = next = nullptr;
	}
	~Node()
	{
		cout << "node with data " << data << " deleted" << endl;
	}
};

template<class D>
class myStack
{
	Node<D>* top;
	int size;
public:
	myStack()
	{
		top = nullptr;
		size = 0;
	}

	void push(D x)
	{
		Node<D>* newnode = new Node<D>(x);
		if (!top)
		{
			top = newnode;
			size++;
		}
		else
		{
			newnode->next = top;
			top->prev = newnode;
			top = newnode;
			size++;
		}
	}

	void pop()
	{
		Node<D>* temp;
		if (top == nullptr)
			cout << "stack is underflow" << endl;
		else
		{
			temp = top;
			top = top->next;
			delete temp;
			size--;
		}
	}

	D Top()
	{
		return top->data;
	}

	int Size()
	{
		return this->size;
	}
};
