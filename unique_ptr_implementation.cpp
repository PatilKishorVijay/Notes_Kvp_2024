#include "Common.h"
#include<queue>
#include<stack>


class myclass
{
public:
	void disp()
	{
		cout << "myclass disp" << endl;
	}

	~myclass()
	{
		cout <<"myclass dctor" << endl;
	}
};

template<class T>
class myuniqueptr
{
	T* ptr;
	bool isArray;
public:
	myuniqueptr(T* p=nullptr, bool flag=false):ptr(p),isArray(flag)
	{

	}
	~myuniqueptr()
	{
		if (isArray)
		{
			delete[]ptr;
		}
		else
		delete ptr;
	}
	myuniqueptr(const myuniqueptr& ref) = delete;
	myuniqueptr& operator=(const myuniqueptr& ref) = delete;

	myuniqueptr(myuniqueptr&& ref)
	{
		ptr = ref.ptr;
		ref.ptr = nullptr;
	}

	myuniqueptr& operator=( myuniqueptr&& ref)
	{
		if (this != &ref)
		{
			delete ptr;
			ptr = ref.ptr;
			ref.ptr = nullptr;
		}
		return *this;
	}

	T& operator*()
	{
		return *ptr;
	}

	T* operator->()
	{
		return ptr;
	}

	T& operator[](int index)
	{
		return ptr[index];
	}
};


int main()
{
	myuniqueptr<myclass> u1(new myclass());
	u1->disp();
	(*u1).disp();

	myuniqueptr<myclass>arr(new myclass[2],true);
	for (int i = 0; i < 2; i++)
		arr[i].disp();
}
