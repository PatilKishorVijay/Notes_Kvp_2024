#pragma once
#include "Common.h"
#include <algorithm>
#ifndef BIRD_H

#define BIRD_H

/*
	abstraction :-

	-- showing only essential info to outer world while hiding/masking background details
	-- desing and programming method whihc separated INTERFACE from the IMPLEMENTATION
	-- Example -- we just calles SORT function from alorithms header for varius data types.
				  But we dont know actual implementation for the same

	-- Abstraction divides code into 2 categories -- interface and inplementation.
		So when implementation changes no impact on interface.

*/

/*

//abstraction :-
	//we are just showing essential things only
	// client can only call getId method but dont know how id is retrived:-- we are hiding implementation of the functionality
*/


/*
	If we are creating a class with a pure virtual function then that class becomes interface for outside world

	classes inheriting this class must implement the pure virtual functions

*/


class Bird
{
public:
	virtual void eat() = 0;
	virtual void fly() = 0;

};

class Sparrow :public Bird
{
private:
	void eat()
	{
		cout << "sparrow is eating" << endl;
	}


	void fly()
	{
		cout << "sparrow is flying" << endl;
	}
};

class Crow :public Bird
{
private:
	void eat()
	{
		cout << "Crow is eating" << endl;
	}


	void fly()
	{
		cout << "Crow is flying" << endl;
	}
};




#endif // !BIRD_H

