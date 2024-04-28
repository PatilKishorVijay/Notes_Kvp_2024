	anonymous objects on heap vs anonymous object on stack

in both cases constructor gets called but destrucotr gets calles immediately for stack object as it scope ends after that line.
But in case of heap bases there is no handle /pointer thruw hich we can call their destuctor explicitley
so those objects remains in memory till execution of the program ends.


stack based obj vs heap based obj
destructor called implicitly for stack based while we have to call explicitly for heap based objects by calling delete on that pointer.
	{
	MyClass m1(17);
	MyClass m2(11);
	MyClass *m3 = new MyClass(2611);
	delete m3;}
	
	O/p-- 2611 destructor
	
	11 destrucotr
	17 destrucotr
	
	-------------------------------------
	{
	MyClass m1(17);
	MyClass m2(11);
	MyClass* m3 = new MyClass[3]{ 10,20,30 };
	delete []m3;
	}
	
	o/p:-
	
	30 destrucotr
	20 destrucotr
	10 destrucotr
	11
	17
	
	----------------------------------------
	-----
	In brief, conceptually malloc and new allocate from different heaps, so can’t free or delete each other’s memory. They also operate at different levels – raw memory vs. constructed objects.
	
	New Vs Malloc 
	
	-- new is operator 
	-- malloc is a function which return void* pointer .
	--New calls default constructor implicitly
	--Malloc will not call constructor implicitly
	
	-------
	
	New and free
	free will not call destructor implicitly. it will lead to memory leak or heap corrupt or memory issue if we had assigned memory to the pointer which is memeber variable of our class.
	
	thats why alsway use delete with new and delete[] with new []
	
	--------
	malloc and delete
	mallco will not call constructor
	delete will call destructor implicitley
	
	------
	
	if we need realloc in c++ then to avoid that we can use vector
	vector expands as needed
	
--------------------------------------------------------------------------------------------------------------

Myclass *ptr=new MyClass[4];
diff betweeen delete ptr and delete[]ptr:=
---delete []ptr ensures that destructor will be invoked for all the objects which are allocated on heap.

--------------------------------------------------------------------------------------------------------------



Lvalue and Rvalue :  an expression is an rvalue if it creates a temporary object

int i=5;

-- i is a l value
-- value that resides in memory and thru which we can retrive the address
	int *ptr= &i;  
-- but we can't do that like below:-
	int *ptr =&5;
-- l  values is addressabel
-- can't be moved;
-- we can modify lvalue

class A{}
A a ;
a is lvalue


	

rvalue:-
	
-- resides on rigth side of assignment operator
-- non modifiable
-- can be moved
-- A a=A();
	A() ia a rvalue;


L value reference:-- 
-- bind only to lvalues but not r values .
-- but const l value refs are used to bind r values also
	we can assign a rvalue to a lvalue reference as like below only
	-- l value refrence must be a const

foo(int i&){} // this will not work

foo(const int &) // this will work

foo(10)  


R-value reference :--   an expression is an rvalue if it creates a temporary object
 --represent with &&
 -- bind only to rvales


int x=10;
int && rr=10;
int && rr2=foo(10);


--------------------------------------------------------------------------------------------------------------
		MOVE semantics
	
int i=5;

move(5)  :- it takes lvalue and converts it to rvalue;



#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
 
int main()
{
    std::string str = "Salut";
    std::vector<std::string> v;
 
    // uses the push_back(const T&) overload, which means
    // we'll incur the cost of copying str
    v.push_back(str);
    std::cout << "After copy, str is " << std::quoted(str) << '\n';
 
    // uses the rvalue reference push_back(T&&) overload,
    // which means no strings will be copied; instead, the contents
    // of str will be moved into the vector. This is less
    // expensive, but also means str might now be empty.
    v.push_back(std::move(str));
    std::cout << "After move, str is " << std::quoted(str) << '\n';
 
    std::cout << "The contents of the vector are {" << std::quoted(v[0])
              << ", " << std::quoted(v[1]) << "}\n";
}



Move Constructor:-

As we know, copy constructors are used to copying the data from an old object and assign it to the new object, while the move constructor is used to make a new pointer to the old object and transfers the resources to the heap memory. Simply put, the move constructor nulls away the temporary object's pointer and makes the declared object's pointer point to the data of the temporary object. As a result, the move constructor stops unnecessary data copying in the memory.

	

// C++ program without moving the constructor
#include <iostream>
#include <vector>

using namespace std;

class Move{
private: 
    // pointer
    int *p;
  
public:
    // Default constructor definition
    Move()
    {
        cout << "Default constructor invoked\n";
        p = new int ;
    }

    // Copy constructor definition
    Move(const Move& A)
    {       
        // copy of object A is created
        this->p = new int;
        cout << "Copy constructor invoked\n";
    }
    
    // Move constructor definition
    Move (Move&& A)
    {
        // It will simply help in pointing to the resource,
        // without creating a copy.
         cout << "Move constructor invoked\n";
        this->p = A.p;
        A.p = NULL;
    }

    // Destructor definition
    ~Move()
    {
        cout <<"Destructor invoked!\n";
        delete p;
    }

};

int main() 
{

  vector <Move> vec;
  vec.push_back(Move());

  return 0;

}



==========================================================================================================

	Generic Smart Pointer

#include "Common.h"
#include<iostream>
using namespace std;

class Person
{
	int age;
	char* name;
public:
	Person()
	{
		name = nullptr;
		cout << "default constructor" << endl;
	}
	Person(int _age,const char *_name):age(_age)
	{
		name = new char[strlen(_name) + 1];
		strcpy(name,_name);
		cout << "param pf person" << endl;
	}
	~Person()
	{
		if (name)
		{
			cout <<"dctor-- " << name << endl;
			delete []name;
		}
	}
	void Display()
	{
		cout << name << endl;
	}
};

class MyClass
{
	int age;
	char* name;
public:
	MyClass()
	{
		name = nullptr;
		cout << "default constructor" << endl;
	}
	MyClass(int _age, const char* _name) :age(_age)
	{
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
		cout << "param pf MyClass" << endl;
	}
	~MyClass()
	{
		if (name)
		{
			cout << "dctor-- " << name << endl;
			delete[]name;
		}
	}
	void Display()
	{
		cout << name << endl;
	}
};



template<typename T>
class Wrapper
{
	T* p;
public:
	Wrapper()
	{
		p = nullptr;
	}
	Wrapper(T *value):p(value)
	{
		cout << "param ctor" <<endl;
	}
	
	~Wrapper()
	{
		delete p;
	}

	T* operator->()
	{
		return p;
	}
	T& operator*()
	{
		return *p;
	}
};
int main()
{
	Wrapper<Person> S1(new Person(1711,"Kishor"));
	(*S1).Display();
	S1->Display();
	Wrapper<MyClass> S2(new MyClass(1611,"OJAS"));
	
}


==========================================================================================================

	Operator Overloading :--
	We cant use member function in case of if left hand operand/object is not class object
	MyClass
	Myclass m1,m2;
	m1=m2+no;   --> we can overload this in class as a member function
	m1=no+m2;   ->> for this we have to overload this operator ouside class as a non member function

==========================================================================================================


copy constructor is called in 3 situations
a) when object is initialized with another object
b) when object is passed as an argument ,and collected in 
another temporary object
c) when object is returned from a function and collected in
some other object

==========================================================================================================

	Copy assignment operator

when an already initialized object is re-initialized with other initialized object.

==========================================================================================================	

Fully Qualified class

#include "Common.h"
#include<iostream>
using namespace std;

class MyClass
{
private:
	char * name;

public:
	MyClass()
	{
		name = nullptr;
		cout << "def ctor" << endl;
	}
	MyClass(const char* _name)
	{
		name = new char[strlen(_name)+1];
		strcpy(name, _name);
		cout << "param ctor" <<endl;
	}
	MyClass(MyClass const &ref)
	{
		name = new char[strlen(ref.name)+1];
		strcpy(name,ref.name);
		cout << "copy ctor" << endl;
	}
	MyClass& operator=(MyClass &obj)
	{
		name = new char[strlen(obj.name + 1)];
		strcpy(name, obj.name);
		return *this;
		//return std::move(*this);
	}
	~MyClass()
	{
		delete[]name;
		cout << "\ninside destructor\n";
	}
	void disp()
	{
		cout << name << endl;
	}
};

int main()
{
	MyClass m1("sachin");
	m1.disp();
	MyClass m2;
	m2 = m1;
	m2.disp();;
	cout << "test" << endl;
	
}
