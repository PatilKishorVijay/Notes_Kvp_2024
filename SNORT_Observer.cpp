#include"Includes.h"

#include<vector>


class Observer
{
public:
	virtual void update(const string & alertMessage) = 0;
};


class Logger :public Observer
{
public:
	void update(const string& alertMsg)
	{
		cout << "Logger :- " << alertMsg << endl;
	}
};

class Email_alert :public Observer
{
public:
	void update(const string& alertMsg)
	{
		cout << "Email Alert :- " << alertMsg << endl;
	}
};

class DetectionEngine {
	vector<Observer*> observers;
	string attackAlert;

public:
	void attach(Observer *observer)
	{
		observers.push_back(observer);
	}

	void detach(Observer* observer)
	{
		observers.erase(remove(observers.begin(), observers.end(),observer),observers.end());
		//observers.erase();
	}

	void notify() {
		for (auto observer : observers) {
			observer->update(attackAlert);
		}
	}

	void detectAttack(const std::string& alertMessage) {
		attackAlert = alertMessage;
		std::cout << "Detection Engine: Attack detected: " << alertMessage << std::endl;
		notify();  // Notify all observers
	}
};
int main()
{
	DetectionEngine detect;
	Logger log;
	Email_alert alert;

	detect.attach(&log);
	detect.attach(&alert);
	detect.detectAttack("sql injection attack detected");
	detect.detach(&log);

	detect.detectAttack("sql injection attack detected");



}
