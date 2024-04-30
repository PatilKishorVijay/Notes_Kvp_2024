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
