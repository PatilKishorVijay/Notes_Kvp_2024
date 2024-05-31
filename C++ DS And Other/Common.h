#pragma once
#include<iostream>
#include <vector>
#include<thread>
#include<mutex>
using namespace std;


class Therad_Test
{
	int data;
public:
	Therad_Test(int no):data(no)
	{

	}

	void getData()
	{
		cout << "data is -- " << data << endl;
	}
	void setData(int no)
	{
		data = no;
	}
};