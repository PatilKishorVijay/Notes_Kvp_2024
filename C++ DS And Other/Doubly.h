#pragma once
#include "Common.h"

class DNode
{
public:
	DNode* prev;
	int data;
	DNode* next;

	DNode(int x)
	{
		prev = next = nullptr;
		data = x;
	}
	~DNode()
	{
		cout << "destructor called for node with data" << data<<endl;
	}
};


class Doubly
{
private:
	DNode* head;
	DNode* tail;
	static int cnt;
public:
	Doubly()
	{
		head = tail = nullptr;
	}

	void insertAtHead(int x)
	{
		DNode* newnode = new DNode(x);
		head = tail = newnode;
	}

	void insertAtTail(int x)
	{
		DNode* newnode = new DNode(x);
		newnode->prev = tail;
		tail->next = newnode;
		tail = newnode;

	}
	void insert(int x)
	{
		if (head == nullptr)
			insertAtHead(x);
		else
			insertAtTail(x);
	}
	void display()
	{
		DNode* temp = head;
		while (temp)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	int getMiddle()
	{
		DNode* slow = head;
		DNode* fast = head->next;

		while (fast != nullptr)
		{
			
			fast = fast->next;
			if (fast) {
				fast = fast->next;
				slow = slow->next;
			}
		}
		return slow->data;
	}
};
int Doubly::cnt = 0;
