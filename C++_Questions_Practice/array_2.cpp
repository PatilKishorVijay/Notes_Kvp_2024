#include"Common.h"





void printArray(vector<int> _arr)
{
	cout << endl;
	for (auto x : _arr)
	{
		cout << x <<"  ";
	}
	cout << endl;
}
void printVector(vector<int>&v)
{
	for (auto x : v)
		cout << x << " ";
	cout << endl;
}
void findUnique(vector<int>v)
{
	int _xor = 0;
	for (int i = 0; i < v.size()-1 ;i++)
	{
		_xor = _xor^v[i] ;
	}
	cout << "unique element is :-- "<<_xor << endl;
}


void UnionOfArrays(int arr1[], int size1, int arr2[], int size2, vector<int>& ans)
{
	for (int i = 0; i < size1; i++)
		ans.push_back(arr1[i]);

	for (int i = 0; i < size2; i++)
		ans.push_back(arr2[i]);
}



void UnionWithoutDuplicates(int arr1[], int size1, int arr2[], int size2, vector<int>& ans)
{

	// using intersection logic to mark the duplicates as INT_MIN and also pushing 1st array into vector
	for (int i = 0; i < size1; i++)
	{
		int element = arr1[i];
		for (int j = 0; j < size2; j++)
		{
			if (arr1[i] == arr2[j])
				arr2[j] = INT_MIN;
		}
		ans.push_back(arr1[i]);
	}
	
	//pushing arrays 2 by without INT_Min elements
	for (int j = 0; j < size2; j++)
	{
		if(arr2[j]!=INT_MIN)
			ans.push_back(arr2[j]);
	}
	
}

void IntersectionOfArrays(int arr1[], int size1, int arr2[], int size2, vector<int>& ans)
{
	for (int i = 0; i < size1; i++)
	{
		int element = arr1[i];
		for (int j = 0; j < size2; j++)
		{
			if (element == arr2[j])
			{
				ans.push_back(arr1[i]);
				//marking already traveresed array so that we can avoid printing duplicate values
				arr2[j] = -1;
			}
		}
	}
}


void sort_zeroes_Ones(vector<int>&arr)
{
	int start = 0;
	int end = arr.size() - 1;
	int i = 0;
	while (start <= end)
	{
		if (arr[i] == 0)
		{
			swap(arr[i], arr[start]);
			i++;
			start++;

		}
		if (arr[i] == 1)
		{
			swap(arr[i], arr[end]);
			end--;
		}
	}
}

int removeDuplicates(vector<int>& nums) {

	vector<int>expected;
	int repeated = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		int cnt = 0;
		expected.push_back(nums[i]);
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[i] == nums[j])
			{
				cnt++;
				repeated++;
			}
			else
				break;
		}
		i += cnt;
	}
	nums.clear();
	for (int i = 0; i < expected.size(); i++)
		nums.push_back(expected[i]);
	return repeated;
}
int main2()
{
	///*vector is an dynamice array whose size is not fixed*/

	////create vector
	//vector<int>arr;

	//arr.push_back(12);
	//arr.push_back(23);

	//cout << "size of vector " << arr.size() << endl;  //how many elements are there ?
	//cout << "capacity " << arr.capacity() << endl;    // how much we can store ?

	//printArray(arr);
	//arr.pop_back();
	//printArray(arr);


	///* if we declare a vector with some size then the default value of the elements will be 0 */

	//vector<int>arr2(10);
	//printArray(arr2);

	///* so to initialize the vector with some default value other than zero then we have to use below syntax */

	//vector<int>arr3(10, -1);  //creating vector with 10 int elements having default value as -1
	//printArray(arr3);

	//// create vector with dynamic/run time size
	//cout << "*****************************************************************" << endl;
	//int n;
	//cout << "enter the size of vector u want to create" << endl;
	//cin >> n;
	//vector<int>arr4(n,-5);
	//printArray(arr4);

/*-----------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------*/



	// Q.7 find unique element in a vector where all elements occur " TWICE " except one element
	/*vector<int>v1 = { 8,4,5,8,5 };
	findUnique(v1);*/

	/*
		Q.8 union of 2 arrays 

		v1=11,22,33,44   //int array
		v2=12,23,34      // int array

		union=11,22,33,44,12,23,34;
	*/

	/*int v1[3] = {12,23,34};
	int v2[4] = {45,56,67,78};

	vector<int>ans;
	UnionOfArrays(v1,3,v2,4,ans);
	cout << "union of 2 arrays is as below:--" << endl;
	for (auto x : ans)
	{
		cout << x << "  ";
	}
	cout << endl;*/



	/*-----------------------------------------------------------------------------------*/
	/*-----------------------------------------------------------------------------------*/

	/*
		Q.9 Intersection of 2 arrays

		a=[1,2,3,4,5,6,8]
		b=[3,4,9,10]

		ans=[3,4];
	*/

	/*int arr1[] = {1,2,3,3,4,6,8};
	int arr2[] = {3,11,4,10};

	vector<int>ans;
	IntersectionOfArrays(arr1,7,arr2,4,ans);
	cout << "intersection of arrays is as below" << endl;
	printVector(ans);*/

/*-----------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------*/

	/*
		Q.10 union of arrays without duplicates

		a=1,2,4,6,8,10;
		b=3,4,5,6;

		ans=1,2,4,6,8,10,3,5;
	*/

	/*int arr1[] = { 1,2,4,6,8,10 };
	int arr2[] = {3,4,4,6};

	vector<int>ans;
	UnionWithoutDuplicates(arr1,6,arr2,4,ans);
	cout << "union of 2 arrays without duplicates is as below :-- " << endl;
	printVector(ans);*/
/*-----------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------*/

	/*
		Q.11 Pair sum
		a1=1,3,5,7,2,4,6
	
		sum=9;

		to find out 2 nos whose addition will br 9
	*/

	/*vector<int>arr{ 10,20,40,50,60,70 };
	for (int i = 0; i < arr.size(); i++)
	{
		int element = arr[i];
		for (int j = i + 1; j < arr.size(); j++)
			if(element+arr[j]==70)
			cout << "{"<<element << " " << arr[j] <<"}" << " ";
		cout << endl;

	}*/

	/*-----------------------------------------------------------------------------------*/
	/*-----------------------------------------------------------------------------------*/
	/*
	*	Q.11 Tripplet Sum
	* a=10,20,30,40,50
	* sum=80
	* 
	* Ans= 10,20,50
	*/
	/*vector<int>arr{ 10,20,40,50,30,70,80 };
	for (int i = 0; i < arr.size()-2; i++)
	{
		int element = arr[i];
		for (int j = i + 1; j < arr.size()-1; j++)
		{
			for (int k = j+1; k < arr.size(); k++)
				if (element + arr[j] + arr[k] == 80)
					cout << "{" << element << " " << arr[j] << " " << arr[k] << "}\n";

		}
		cout << endl;

	}*/
	/*-----------------------------------------------------------------------------------*/
	/*-----------------------------------------------------------------------------------*/
	/*
	*	Q.12 Sort 0's and 1's
	*/
	
	/*vector<int>arr = {1,1,0,0,1,0,1,0,1,1 };
	cout << "before sorting\n";
	printVector(arr);
	sort_zeroes_Ones(arr);
	cout << "\nafter sorting\n";
	printVector(arr);*/

//Q.13 Left rotate an array by 1
//Q.14 Majority element in an array
//Q.15 Buy n Sell stock -- >level 1

	/*-----------------------------------------------------------------------------------*/
	/*-----------------------------------------------------------------------------------*/
	/*
		Q.13 Remove duplicates from an array
	*/
	/*vector<int>arr = { 1,1,2};
	printVector(arr);
	cout << endl;
	cout << removeDuplicates(arr) << endl;
	printVector(arr);*/





return 0;
}




