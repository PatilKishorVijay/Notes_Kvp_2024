#include "Common.h"

/*
	Can Ctor be private ?

	--- Yes  there are 2 used cases: --
		1) we can create the object of that class from another class who is declared as friend class. E.G class BoxFactory
		2) singleton desing pattern  -- to maintain a single object throughout the execution of the program

*/

class Box
{
	int width;
	Box(int _w) :width(_w)
	{

	}
public:

	
	int get_width()const
	{
		return width;
	}

	void set_width(int _w)
	{
		width = _w;
	}

	friend class BoxFactory;
};
class BoxFactory
{
public:
	Box getBox(int _w)
	{
		return Box(_w);
	}
};