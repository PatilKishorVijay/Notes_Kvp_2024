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

==========================================================================================

****vptr providede by compiler for each object . it is also inherited.
**** vtable is an static array and it is bind to class level not object level
*** when we create object , in constructor vptr is gets initialised to vtable's address of that particular class

==========================================================================================
no separate vptr in child class , base class vptr is inherited 


youtube--- saurabh shukla playlist 

-- vtable is created for a class not for each object
-- it is nothing but a static array containgn addres of virtual function pointers
-- vptr for each class is initialized with address of vtable of that class by compiler itself
-- if virtual functin is presaetnin any class :-
	compiler does 2 tasks :-
		-- creates a vtable
		-- initialises a vptr for an instance with the address of vtabel


==========================================================================================

---***  using parent class pointer or reference u can invoke only those methods which are available in parent class.

==========================================================================================
*** why vtable is for all classes is separate ?
class D : public A, public B, public C {.........}

If we dont store the base classes' vptrs in derived objects, that means you have to club all the virtual functions of all the base
classes (in case of multiple inheritance) into one vtbl that has a single vptr that will be stored in your object. Now, no problem in
accessing virtual functions of first subobject (like class A in the above code snippet) whose virtual function pointers are stored in
starting location of vtbl. But what happens in accessing other subobjects (like classes B and C in the above code snippet) virtual
functions. Their offsets will get disturbed as you have clubbed all the virtual functions into one vtbl. After all, compiler will access
virtual functions with their offsets only. Now you dont know what will be get called.


==========================================================================================


Copy COnstructor:- 
if in child class CC is not provided:-
	1) it will call base class CC implicitley
If we provided CC in child class , then it will call base class default constructor implicitly
to avoid that we have to call base class CC explicilty

If base class dont have CC then compiler provided CC gets called.



==========================================================================================



			**** Casting ****
1) static_cast:- 


int main()
{
	char c;
	int* p1 = (int*)(&c);   
	*p1 = 3;    //will pass at compile time but will crash at runtime

	// so to avoid runtime error its better it breaks at compile time.
	// to handle this we use static_cast as below
	int* p2 = static_cast<int*>(&c);
	return 0;
}



*** private inheritance violates inheritance---it acts alike a composition

in case of private inheritance trhere is no is-a relationship.
so inshort derived is not base class
so to typecase derived obj into base class is wrong 
but it is done with c-style casting which is wrong.
SO to avoid it we shud use static_cast so that it can be avoided.


class person
{

};

class student :private person
{

};

void eat(const person& ref) //anyone can eat
{
	cout << "eat" << endl;
}
void study(const student& ref) //students only studies
{
	cout << "study" << endl;
}
int main()
{
	person p;
	student s;
	eat(p);
	eat((person &)s);  // c-style cast which is not recommnend

	/*static_cast*/

	person obj = static_cast<person>(s);
	//immediatly it gives compile time error as conversion to inaccessible base class is not allowed

	study(s);
}


--------------------------------------------------------------------------------------

RTTI -- dynamic casting -- runtime type identification

-- The dynamic_cast operator is mainly used to perform downcasting (converting a pointer/reference of a base class to a derived class). It ensures type safety by performing a runtime check to verify the validity of the conversion.

-- provides a  standard way to determine the type of object during runtime...

-- if thereis polymorphic relationship between the classes i.e base class declared or defined any virtual function 
and we had created base class pointers to sub class objects .then at sometime we need to cast any of base class pointer into a
valid sub class pointer then we shud use RTTI/dynamic cast

-- base class has to be a polymorphic
-- on success :- return new type 
--on failure--- if pointer then return null
		if refernce then-- bad_cast exception

class animal
{
public:
	virtual void bark() {}
};
class dog :public animal
{
public:
	
};
class cat :public animal
{

};
int main()
{
	animal* a = new dog;
	animal* b = new cat;

	dog* d = dynamic_cast<dog*>(a);
}


-------------------------

3) const_cast:--  it is used to cast away the const ness of a variable

eg: const int *p  ==>>> int *p



use cases :-
	1) passing const data to a function which accepts non-const
	
	int fun(int *ptr)
{

}
int main()
{
	const int a = 5;
	const int* ptr=&a;
	fun(ptr);  // theo error as function not accepts const data

	// to avoid that we can use const_cast
	int* p = const_cast<int*>(ptr);
	fun(p);

}


//if the code is ours then we can change the declaation of function by adding const keyword
// but if using any lib function..in that case then we have to pass our varibale my removing their constness


	2) if we want to change non-const class members inside const member function

class myclass
{
	int x;
public:
	void test(int no)const
	{
		x = no;  // it will not allow  as function is constant

		const_cast<myclass*>(this)->x = no;  // this is way to do that
	}
};


**** usualyy we shud not try to change the value of const variable , otherwise it leads to undefined behaviour

int main()
{
	const int a = 5;
	const int* ptr=&a;

	int* p2 = const_cast<int*>(ptr);
	*p2 = 55;
	cout << *p2 << endl;
	cout << a << endl;


	// below both will print same address bbut above lines will print diff values
	//it is because for const variable compiler treat it as a macro and at compile time it replaces its value
	// while print a -- we are not printing the value stored at a we are just printing the macro which is replaced
	//so the values printed are diff for variable and pointer

	//**** to avoid such behaviour we shud not use const_cast to cast away the ocnstness of a dtaa memeber or a normal variable
	cout << &a << endl;
	cout << ptr << endl;


}




----------------------------------------------------------------------------------------

*** reinterpret cast

-- allows any pointer to be converted into any pointer
-- any integral type into poinetr type and vice versa


------------------------------------
/* Difference between typeid and dynamic_cast

typeid does not check complete inheritance hierarchy  i.e it does not use virtual table. Hence if u are using typeid , it is not compulsory to use polymorphic type.
--it only check till its immediate base class only 
dynamic_cast can check complete inheritance hierarchy i.e it uses virtual table for this purpose. Hence if u are using dynamic_cast , it you must have polymorphic type.

*/

#include<iostream>
#include<typeinfo.h>
using namespace std;
class base
{
public:
	virtual void disp(){}
};
class sub:public base
{
	public:
	void disp()
	{
		cout<<endl<<"in disp of sub\n";
	}
};
class sub1:public sub
{
public:
	void disp()
	{
		cout<<endl<<"in disp of sub1\n";
	}
};
void main()
{
	base *b=new sub1;
	sub *s1;
	sub1 *s2;
	/*s1=dynamic_cast<sub*>(b);
	if(s1)
	{
		s1->disp();
	}
	else
		cout<<"not successful\n";*/

	if(typeid(*b)==typeid(sub))
		cout<<"equal\n";
	else
		cout<<"not equal\n";

}
	
------------------------------------------------------------------------------------------------------------------------------


**** Namespace:-

Namespace provide the space where we can define or declare identifier i.e. variable,  method, classes.
--Using namespace, you can define the space or context in which identifiers are defined i.e. variable, method, classes. In essence, a namespace defines a scope.

		Advantage of Namespace to avoid name collision.
		
--Example, you might be writing some code that has a function called xyz() and there is another library available which is also having same function xyz(). Now the compiler has no way of knowing which version of xyz() function you are referring to within your code.
		
--A namespace is designed to overcome this difficulty and is used as additional information to differentiate similar functions, classes, variables etc. with the same name available in different libraries. 
		
--The best example of namespace scope is the C++ standard library (std) where all the classes, methods and templates are declared. Hence while writing a C++ program we usually include the directive using namespace std;

#include<iostream>
using namespace std;

namespace sp1
{
	template<class type>
	class myclass
	{
		type a;
	public:
		myclass(type a)
		{
			this->a = a;
		}
		void disp()
		{
			cout << a << endl;
		}
	};
}
namespace sp2
{
	template<class type1, class type2>
	class myclass
	{
		type1 a;
		type2 b;
	public:
		myclass(type1 a, type1 b)
		{
			this->a = a;
			this->b = b;
		}
		void disp()
		{
			cout << a << "\t" << b << endl;
		}
	};
}
void main()
{
	sp1::myclass<int>m1(20);
	m1.disp();
	sp2::myclass<float, int>m2(5.6f,1711);
	m2.disp();
}





------------------------------------------------------------------------------------------------------------------------------











