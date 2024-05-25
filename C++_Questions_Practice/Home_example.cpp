#include"Common.h"

class Home
{
	int house_no;
	int floors;
	double length;
	double  width;
	

public:

	Home(int _hno,int _flrs,double _len,double _w):house_no(_hno),floors(_flrs),length(_len),width(_w)
	{

	}
	double getArea()
	{
		return length * width;
	}

	int getNoOfFloors()
	{
		return floors;
	}
	
	void buildNewFloor()
	{
		cout << "new floor built" << endl;
		floors++;
	}


	
};


