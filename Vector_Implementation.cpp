#include"Includes.h"

template<class T>
class myVector
{
	T* data;
	int size;
	int capacity;


	void resize(int _newcapacity)
	{
		T* new_data = new T[_newcapacity];
		for (int i = 0; i < size; i++)
		{
			new_data[i] = data[i];
		}
		delete[] data;
		data = new_data;
		capacity = _newcapacity;
	}
	void ensure_capacity()
	{
		if (capacity == 0)
			resize(1);
		else
		{
			resize(capacity * 2);
		}
	}
public:
	
	void push_back(int x)
	{
		if (size==capacity)
		{
			ensure_capacity();
		}
		data[size++] = x;
	}
	
	void pop_back()
	{
		if (size)
		{
			size--;
		}
	}

	T& operator[](int index)
	{
		if (index >= size)
		{
			cout << "out of index" << endl;
		}
		return data[index];
	}

	const T& operator[] (int index)const 
	{
		if (index >= size)
		{
			cout << "out of index" << endl;
		}
		return data[index];
	}
	myVector():data(nullptr),size(0),capacity(0)
	{}
	~myVector()
	{
		delete[]data;
	}

	int get_capacity()
	{
		return capacity;
	}
	int get_size()
	{
		return size;
	}

};

int main()
{
	myVector<int> m1;
	m1.push_back(12);
	cout << m1.get_size() << endl;
	cout << m1.get_capacity() << endl;
	m1.push_back(23);
	cout << m1.get_size() << endl;
	cout << m1.get_capacity() << endl;
	m1.push_back(34);
	cout << m1.get_size() << endl;
	cout << m1.get_capacity() << endl;
	m1.push_back(45);
	cout << m1.get_size() << endl;
	cout << m1.get_capacity() << endl; 
	m1.push_back(56);
	cout << m1.get_size() << endl;
	cout << m1.get_capacity() << endl;

	for (int i = 0; i < m1.get_size(); i++)
		cout << m1[i] << endl;


	myVector<char> m2;
	m2.push_back('k');
	m2.push_back('I');
	m2.push_back('s');
	m2.push_back('H');
	m2.push_back('o');
	m2.push_back('R');

	for (int i = 0; i < m2.get_size(); i++)
		cout << m2[i] << " " ;

}
