#include"Common.h"



void printRowWiseSum(int arr[][3], int r, int c)
{
	
	for (int i = 0; i < r; i++)
	{
		int sum = 0;
		cout <<endl<< "sum of row " << i + 1 <<"  =  ";
		for (int j = 0; j < c; j++)
		{
			sum += arr[i][j];
		}
		cout << sum << endl;

	}
}
void printColumnWiseSum(int arr[][3], int r, int c)
{
	for (int j = 0; j < c ; j++)
	{
		int sum = 0;
		cout<<"sum of " << j + 1 << " column =  ";
		for (int i = 0; i < r; i++)
		{
			sum += arr[i][j];
		}
		cout << sum << endl;
	}
}
void print2DArray(int arr[][3],int r,int c)
{
	
	for (int i= 0; i < r; i++)
	{

		for (int j = 0; j < c; j++)
		{
			cout << arr[i][j] << "  ";
		}
		cout << endl;
		

	}
}


void getMax(int arr[][3],int r,int c)
{
	int max = INT_MIN;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0;j < c; j++)
			if (arr[i][j] > max)
				max = arr[i][j];
	}

	cout << "max element of given array is :-- " << max << endl;
}

void getMin(int arr[][3], int r, int c)
{
	int min = INT_MAX;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0;j < c; j++)
			if (arr[i][j] < min)
				min = arr[i][j];
	}

	cout << "min element of given array is :-- " << min << endl;;
}

int main3()
{
	/*
		2-D array

		arr[3][3]=
		  0   1   2
		0[ 2   4   6 ]
		1[ 8   9  10 ]
		2[ 13  15  17]

	   above is just a visualization we can do

	   in actual 2 D array stored as below
	index  0 1 2 3 4 5  6  7   8
	values 2 4 6 8 9 10 13 15 17

	when we say

	arr[2][2] =?

	complier will do belo calculations with formula as

	(no.of column*i)+j) == (3*2)+2  = 8

	arr[8] == 17



	*/

	/*
		declaration and introduction
	*/
	//int arr[3][3];

	////initialization
	//int brr[3][3] = { {12,23,34}, {11,22,33}, {45,56,67} };
	//cout << "*****  row wise printing  ****" << endl << endl;
	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		cout << brr[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	//cout << endl<<"*****  Column wise printing   ****" << endl << endl;
	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		cout << brr[j][i] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << endl << "------------------------------------------------------------------------" << endl<<endl;

	//----------------------------------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------------------



//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


	/*
		Q.16 Row wise sum of 2 d array
	*/

	/*int arr[3][3] = { {12,23,34}, {11,22,33}, {45,56,67} };
	print2DArray(arr,3,3);

	printRowWiseSum(arr, 3, 3);
	cout << endl << endl;
	printColumnWiseSum(arr, 3, 3);*/


	//----------------------------------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------------------



	/*
		Q.17 Max /Min of 2D array
	*/

	/*int arr[3][3] = { {1,2,3},{1,3,7},{11,0,5 } };
	print2DArray(arr,3,3);
	getMax(arr,3,3);
	getMin(arr,3,3);*/



	/*
		Q.15 Transpose of a matrix using 2 D array
	*/
	/*int arr[4][3] = { { 12,23,34 }, { 11,22,33 }, {45,56,67},{78,89,90} };


	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "*****  Transpose of a MATRIX  ****" << endl << endl;
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/

  //  rotate by 90 degree
		//spiral print
		//median of matrix
	
// 2 - d array using vector---vector of vectors

	//vector< vector<int> >arr;

	//vector<int>a = { 1,2,3 };
	//vector<int>b = { 2,4};
	//vector<int>c = { 1,5,9,88 };

	//arr.push_back(a);
	//arr.push_back(b);
	//arr.push_back(c);

	//cout << "printing vectors of vector -- " << endl;


	////arr.size()  --- wil give us numbver of rows of the 2d-array
	//for (int i = 0; i < arr.size(); i++)
	//{
	//	// arr[i].size() --- wil give us the actual columns for that particular row
	//	 
	//	for (int j = 0; j < arr[i].size(); j++)
	//		cout << arr[i][j] << " ";
	//	cout << endl;
	//}

	//int row = 3;
	//int col = 7;

	//vector<vector<int>>arr1(row,vector<int>(col,0));
	///*
	//			vector<vector<int>> arr1(row,vector<int>(col,0));
	//			vector<vector<int>>  -- we are going to create a vector of vector<int>
	//			arr1(row,vector<int>(col,0));

	//			row -- will be used as size of outer vector

	//			col --- size of innner vectors in which we will place actual int values
	//			
	//			0 -- we are going to initialize the vector with zeroes

	//
	//*/
	//for (int i = 0; i < arr1.size(); i++)
	//{
	//	// arr[i].size() --- wil give us the actual columns for that particular row

	//	for (int j = 0; j < arr1[i].size(); j++)
	//		cout << arr1[i][j] << " ";
	//	cout << endl;
	//}

	
return 0;
	
}