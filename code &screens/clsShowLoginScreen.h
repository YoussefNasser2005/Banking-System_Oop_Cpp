#pragma once
#include <iostream>
#include "clsMainScreen.h"
#include "clsGlobal.h"

using namespace std;

class clsShowLoginScreen : protected clsScreen
{

protected:

	static bool _Login()
	{
		bool LoginFailed = false;
		short count = 3;
		do
		{

			if (LoginFailed)
			{
				cout << "\n Invalid Username or password!\n\n";
				count--;
			}
			cout << "\n\nYou have " << count << " trie(s) to enter a correct account\n";

			if (count == 0)
			{
				system("cls");
				_DrawScreenHeader("\t   Closing program...");
				cout << "\nYou are locked out after 3 failed attempts.\n";
				return false;
			}

			string Username;
			cout << "Enter Username\n";
			cin >> Username;

			string Password;
			cout << "Enter Password\n";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);
			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.SaveLoginRegistration();
		clsMainScreen::ShowMainMenu();
		return true;
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t      Login Screen");
		return _Login();
	}

};

