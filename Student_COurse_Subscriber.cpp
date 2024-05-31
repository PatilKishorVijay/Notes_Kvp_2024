//student_subscrieber problem---yet unsolved

#include<iostream>
#include<vector>
#include<set>
#include<list>
using namespace std;

//void addPointsToSTL(vector<string> &points)
//{
//	set<string> s1;
//	for (auto x : points)
//		s1.emplace(x);
//	cout << endl;
//}
class Points;

//void addPointsToSTL(set<Points>& points)
//{
//
//}

class Student
{
	string name;
	int isSubscribed;

public:
	Student(string _name):name(_name)
	{
		isSubscribed = 0;
	}

	void setSubscribe(int x)
	{
		isSubscribed = x;
	}
	int getSubscribeFlag()
	{
		return isSubscribed;
	}
	void BroadCastMessage(string str)
	{
		cout << name << " broadcasting the msg as -- " << str << endl;
	}

};


class Youtube
{
	 list<Student> list;
public:
	 void GetSubsscription(Student& obj)
	{
		obj.setSubscribe(1);
		list.push_back(obj);
	}
	 void DoBroadcast(string str)
	{

		 for (auto x : list)
		 {
			 int no = x.getSubscribeFlag();
			 if (no == 1)
				 x.BroadCastMessage(str);
		 }
	}

	 void Unsubscribe(Student& obj)
	{
		 list.remove(obj);
	}

	 int getSubscribeCount()
	{
		 // add check with the student flag ob subscribe
		return list.size();
	}
};


int main()
{
	Student s1("abc");
	Student s2("xyz");
	Student s3("pqr");

	Youtube Channel;
	Channel.GetSubsscription(s1);
	Channel.GetSubsscription(s2);
	Channel.GetSubsscription(s3);
	Channel.DoBroadcast("CCTECH WAKAD");
	
	Channel.Unsubscribe(s2);

	cout << s2.getSubscribeFlag() << endl;
	cout << endl << endl;
	Channel.DoBroadcast("CCTECH WAKAD");
	//cout << Channel.getSubscribeCount() << endl;

	

}
