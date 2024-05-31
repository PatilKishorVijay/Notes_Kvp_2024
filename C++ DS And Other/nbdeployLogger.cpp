#include "nbdeployLogger.h"


nbdeployLogger* nbdeployLogger::getLogger()
{
	// therad safe and double lock check 

	if (logger == nullptr)
	{
		mtx.lock();
		if (logger == nullptr)
		{
			logger = new nbdeployLogger;
		}
		mtx.unlock();
	}


	/*if (logger == nullptr)
	{
		logger = new nbdeployLogger;
	}*/
	return logger;
}

nbdeployLogger* nbdeployLogger::logger = nullptr;
int nbdeployLogger::cnt = 0;

void nbdeployLogger::log(string logmsg)
{
	cout << logmsg << endl;
}

mutex nbdeployLogger::mtx;
nbdeployLogger::nbdeployLogger()
{
	cnt++;
	cout << "instance count -- " << cnt<<endl;
}