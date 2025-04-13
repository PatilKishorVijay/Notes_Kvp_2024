#include "Includes.h"
#include<thread>
#include<mutex>

mutex mtx;
condition_variable cv1;

int state = 0;
int counter = 0;
thread_local int local_id;

bool threadState()
{
	return state % 4 == local_id;
}
 
void printChar(char c, int tid)
{
	local_id = tid;
	while (1)
	{
		unique_lock<mutex>lock(mtx);
		cv1.wait(lock, threadState);
		if (counter > 5) {
			
			cv1.notify_all();
			break;
		}
		cout << c;
		counter++;
		state++;
		cv1.notify_all();
	}
}
int main()
{
	thread t1(printChar,'A', 0);
	thread t2(printChar,'B', 1);
	thread t3(printChar,'C', 2);
	thread t4(printChar,'D', 3);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
}
