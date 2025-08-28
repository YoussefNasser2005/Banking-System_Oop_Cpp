#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsDate.h"
#include "clsGlobal.h"
using namespace std;

class clsScreen
{

protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\n\t\t\t\t\t____________________________________\n";
		cout << "\n\t\t\t\t\t" << Title << "\n";
		if (SubTitle != "")
		{
			cout << "\n\t\t" << SubTitle << endl;
		}
		cout << "\t\t\t\t\t____________________________________\n\n";
		cout << "\t\t\t\t\tUser: " << CurrentUser.UserName << endl;
		clsDate d = clsDate::GetSystemDate();
		cout << "\t\t\t\t\tDate: " << d.DateToString() << endl;
	}

	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessScreen(Permission))
		{
			cout << "\n\t\t\t\t\t____________________________________\n";
			cout << "\n\t\t\t\t\t" << "Access Denied!, Contact your access\n\n";
			cout << "\t\t\t\t\t____________________________________\n\n";
			return false;
		}
		else
			return true;
	}

};

