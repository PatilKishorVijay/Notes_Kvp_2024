#include<iostream>
#include<vector>
#include<list>
using namespace std;
//
//class ISubscriber
//{
//public:
//	virtual void notify(string msg) = 0;
//};


class User //:public ISubscriber
{
	int id;

public:
	
	User(int _id) :id(_id) {}

	void notify(string msg)
	{
		cout << "user " << id << " received notification as " << msg << endl;
	}
};


class Channel
{
	list<User*>users;
public:
	Channel()
	{
		//users = nullptr;
	}

	void subscribe(User* u)
	{
		users.push_back(u);
	}

	void unsubscribe(User* u)
	{
		users.remove(u);
	}

	void broadcast(string msg)
	{
		for (auto x : users)
		{
			x->notify(msg);
		}
	}
};

int main()
{
	Channel* channel = new Channel;

	User* user1 = new User(1);
	User* user2 = new User(2);
	User* user3 = new User(3);

	channel->subscribe(user1);
	channel->subscribe(user2);
	channel->subscribe(user3);


	channel->broadcast("New video will come\n\n");


	channel->unsubscribe(user2);

	channel->broadcast("new video launched\n\n");
}


