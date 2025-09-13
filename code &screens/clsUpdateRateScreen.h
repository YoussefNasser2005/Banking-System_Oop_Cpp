#pragma once

#include "clsScreen.h"
 

class clsUpdateRateScreen : protected clsScreen
{

    static float _ReadNewRate()
    {
        float Rate = 0.0;
        cout << "\nUpdate currency rate:\n";
        cout << "_____________________\n\n";
        cout << "Enter New Rate: ";
        Rate = clsInputValidate::ReadFloatNumber();

        return Rate;
    }

    static  void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
    {

        cout << "\n" << Title << "\n";
        cout << "_____________________________\n";
        cout << "\nCountry       : " << Currency.Country();
        cout << "\nCode          : " << Currency.CurrencyCode();
        cout << "\nName          : " << Currency.CurrencyName();
        cout << "\nRate(1$) =    : " << Currency.Rate();
        cout << "\n_____________________________\n\n";

    }


public:

	static void UpdateRateScreen()
	{
		_DrawScreenHeader("Update Rate Screen");


        string choice;
        cout << "\n Please Enter Currency Code: ";

        choice = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(choice))
        {
            cout << "\nYour choice is not found, choose another one: ";
            choice = clsInputValidate::ReadString();
        }
        cout << "\nCurrency Found -:)\n";
        clsCurrency Currency = clsCurrency::FindByCode(choice);
        _PrintCurrencyCard(Currency);


        char ans;
        cout << "Ary you sure update the rate of this country?Y/N ";
        cin >> ans;
        if (tolower(ans) == 'y')
        {

            Currency.UpdateRate(_ReadNewRate());
            cout << "Currency rate updated successfully:-)\n\n";
            _PrintCurrencyCard(Currency);
        }
	}

};

