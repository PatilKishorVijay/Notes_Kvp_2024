#include<iostream>
#include <vector>

using namespace std;

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
