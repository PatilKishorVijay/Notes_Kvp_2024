#include "Abstraction_Bird.h"


/*
	abstraction :-

	-- delivering only essential info to outer world while hiding/masking background details
	-- desing and programming method whihc separated INTERFACE from the IMPLEMENTATION
	-- Example -- we just calles SORT function from alorithms header for varius data types.
				  But we dont know actual implementation for the same

*/

void bird_does_something(Bird * bird)
{
	bird->eat();
	bird->fly();
}

int main17()
{
	Bird* bird = new Sparrow();
	bird_does_something(bird);
	Crow *c = new Crow();
	bird_does_something(c);
	return 0;
}