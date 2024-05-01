#include<iostream>
#include <vector>

using namespace std;
/*
-- without factory object creation was taking place in client code..
so in down the line if new  class introduced then we have to again change the cleint code

-- after creating factory class which creates the object and just reurn to client  , the tight coupling betweween cleint and object creation process gets loosen


*/
class Workload
{
public:
	virtual void takeBackup() = 0;
};


class FileSystem :public Workload
{
public:
	void takeBackup()
	{
		cout << "FileSystem backup initiated" << endl;
	}
};

class Oracle :public Workload
{
	void takeBackup()
	{
		cout << "Oracle backup initiated" << endl;
	}
};


class WorkloadFactory
{
public:
	static Workload* getWorkload(string);
};

Workload* WorkloadFactory::getWorkload(string WorkloadType)
{
	Workload* WD;
	if (WorkloadType=="FS")
	{
		return new FileSystem();
	}
	else if (WorkloadType == "ORACLE")
	{
		return new Oracle();
	}
}

int main()
{
	string type;
	cin >> type;
	Workload* wd = WorkloadFactory::getWorkload(type);
	wd->takeBackup();
}

