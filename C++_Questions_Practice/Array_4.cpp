#include "Common.h"


void print_Array(int arr[], int size)
{
	//cout << endl << "------------------------------------------------------" << endl;
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl << "------------------------------------------------------" << endl;
}


void print_vector(vector<int> arr)
{
	cout << "Printing vector" << endl << endl;
	for (auto x : arr)
	{
		cout << x << " ";
	}
	cout <<"------------------------------------" << endl;
}


void sortColors(vector<int> &_arr)
{
	int low=0, mid = 0;
	int high = _arr.size() - 1;
	while (mid <= high) {
		if (_arr[mid] == 0)
		{
			swap(_arr[low], _arr[mid]);
			low++;
			mid++;
		}
		else if (_arr[mid] == 1)
		{
			mid++;
		}
		else
		{
			swap(_arr[mid], _arr[high]);
			//mid++;
			high--;
		}
	}

}

void sortColors_SHORTCUT(vector<int>&ref)
{
	sort(ref.begin(),ref.end());
}

void moveNegativeNumbers(vector<int>&arr)
{
	int low = 0;

	//in-case if first elemet itself is negative

	if (arr[low] < 0)
		low++;
	for (int i = low; i < arr.size(); i++)
	{
		if (arr[i] < 0)
		{
			swap(arr[i],arr[low]);
			low++;
		}

	}
}

int main()
{

	
	//Q.sorting colors
	//*/
	//vector<int>arr= { 2,0,2,1,1,0 };

	//print_vector(arr);

	////sortColors_SHORTCUT(arr);   //using SORT function directly
	//
	//sortColors(arr);

	//print_vector(arr);
	// 
	//cout << "**********************************************************************************************************" << endl;
	/*
	
		Q.moving negative numvers of an array to left side
		Deutche National flag problem
	 */

	vector<int>arr2 = {-77, 1,2,-3,4,-5,6 };
	print_vector(arr2);
	moveNegativeNumbers(arr2);
	print_vector(arr2);
	
}