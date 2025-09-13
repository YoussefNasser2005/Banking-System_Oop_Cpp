#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsShowListCurrencies.h"
#include "clsUpdateRateScreen.h"
#include "clsFindCurrency.h"
#include "clsCalculateCurrenciesScreen.h"

using namespace std;

class clsShowCurrencyExchangeScreen : protected clsScreen
{

    enum enMainMenueOptions {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
        eCurrencyCalculator = 4, eExit = 5
    };

	static void _GoBackToMainMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";
		system("pause>0");
		system("cls");
		CurrencyExchangeMainScreen();
	}

    static short _ReadMainMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }  
	
	static void _ListCurrencies()
    {
        //cout << "List Currencies will be here...\n";	
		clsShowListCurrencies::ShowCurrenciesList();
    }
	
	static void _FindCurrency()
    {
        //cout << "Find Currency will be here...\n";	
		clsFindCurrency::ShowFindCurrency();
    }

	static void _UpdateCurrency()
    {
        //cout << "Update Currency will be here...\n";	
		clsUpdateRateScreen::UpdateRateScreen();
    }

	static void _CurrencyCalculator()
    {
        //cout << "Currency Calculator will be here...\n";
		clsCalculateCurrenciesScreen::ShowCurrencyCalculatorScreen();
    }

	static void _MainMenu()
    {
		_GoBackToMainMenu();
    }

    static void _PerformMainMenuOption(enMainMenueOptions CurrencyExchangeOption)
    {
		switch (CurrencyExchangeOption)
		{
			case eListCurrencies:
				system("cls");
				_ListCurrencies();
				_GoBackToMainMenu();

			case eFindCurrency:
				system("cls");
				_FindCurrency();
				_GoBackToMainMenu();
				break;
			case eUpdateRate:
				system("cls");
				_UpdateCurrency();
				_GoBackToMainMenu();
				break;
			case eCurrencyCalculator:
				system("cls");
				_CurrencyCalculator();
				_GoBackToMainMenu();
				break;
			case eExit:
				system("cls");
				_MainMenu();
				break;
		}
    }


public:

	static void CurrencyExchangeMainScreen()
	{
		_DrawScreenHeader("    Currency Exchange Main Screen");

		cout << "\t\t\t\t\t====================================\n";
		cout << "\t\t\t\t\t\tCurrency Exchange Menu\n";
		cout << "\t\t\t\t\t====================================\n";
		cout << "\t\t\t\t\t[1] List Currencies. \n";
		cout << "\t\t\t\t\t[2] Find Currency. \n";
		cout << "\t\t\t\t\t[3] Update Rate. \n";
		cout << "\t\t\t\t\t[4] Currency Calculator. \n";
		cout << "\t\t\t\t\t[5] Main Menu. \n";
		cout << "\t\t\t\t\t========================\n";
        _PerformMainMenuOption(enMainMenueOptions(_ReadMainMenuOption()));
	}

};

