#pragma once
#include <iostream>
#include <iostream>
#include "clsScreen.h"

using namespace std;

class clsShowLoginRegisterScreen : protected clsScreen  
{

private:

    static void _PrintLoginRecordLine(clsUser::stLoginRegister User)
    {

        cout << setw(8) << left << "" << "| " << setw(20) << left << User.Date;
        cout << "| " << setw(25) << left << User.UserName;
        cout << "| " << setw(15) << left << User.Password;
        cout << "| " << setw(15) << left << User.Permissions;
    }

public:

    static void ShowLoginsList()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
        {
            return;// this will exit the function and it will not continue
        }

        vector <clsUser::stLoginRegister> vUsers = clsUser::GetLoginsRecord();

        string Title = "\t  Login List Screen";
        string SubTitle = "\t\t\t\t    (" + to_string(vUsers.size()) + ") Login(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(20) << "Date";
        cout << "| " << left << setw(25) << "UserName";
        cout << "| " << left << setw(15) << "Password";
        cout << "| " << left << setw(15) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tThere isn't any login yet!";
        else

            for (clsUser::stLoginRegister User : vUsers)
            {
                _PrintLoginRecordLine(User);
                cout << endl;
            }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};

