#pragma once
#include"Common.h"
#include<algorithm>

class Node
{
public:
	Node* Lchild;
	Node* Rchild;
	int data;
	Node(int x)
	{
		Lchild = Rchild = nullptr;
		data = x;
	}
	~Node()
	{
		cout << "destructor called for data -- " << data << endl;
	}
};
class BinaryTree
{
	Node* root;
	/*void insertChildNodes(Node* node, int x)
	{
		if (!root)
		{
			root = new Node(x);
			return;
		}

		else
		{
			while (node)
			{
				if (x<=node->data)
				{
					if (node->Lchild == nullptr)
					{
						node->Lchild = new Node(x);
						return;
					}
					else
						node = node->Lchild;
				}
				else if (x > node->data)
				{
					if (node->Rchild == nullptr)
					{
						node->Rchild = new Node(x);
						return;
					}
					else
						node = node->Rchild;
				}
			}
		}
	}*/

	void insertChildNodes(Node* node, int x)
	{
		if (!root)
		{
			root = new Node(x);
			return;
		}
		else
		{
			while (node)
			{
				if (x <= node->data)
				{
					if (node->Lchild == nullptr)
					{
						node->Lchild = new Node(x);
						return;
					}
					node = node->Lchild;
				}
				else
				{
					if (node->Rchild == nullptr)
					{
						node->Rchild = new Node(x);
						return;
					}
					node = node->Rchild;
				}

			}
		}
	}

	
	void getInOrder(Node* p)
	{
		// LNR  --Left Node RIght
		if (!p)
			return;
		getInOrder(p->Lchild);
		cout << p->data << " ";
		getInOrder(p->Rchild);
	}
	
	void getPreOrder(Node* p)
	{
		//NLR -- Node  Left Right
		if (!p)
			return;

		cout << p->data << " ";
		getInOrder(p->Lchild);
		getInOrder(p->Rchild);
	
	}

	void getPostOrder(Node* p)
	{
		//LRN  -- left right node
		if (!p)
			return;
		getInOrder(p->Lchild);
		getInOrder(p->Rchild);
		cout << p->data << " ";

	}

	int getDepthAndNodeCount(Node* node)
	{
		if (!node)
			return 0;
		else
		{
			int x = getDepthAndNodeCount(node->Lchild);
			int y = getDepthAndNodeCount(node->Rchild);
			int ans = max(x, y) + 1;
			return ans;
		}
	}

	

	/*bool searchTree(Node* node, int key)
	{
		while (node)
		{
			if (node->data == key)
				return 1;
			else
			{
				if (key <= node->data)
					node = node->Lchild;
				else
					node = node->Rchild;
			}
		}
		return 0;
	}*/

	bool searchTree(Node* node, int key)
	{
		while (node)
		{
			if (node->data == key)
				return 1;
			else
			{
				if (key <= node->data)
					node = node->Lchild;
				else
					node = node->Rchild;
			}
		}

	}
public:
	BinaryTree()
	{
		root = nullptr;
	}
	void insertInBST(int x)
	{
		insertChildNodes(root,x);
	}
	//void insertIntoTreeRecursive(int x)
	//{
	//	//Node* node= insertIntoTree(root,x);
	//}

	void printInOrder()
	{
		cout <<"printing inOrder" << endl;
		getInOrder(root);
		cout << endl<<endl;
	}
	void printPreOrder()
	{
		cout <<"printing Pre-Order" << endl;
		getPreOrder(root);
		cout << endl<<endl;
	}
	void printPostOrder()
	{
		cout <<"printing Post- Order" << endl;
		getPostOrder(root);
		cout << endl << endl;
		//cout << endl << endl;
	}
	int calculateDepth()
	{
		return getDepthAndNodeCount(root);
	}

	void SearchKey(int key)
	{
		if (searchTree(root, key))
			cout << "key is found" << endl;
		else
			cout << "not found" << endl;
	}


	int getNodeCount()
	{
		return getDepthAndNodeCount(root) + 1;
	}
};