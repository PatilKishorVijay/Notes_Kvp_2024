#pragma once
#include"Common.h"
#include<mutex>

class nbdeployLogger
{
	static nbdeployLogger* logger;
	static mutex mtx;
	static int cnt;
	//nbdeployLogger
	nbdeployLogger();
	nbdeployLogger(nbdeployLogger const &ref);
	nbdeployLogger operator=(nbdeployLogger& ref);
public:
	static nbdeployLogger* getLogger();
	void log(string logmsg);

};



