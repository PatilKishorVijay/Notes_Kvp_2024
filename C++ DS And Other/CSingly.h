#pragma once
#include "Common.h"

class node
{
public:
	node* next;
	int data;
	node(int x):data(x)
	{
		next = nullptr;
	}
	~node()
	{
		cout << "node destructor called for data-- "<<data << endl;
	}
};


class Singly
{
	node* head;
	node* tail;
	static int count;
public:
	Singly()
	{
		head = tail = nullptr;
	}

	void insertAtHead(int x)
	{
		node * newnode = new node(x);
		if (!head)
			head = tail = newnode;
		else
		{
			newnode->next = head;
			head = newnode;
		}
		count++;
	}

	void insertAtTail(int x)
	{
		node* newnode = new node(x);
		tail->next = newnode;
		tail = newnode;
		count++;
	}

	void addNode(int x)
	{
		//node* newnode = new node(x);
		if (!head)
		{	
			insertAtHead(x);
		}
		else
		{
			insertAtTail(x);
		}
	}

	void Display()
	{
		node* temp=head;
		while (temp)
		{
			cout << temp->data << " ";
			if (temp->next)
				temp = temp->next;
			else
				break;
		}
		cout << endl;
	}


	void insertAtPosition(int pos,int x)
	{
		if (pos == 1)
			insertAtHead(x);
		else if (pos == count)
			insertAtTail(x);
		else
		{
			node* newnode = new node(x);
			node* temp = head;
			for (int i = 0; i < pos-2; i++)
			{
				temp = temp->next;
			}
			newnode->next = temp->next;
			temp->next = newnode;
			count++;
		}

	}


	//void getMiddleNode()
	//{
	//	node* slow=head;
	//	node* fast = head->next;
	//	static int cnt = 0;
	//	while (fast)
	//	{
	//		
	//		fast = fast->next;
	//		if (fast)
	//		{
	//			
	//			fast = fast->next;
	//			slow = slow->next;
	//		}
	//	}

	//	//return slow->data;

	//	cout << "middle is " << slow->data << endl;

	//}

	void getMiddleNode()
	{
		node* slow = head;
		node* fast = head->next;

		while (fast)
		{
			fast = fast->next;
			if (fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
	}

	void createLoop()
	{
		tail->next = head->next->next;
	}

	void detectLoop()
	{
		node* slow=head;
		node* fast=head;
		static int cnt;
		while (fast&&fast->next)
		{
			//slow = slow->next;
			cnt++;
			fast = fast->next->next;
			slow = slow->next;
			if(fast->next==slow)
			{
				cout << "loop detected" << endl;
				return;
			}
		}
		cout << "no loop detected" << endl;
	}


	void deleteNode(int pos)
	{
		if (pos == 1)
		{
			node* temp = head;
			head = temp->next;
			count--;
			delete temp;
		}
		else if (pos == count)
		{
			node* temp = head;
			while (temp->next != tail)
				temp = temp->next;
			tail = temp;
			tail->next = nullptr;
			count--;
			delete temp->next;
		}
		else
		{
			node* temp = head;
			int i = 0;
			while (i < pos - 2)
			{
				temp = temp->next;
				i++;
			}
			node* del = temp->next;
			temp->next = temp->next->next;
			delete del;
			count--;
		}
	}

	void reverseList()
	{
		node* prev = nullptr;
		node* current = head;
		while(current)
		{
			node* next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}

		head = prev;
	}

	void printReverse(node* current)
	{
		if (current == nullptr)
			return;
		printReverse(current->next);
		cout << current->data << " ";

	}


	void RemoveDups(node* head,int key)
	{

		if (key == head->data)
			deleteNode(1);
		if (key == tail->data)
			deleteNode(count);
		node* current = head;
		while (current) {
			//node* current = head;
			if (current->next->data = key)
			{
				node* del = current->next;
				current->next = current->next->next;
				delete del;
			}
			current = current->next;
		}
	
	}
	void RemoveDuplicates(int key)
	{
		RemoveDups(head,key);
	}


	void printInReverse()
	{
		printReverse(head);
	}
};
int Singly::count;

