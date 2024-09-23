#include <memory>
#include <iostream>
#include<chrono>
using namespace std;

#include<mutex>
#include<condition_variable>
#include<list>


mutex mtx;
condition_variable cv1;

list<int>l1;

bool isListEmpty()
{
	return !(l1.empty());
}

void read_list()
{
	while (true)
	{
		unique_lock<mutex> lock(mtx);
		cv1.wait(lock, isListEmpty);

		cout << "reading element" << endl;
		cout << l1.front()<<endl;
		l1.pop_front();
		lock.unlock();
		this_thread::sleep_for(2ms);


	}
}

void write_list()
{
	for (int i = 0; i < 5; i++)
	{
		unique_lock<mutex> lock(mtx);
		cout << "adding element" << endl;
		l1.push_back(i);
		lock.unlock();
		cv1.notify_one();
		this_thread::sleep_for(2ms);
	}
}


int main()
{
	thread t1(read_list);
	thread t2(write_list);

	t1.join();
	t2.join();
}
