#include "Includes.h"
#include<thread>
#include<mutex>
#include<condition_variable>

mutex m1;
condition_variable cv1;
int cnt = 0;


bool isEven()
{
	return cnt % 2 == 0;
}


bool isOdd()
{
	 return cnt % 2 == 1;
}


void printEven()
{
	while (1)
	{
		
			unique_lock<mutex> lock(m1);
			cv1.wait(lock, isEven);
			if (cnt >= 20) break;
			cout << "from even thread --" << cnt++ << endl;
			cv1.notify_all();
		
	}
}

void printOdd()
{
	while (1)
	{
		
		
			unique_lock<mutex> lock(m1);
			cv1.wait(lock, isOdd);
			if (cnt >= 20) break;
			cout << "from odd thread --" << cnt++ << endl;
			cv1.notify_all();
		

	}
}

int main()
{
	thread t1(printEven);
	thread t2(printOdd);

	t1.join();
	t2.join();
}




/*

/* unique_lock<mutex> gives ownership of the mutex, required for cv.wait().

cv1.wait(lock, isEven) waits until the isEven() condition is true:

If not true, it releases the lock and sleeps

Once woken up, it re-acquires the lock and re-checks isEven()

After printing, it calls notify_all() to wake up the other thread (odd printer) if it's waiting.*/

void printEven() {
	while (1) {
		if (cnt < 20) {
			unique_lock<mutex> lock(m1); // 🔐 Lock mutex to safely check and modify shared counter

			cv1.wait(lock, isEven);      // ⏸ Wait until it's even thread's turn (i.e., cnt is even)

			cout << "from even thread --" << cnt++ << endl;  // ✅ Print current even number, then increment

			cv1.notify_all();            // 🔔 Notify the odd thread (that might be waiting)
		}
		else
			break;
	}
}


*/
