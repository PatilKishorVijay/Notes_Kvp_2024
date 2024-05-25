#include "Common.h"


class abc
{
	//if we want to change variable even in the constant function then we should use mutable keyword before the varable name
	// it will allow us the modify the values of that particular variable
	//mutable int x;  
	int x;
	int* y;
	const int z;
public:

	/*abc()
	{
		x = 0;
		y = new int(0);
	}*/

	
	//ctor -- old style
	/*abc(int _x,int _y,int _z=0)
	{
		x = _x;
		y = new int(_y);
		z = _z;  //error as declared as const ...initializer list used 
	}*/



	/*
		new way of ctor aka initializer list

		when there is const member variable then to initialize it we need this.

		old way will restrict as it will break the const constraint

	*/
	abc(int _x,int _y,int _z=0):x(_x),y(new int(_y)),z(_z)
	{
		cout << "init list" << endl;
	}


	/*
		made getX as constant member fucntion which 
		restricts change in data of the member variable
	*/

	int getX() const 
	{
		//x = 90;  //error  ---can be resolved by making variable mutable
		return x;
	}

	void setX(int a) 
	{
		x = a;
	}

	int getY() const
	{
		return *y;
	}

	void setY(int _val)
	{
		*y = _val;
	}


	//as we remove const from below function complier will throw error 
	//as we are trying to access the values of the object received as const in function printABC
	//So in order to work with const object respective function needs to be constant
	//it will not give error to getX and getY functions as they are const

	int getZ() const  
	{
		return z;
	}

};

void printABC(const abc& obj)
{

	cout << obj.getX() << endl;
	cout << obj.getY() << endl;
	cout << obj.getZ() << endl;  //error as getZ is non-const function so to make it work make that function as constant  
}

class Copy
{
public:
	int x;
	int* y;

	Copy(int _x, int _y) :x(_x), y(new int(_y))
	{

	}

	//deep copy ctor
	/*Copy(const Copy &obj)
	{
		x = obj.x;
		y = new int(*obj.y);
	}*/
	void print()const 
	{
		cout << "content of x "<<x << "\ncontent of y " << *y << endl;
		cout << "address y holding is -- " << y << endl;
		cout << endl << "-----------------------------------" << endl;
	}
	~Copy()
	{
		cout << "dtot called" << endl;
		delete y;
	}
};



class Static_class
{
public:
	static int x, y;
	int a, b;


	//non-static function can access static as wll as non-static members
	void print()
	{
		//cout << endl << "--------------------------------------" << endl;
		cout << endl<<x << "   " << y << endl;

		cout << endl << a << "  " << b << endl;
		cout << endl << "----------------------------------------------------------------------------------------" << endl;
	}


	static void show()
	{
		cout << endl << x << "   " << y << endl;

		//cout << endl << a << "  " << b << endl; //error  //static function will not access non-static members.
	}
};
int Static_class::x;
int Static_class::y;



/*
	lvalue == variables having memory locations

	rvalue == does not have memory location  EG-- reference int &a=b; 

*/
int main222()
{
	const int x = 10;

	//int* a = new int;
	//*a = 2;
	//cout << *a << endl;
	//delete a; //to avoid memory leak f
	//int b = 5;
	//a = &b;
	//cout << *a << endl; //5


	// const with pointers


	/*
					  LHS * RHS

					  const LHS of *  == data/variable is constant
					  const  RHS of * == pointer is constant

	*/

	//read always from right to left
	// const int* a 
	// 
	/*
		non - const pointer to a constant variable
		we can not change the value of the variable one's it is initialized
		but we can re-assign the pointer with the address of another variable
	*/


	//const int* a = new int(10);
	//
	//cout << *a << endl;

	//*a = 1711;   //error 
	//delete a; //to avoid memory leak f
	//int b = 5;
	//a = &b;
	//cout << *a << endl; //5

	/*
		constant pointer to a non - const variable

		we can change the value of the varibale but we cant't pint the pointer to another variable
	*/

	//int *const ptr = new int;

	//*ptr = 17;

	//delete ptr;

	//int b = 90;
	//ptr = &b; //errror

	/*
		constant pointer to a constant variable
	*/

	//const int * const ptr1 = new int(11);
	//cout << *ptr1 << endl;

	//*ptr1 = 17; //error

	//int b = 99;
	//ptr1 = &b;   //errror


	/*
	abc a;
	cout << a.getX() << endl;
	cout << a.getY() << endl;
	*/

	//abc obj1(17,11);
	//printABC(obj1);

	////testing for initializert list ctor
	//abc obj2(26,11,20);
	//cout << endl<<obj2.getX() << " " << obj2.getY() << "  " << obj2.getZ() << endl;

	/*
		shallow and deep copy
	 */
	 /*cout << "shallow and deep copy concepts\n\n" << endl;
	 Copy c1(15,04);
	 c1.print();
	 cout << endl;
	 Copy c2 = c1;

	 c2.print();


	 Copy* obj1 = new Copy(19,04);
	 Copy *obj2 = obj1;

	 obj1->print();
	 obj2->print();
	 delete obj1;

	 obj2->print();*/

	
	Static_class obj1{17, 11};
	obj1.x = 1;
	obj1.y = 2;
	

	return 0;
}