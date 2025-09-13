#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"


class clsShowListCurrencies : protected clsScreen
{
	 
	static void _PrintCurrenciesRecordLine(clsCurrency Currency)
	{

		cout << setw(8) << left << "" << "| " << setw(40) << left << Currency.Country();
		cout << "| " << setw(12) << left << Currency.CurrencyCode();
		cout << "| " << setw(40) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate();
	}

public:

	static void ShowCurrenciesList()
	{
		vector <clsCurrency> vObj1 = clsCurrency::GetCurrencyList();
		string title = "\t   Currencies List";
		string SubTitle = "\t\t\t\t   (" + to_string(vObj1.size()) + ") Currency.";

		_DrawScreenHeader(title,SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_____________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(12) << "Code";
		cout << "| " << left << setw(30) << "Name";
		cout << "| " << left << setw(20) << "Rate($)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_____________________________________________________\n" << endl;


		if (vObj1.size() == 0)
			cout << "\t\t\t\tNo Currencies Available In the System!";
		else

			for (clsCurrency Currency : vObj1)
			{

				_PrintCurrenciesRecordLine(Currency);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_____________________________________________________\n" << endl;


	}
};

