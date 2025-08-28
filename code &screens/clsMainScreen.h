#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsShowTransactionMenu.h"
#include "clsShowFindClientScreen.h"
#include "clsShowUpdateClientScreen.h"
#include "clsShowDeleteClientScreen.h"
#include "clsShowLoginRegisterScreen.h"
#include "clsManageUsersScreen.h"
#include "clsShowLoginScreen.h"
#include "clsGlobal.h"

using namespace std;

class clsMainScreen :protected clsScreen
{


private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister = 8, eExit = 9
    };

    static short _ReadMainMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 9]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 9, "Enter Number between 1 to 9? ");
        return Choice;
    }

    static void _GoBackToMainMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";
        system("pause>0");
        ShowMainMenu();
    }

    static void _ShowAllClientsScreen()
    {
        //  cout << "\nClient List Screen Will be here...\n";
        clsClientListScreen::ShowClientsList();


    }

    static void _ShowAddNewClientsScreen()
    {
        // cout << "\nAdd New Client Screen Will be here...\n";
        clsAddNewClientScreen::ShowAddNewClientScreen();

    }

    static void _ShowDeleteClientScreen()
    {
        //cout << "\nDelete Client Screen Will be here...\n";
        clsDeleteClientScreen::ShowDeleteClientScreen();

    }

    static void _ShowUpdateClientScreen()
    {
        //cout << "\nUpdate Client Screen Will be here...\n";
        clsUpdateClientScreen::ShowUpdateClientScreen();


    }

    static void _ShowFindClientScreen()
    {
        // cout << "\nFind Client Screen Will be here...\n";
        clsFindClientScreen::ShowFindClientScreen();


    }

    static void _ShowTransactionsMenu()
    {
        // cout << "\nTransactions Menue Will be here...\n";
        clsTransactionsScreen::ShowTransactionsMenu();

    }

    static void _ShowManageUsersMenu()
    {
        //cout << "\nUsers Menu Will be here...\n";
        clsManageUsersScreen::ShowManageUsersMenu();

    }

    static void _ShowLoginRegisterScreen()
    {
        //cout << "\nShow Login Register Screen Will be here...\n";
        clsShowLoginRegisterScreen::ShowLoginsList();
    }   
    
    static void _ShowEndScreen()
    {
        //cout << "\nEnd Screen Will be here...\n";
        CurrentUser = clsUser::Find("", "");
    }

    static void _PerformMainMenuOption(enMainMenueOptions MainMenuOption)
    {
        switch (MainMenuOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenu();
            _GoBackToMainMenu();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenu();
            _GoBackToMainMenu();
            break;

        case enMainMenueOptions::eLoginRegister:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenu();
            break;
        case enMainMenueOptions::eExit:
            system("cls");
            _ShowEndScreen();
            break;
        }
    }


public:

    static void ShowMainMenu()
    {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformMainMenuOption((enMainMenueOptions)_ReadMainMenuOption());
    }
};

