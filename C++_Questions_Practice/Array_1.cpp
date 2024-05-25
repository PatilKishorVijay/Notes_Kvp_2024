#include "Common.h"


void printArray(int arr[],int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int LinearSearch(int arr[], int size, int no)
{
	for (int i = 0; i < size; i++)
	{
		if (no == arr[i])
			return i + 1;
	}
	cout << "not found" << endl;
	return 0;
}


void Count_1_and_0(int arr[],int size)
{
	int zeroes = 0;
	int ones = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 0)
			zeroes++;
		if (arr[i] == 1)
			ones++;
	}
	cout << "count of 0s :- " << zeroes << endl;
	cout << "count of 1s is :- " << ones << endl;
}

void findMaxAndMin(int arr[], int size)
{
	int max = INT_MIN;
	int min = INT_MAX;
	for(int i=0;i<size;i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	cout << "max is " << max << endl;
	cout << "min is " << min << endl;

}



void printExtremes(int arr[],int size)
{
	int i = 0;
	int j = size - 1;

	while (i <= j)
	{
		if (i == j)
		{
			cout << arr[i] << " " << endl;
			break;
		}
		else
			cout << arr[i++] << " " << arr[j--];
		cout << " " << endl;
	}
	

}



void ReverseArray(int arr[],int size)
{
	int start = 0;
	int end = size - 1;

	while (start<=end)
	{
		if (start == end)
			break;
		else
		{
			arr[start] = arr[start] + arr[end];
			arr[end] = arr[start] - arr[end];
			arr[start] = arr[start++] - arr[end--];
		}
	}
	printArray(arr, 6);

}

int main1()
{

	/*
		Q.1 take array and initialize by taking inputand print double of its elements
	*/

	/*int arr_1[5];
	for (int i = 0; i < 5; i++)
		cin >> arr_1[i];
	for (int i = 0; i < 5; i++)
		cout << arr_1[i] * 2 << " ";
		cout << endl;*/

/*-----------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------*/

	/* pass by value :- creates value at function when called */

	/* if we pass array name to a function then we are passing it as reference default */

/*-----------------------------------------------------------------------------------*/


	/*
		Q.2  Linear search
	*/
	/*int arr[] = { 12,23,34,45,56 };
	printArray(arr,5);
	int key;
	cout << "enter key to find" << endl;
	cin >> key;
	
	if(LinearSearch(arr, 5, key))
		cout <<"found" << endl;*/


/*-----------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------*/

	/*
	*   Q.3 Program to count 1s and 0s in an array
	*/

	/*int arr[15] = { 1,0,0,1,0,1,0,1,0,1,1,1,1,0,0 };
	printArray(arr,15);
	Count_1_and_0(arr,15);*/

/*-----------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------*/

	/*
		 Q.4 T0 find max and Min from array using linear search
	*/

	/*int arr[5] = { 11,5,23,47,65 };
	printArray(arr,5);
	findMaxAndMin(arr, 5);*/

/*-----------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------*/

	/*
		Q.5  To find extremes

		arr=,1,2,3,4,5,6

		o/p ==> 1,6,2,5,3,4
	*/

	/*int arr[6] = {11,22,33,44,55,66};
	printArray(arr,6);
	printExtremes(arr,6);*/


/*-----------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------*/

	/*
	
	Q.6 Reverse an array
	*/

	int arr[6] = { 12,23,34,45,56 ,67};
	printArray(arr,6);
	ReverseArray(arr,6);



	//delete this ...addeed for main1
	return 0;  
}
