Maps are associative containers that store elements in a mapped fashion. Each element has a key value and a mapped value. No two mapped values can have the same key values.

begin() – Returns an iterator to the first element in the map.
end() – Returns an iterator to the theoretical element that follows the last element in the map.
size() – Returns the number of elements in the map.
max_size() – Returns the maximum number of elements that the map can hold.
empty() – Returns whether the map is empty.
pair insert(keyvalue, mapvalue) – Adds a new element to the map.
erase(iterator position) – Removes the element at the position pointed by the iterator.
erase(const g)– Removes the key-value ‘g’ from the map.
clear() – Removes all the elements from the map.

#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;
int main()
{
	//vector<int>v1 = { 11,22,33 };
	//vector<int>v2 = { v1.begin(),v1.end() };
	//cout << &v1[0] << endl;cout << &v2[0] << endl;

	map<int, const char*> info;

	info.insert(pair<int, const char*>(2, "Jayshri"));
	info.insert(pair<int, const char*>(1, "kishor"));

	info.insert(pair<int, const char*>(3, "Ojas"));

	info[7] = "Vandana";
	info[4] = "Ojas";

	map<int, const char*>::iterator itr;
	for (itr = info.begin(); itr != info.end(); itr++)
	{
		cout << (*itr).first << "  " << (*itr).second << endl;
	}


	int no;
	cin >> no;
	map<int, const char*>::iterator i = info.find(no);
	if (i != info.end())
		cout << (*i).first << "  " << (*i).second << endl;
	else
		cout << "key not found" << endl;
}
