#pragma once
#include <iostream>
#include "clsScreen.h"

using namespace std;

class clsShowTransferLogScreen : protected clsScreen
{
	

    static void _PrintLoginRecordLine(clsBankClient::stTransferLog TransferLog)
    {

        cout << setw(8) << left << "" << "| " << setw(20) << left << TransferLog.Date;
        cout << "| " << setw(10) << left << TransferLog.A1_AccountNumber;
        cout << "| " << setw(10) << left << TransferLog.A2_AccountNumber;
        cout << "| " << setw(15) << left << TransferLog.amount;
        cout << "| " << setw(15) << left << TransferLog.A1_AccountBalance;
        cout << "| " << setw(15) << left << TransferLog.A2_AccountBalance;
        cout << "| " << setw(20) << left << TransferLog.UserName;
    }

public:

	static void ShowTransferLogScreen()
	{

        vector <clsBankClient::stTransferLog> vClients = clsBankClient::GetTransferList();

        string Title = "\t  Transfer List Screen";
        string SubTitle = "\t\t\t\t  (" + to_string(vClients.size()) + ") Transfer Actions.";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(20) << "Date";
        cout << "| " << left << setw(10) << "A1.AccNum";
        cout << "| " << left << setw(10) << "A2_AccNum";
        cout << "| " << left << setw(15) << "Amount";
        cout << "| " << left << setw(15) << "A1_Balance";
        cout << "| " << left << setw(15) << "A2_Balance";
        cout << "| " << left << setw(20) << "UserName";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tThere isn't any login yet!";
        else

            for (clsBankClient::stTransferLog &Client : vClients)
            {
                _PrintLoginRecordLine(Client);
                cout << endl;
            }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________________________\n" << endl;
	}

};

