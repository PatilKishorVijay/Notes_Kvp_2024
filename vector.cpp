

	vector<int> vect = { 12,23,34,45,56,34 };

	for (auto x : vect)
	{
		cout << x << " ";
	}

	cout << endl;

	vect.erase(remove(vect.begin(),vect.end(),34), vect.end());
	for (auto x : vect)
	{
		cout << x << " ";
	}

std::remove is an algorithm from the <algorithm> header.

It reorders the vector so that all elements not equal to 34 are moved to the front, and returns an iterator to the new logical end of the "valid" range.

	in short at backend --- 12,23,45,56,34,34  (remove returns 4 as starting index to erase function )

It doesn’t actually erase anything—it just "marks" the redundant elements past the returned iterator.

	vect.erase(start_iterator, end_iterator)

start_iteratot gets -- 4 as address from remove function 
end_iterator -- gets from vect.end()


---------------------------------------------------------------------------
#include<iostream>
using namespace std;
#include<vector>

int main()
{
	vector<int> v = { 1,2,3,4,5,6,7};
	cout << "size of vector is --- " << v.size() << endl;

	cout << "capacity of vector is ---- " << v.capacity() <<endl;
	v.push_back(8);
	cout << "capacity of vector is ---- " << v.capacity() << endl;

	// cout << "accessing vector using []--" << v[8] << endl;
	//cout << "accesing using at()--- "<<v.at(8) << endl;
	/*
	*  = -- used for initializing a vector
	* vector<int>v={12,23,32}
	* 
	* []  -- to access any element randomly
	* 
	* at() -- 
	* 
	* v.front()  -- return first element --similar to v[0]
	* v.back()-- return last element 
	* v.shrink_to_fit -- if we inserted 4 elemnet sand due to that vector capacity grows to 8 ...we know that we have completed out task
	*					then in that case we can call this function whill free the extra memory allocated 
	* 
	* empty()  -- checks whether vector is empty or not
	* 
	* 
	*/

	cout << endl << endl << "testing for shrink_to _fit funtion" << endl << endl;
	cout << "capacity of vector is ---- " << v.capacity() << endl;
	cout << "size of vector is --- " << v.size() << endl;
	v.shrink_to_fit();
	cout << "** after calling shrink_to_fit *** " << endl << endl;
	cout << "capacity of vector is ---- " << v.capacity() << endl;
	cout << "size of vector is --- " << v.size() << endl;



}
// // when object are stored in STL ,their copies are stored



#include<iostream>
#include<vector>
using namespace std;
class MyClass
{
	int num;
public:
	MyClass()
	{
		num=0;
	}
	MyClass(int k)
	{
		num=k;
		cout<<endl<<"In parameterized const\n";
	}
	void setNum(int num)
	{
		this->num=num;
	}
	void disp()
	{
		cout<<endl<<num<<endl;
	}
};
void main()
{
	vector<MyClass> v1;
	unsigned int i=0,j=10;
	MyClass m1(100),m2(200);
	v1.push_back(m1);
	v1.push_back(m2);
	m1.setNum(500);
	m2.setNum(600);
	cout<<"m1 and m2 values"<<endl;
	m1.disp();
	m2.disp();
	cout<<"vector values"<<endl;
	for(i=0;i<v1.size();i++)
	{
		v1[i].disp();
	}
}


--------------------------------
if we create vector of myclass which is polymorphic
then we shud ccreate vector of pointer of myclass...push_back addresses of myclass objects

with this iterator  becomes double pointer ...(**itr).disp();
#include<iostream>
#include<vector>
using namespace std;
class base
{
public:
	virtual void disp()
	{
		cout << "in base disp" << endl;
	}
};
class sub :public base
{
public:
	void disp()
	{
		cout << "in sub disp" << endl;
	}
};
class sub1 :public base
{
public:
	void disp()
	{
		cout << "in sub1 disp" << endl;
	}
};
int main()
{
	vector<base*> v;
	base b;
	sub s;
	sub1 s1;
	v.push_back(&b);
	v.push_back(&s);
	v.push_back(&s1);
	vector<base*>::iterator itr = v.begin();
	for (itr=v.begin(); itr != v.end(); itr++)
	{
		(**itr).disp();
	}
}
-------------------------------------
