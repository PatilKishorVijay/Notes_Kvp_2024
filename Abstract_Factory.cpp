#include<iostream>
#include <vector>
#include "nbdeployLogger.h"
#include<thread>

using namespace std;

class IButton
{
public:
	virtual void Press() = 0;
};

class MacButton :public IButton
{
public:
	void Press()
	{
		cout << "Mac button presssed" << endl;
	}
};

class IFactory
{
public:
	virtual IButton* CreateButton() = 0;
};

class MacFactory :public IFactory
{
public:
	IButton* CreateButton()
	{
		return new MacButton;
	}
};

class GUIAbstractFactory
{
public:
	static IFactory* CreateFactory(string osType)
	{
		if (osType == "MAC")
			return new MacFactory;
	}
};

int main()
{
	string os;
	cin >> os;

	IFactory* fptr = GUIAbstractFactory::CreateFactory(os);
	IButton *button=fptr->CreateButton();

	button->Press();
}
