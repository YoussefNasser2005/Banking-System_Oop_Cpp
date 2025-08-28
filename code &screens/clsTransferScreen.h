#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;

class clsTransferScreen : protected clsScreen
{

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAccount Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }

public:


	static void TransferBetween2Accounts()
	{
		_DrawScreenHeader("\t    Transfer Menu");

        string AccountNumber1, AccountNumber2 = "";

        cout << "\nEnter account number to transfer from: ";
        AccountNumber1 = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber1))
        {
            cout << "\nAccount number is already not found, Choose another one: ";
            AccountNumber1 = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber1);

        if (!Client1.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        _PrintClient(Client1);

        cout << "\n\nEnter account number to transfer to: ";
        AccountNumber2 = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber2))
        {
            cout << "\nAccount number is already not found, Choose another one: ";
            AccountNumber2 = clsInputValidate::ReadString();
        }

        clsBankClient Client2 = clsBankClient::Find(AccountNumber2);

        if (!Client2.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        _PrintClient(Client2);

        double amount;
        cout << "Enter Transfer Amount: ";
        cin >> amount;

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            while (!Client1.Transfer(amount,Client2,CurrentUser.UserName))
            {
                cout << "\nCannot withdraw Is suffecient Balance!, enter other amount: ";
                cin >> amount;
            }

            cout << "\nTransfer Done Successfully.\n";
            _PrintClient(Client1);
            _PrintClient(Client2);
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
            return;
        }
	}
};

