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


==========================================================================================================
overloading of dot and arrow operator
*this -- return clone of object
this return pointer
class Myclass
{
	int num;
public:
	void disp()
	{
		cout <<"in disp funciton" << endl;
	}

	Myclass& operator*()
	{
		return *this;
	}
	Myclass* operator->()
	{
		return this;
	}
};
int main()
{
	Myclass m;
	(*m).disp();
	m->disp();
}
==========================================================================================================

	Memory leak handling:-
	smart pointer -- shared ptr , unique ptr;

they are implemented by using RAII concept: --
	Resource Aquisition in Initialization


#include<iostream>
using namespace std;

class Myclass
{
public:
	void disp()
	{
		cout << "myclas disp" << endl;
	}
	Myclass()
	{
		cout << "Myclass ctor" << endl;
	}
	~Myclass()
	{
		cout << "Myclass dtor" << endl;
	}
};
template<typename A>
class Wrapper
{
	A* classptr;
public:
	Wrapper(A* ptr):classptr(ptr)
	{
		cout << "inside ctor" << endl;
	}
	~Wrapper()
	{
		cout << "dctor" << endl;
		delete classptr;
	}
	A& operator*()
	{
		return *classptr;
	}
	A* operator->()
	{
		return classptr;
	}
};

int main()
{
	//Wrapper<int>obj1(new int(10));
	Wrapper<Myclass>obj2(new Myclass());
	(*obj2).disp();
	obj2->disp();
	return 0;
}

==========================================================================================================
can constructor be virtual ? No
The compiler must be aware of the class type to create the object. In other words, what type of object to be created is a compile-time decision from the C++ compiler perspective. If we make a constructor virtual, the compiler flags an error. 
==========================================================================================================

factory design pattern
https://www.geeksforgeeks.org/advanced-c-virtual-constructor/


==========================================================================================================

*** Virtual info  *** 

A VTABLE contains addresses of virtual functions.The compiler creates a VTABLE for each class that contains virtual functions and for classes that are derived from it.The VTABLE contains the addresses in the order in which virtual functions are defined within the class.

Whenever we create an object of the class,the class gets loaded into the memory and VTABLE gets created.

The address of the VTABLE stored in the object is known as VPTR.

The VTABLE belongs to a class.All objects of the class share the same VTABLE. The objects contain the address of the VTABLE in their first 2 bytes(under DOS) or in first 4 bytes(under Windows).
That is there is only one VTABLE per class and There is one VPTR per object.


Virtual function vs. Normal function

The call to virtual function is resolved at runtime.Moreover the call is resolved after retrieving the address of the function from the VTABLE.This consumes time.

The call to normal function is resolved at compile time. Also there is no mechanism of VTABLE involved in calling the normal function.


static functions can not be virtual because they are not related to objects.


Why member functions are not virtual by default?
	The mechanism of virtual functions is not very efficient.As compared to a simple call to an absolute address,there are more sophisticated assembly instructions required to set up the virtual function call.This requires both code space and execution time.All non-virtual function calls are implemented through early binding and all virtual function calls are implemented through late binding.Thus,had all function calls in C++ been implemented through late binding,the efficiency would have suffered heavily. 
Hence the virtual function is an option,and by default the language uses the non-virtual mechanism which is of course faster.



why destructors are not virtual by default?

base *b;
b=new sub;
Here,the base class constructor would be called followed by a call to sub class constructor.
If we say "delete b" then destruction should be proceed from sub to base.This can be ensured by declaring the base class destructor as "virtual".
When we declare virtual destructor,time spent in building the VTABLE. If we do not intend to create objects through new then there is no need for base class destructor to be virtual.Hence there is no need to create VTABLE.
Had destructors been virtual by default then unnecessarily time would have been spent for building VTABLE even if you don't need it.Hence destructors are not made virtual by default.




**** Late Binding ***** 

Connecting a function call to a function body is called binding. 
	When binding is performed before the program is run (by the compiler and linker), it is called by early binding.
	When binding is performed during program execution (runtime) , it is called a Late Binding.
	To cause a late binding to occur for a particular function, C++ requires that u use the "virtual" keyword when defining the function in the base class.

Late binding occurs only with virtual functions and only when u r using pointer to base class or reference to base class.
If a function is defined as "virtual" in the base class, it is "virtual" in all the derived class. The redefinition of a "virtual" function in a derived class is called as "overriding".
	The keyword "virtual" tells the compiler it should not perform early binding. Instead, it should automatically install all the mechanisms necessary to perform late binding. This means that if u call "draw()" function for a "Triangle" instance through "pointer of Shape" or "reference of shape", u will get proper function invocation.
	To accomplish this, the compiler creates a single table (called VTABLE) for each class that contains "virtual" functions. The compiler places the addresses of the virtual functions for that particular class in the VTABLE. In each class with virtual functions, it secretly places a pointer, called the vptr (virtual pointer i.e. VPTR), which points to the VTABLE for that object. 
When u make a virtual function call through a base class pointer or reference ( that is when u make polymorphic call ), the compiler quietly inserts code to fetch the VPTR and look up the function address in the VTABLE, thus calling correct function and causing late binding to take place.
	All of this - setting up the VTABLE for each class, initializing the VPTR, inserting the code for the virtual function call - happens automatically, so u don't have to worry about it. With virtual functions, the proper function gets called for an object, even if the compiler cannot know the specific type of the object.

compiler's instrctions:-
	when compiler encounters any polymorphic call, it generates code like
a) see the content of base class pointer
b) access the object
c) get the vptr
d) call vptr+index function

( if there are 2 virtual functions defined in the order "disp1" and "disp2" respectively , then disp1 will be at index 0 and disp2 will be at index 1)

so if u call disp2, instruction (d) will be, call vptr+1 function.



=============================================
no separate vptr in child class , base class vptr is inherited 


-- vtable is created for a class not for each object
-- it is nothing but a static array containgn addres of virtual function pointers
-- vptr for each class is initialized with address of vtable of that class by compiler itself
--





















