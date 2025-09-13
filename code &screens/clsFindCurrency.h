#pragma once
#include <iostream>
#include "clsScreen.h"


class clsFindCurrency : protected clsScreen
{

    static void _PrintCurrency(clsCurrency & Currency)
    {

        cout << "\nCurrency Found -:)\n\n";
        cout << "\nCurrency Card:";
        cout << "\n___________________";
        cout << "\nCountry     : " << Currency.Country();
        cout << "\nCode        : " << Currency.CurrencyCode();
        cout << "\nName        : " << Currency.CurrencyName();
        cout << "\nRate        : " << Currency.Rate();
        cout << "\n___________________\n";
    }

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }

public:

    static void ShowFindCurrency()
    {
        _DrawScreenHeader("\tFind Currency Screen");

        short num = 0;
        string choice;
        cout << "\n Find With [1]:Code  [2]:Country  ";

        num = clsInputValidate::ReadShortNumberBetween(1,2);
        if (num == 1)
        {

            cout << "\n Enter Currency code: ";
        }
        else
        {
            cout << "\n Enter country name: ";
        }

        choice = clsInputValidate::ReadString();

        while (!(clsCurrency::IsCurrencyExist(choice) || clsCurrency::IsCurrencyExistWithCountry(choice)))
        {
            cout << "\nYour choice is not found, choose another one: ";
            choice = clsInputValidate::ReadString();
        }
        if (num == 1)
        {
            clsCurrency Currency = clsCurrency::FindByCode(choice);
            _ShowResults(Currency);
        }
        else
        {
            clsCurrency Currency = clsCurrency::FindByCountry(choice);
            _ShowResults(Currency);
        }
    }
};

