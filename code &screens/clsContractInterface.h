#pragma once
#include <iostream>
using namespace std;

class clsContractInterface
{


public:

	virtual void SendMail(string title, string body) = 0;	
	virtual void SendFax(string title, string body) = 0;
	virtual void SendPhone(string title, string body) = 0;

};

