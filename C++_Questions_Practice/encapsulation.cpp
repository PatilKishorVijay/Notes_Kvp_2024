#include<iostream>
using namespace std;


/*
* encapsulation --- data hiding--(showing essential and not showing non -essentials )
*				--- achieved thru access modifiers
*				--- wrapping data and member function
*					EG. class..by default encapsulation
*
*
* Perfect Encapsulation:--
*					all data members are private.
					to access them via getters and setters

	uses:- to achieve security
		 -- to make class as read only


// also if we are calling any method of that clss from main or client code...they can just call that method they dont know the implementatin

EG:- a.bark()--- method will be called but how it barks they dont know..../// implementation hiding...providing securte layer to the code...from outside world...

*/

class animal
{
public:
	int age;
	int legs;

	animal()
	{

	}
	animal(int a, int l) :age(a), legs(l)
	{

	}
	void bark()
	{

	}

	friend void operator<<(ostream&, animal& ref);
};

void operator<<(ostream& os, animal& ref)
{
	cout << ref.age << endl << ref.legs << endl;
}

int main()
{
	animal a(25, 4);
	a.bark();  
	cout << a;
}