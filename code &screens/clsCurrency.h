#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsString.h"
using namespace std;

class clsCurrency
{

	enum enMode { eEmptyMode = 1, eUpdateMode = 2 };

     enMode _Mode;
	 string _Country;
	 string _CurrencyCode;
	 string _CurrencyName;
	 float _Rate;

    string _CurrencyLine(string Separator = "#//#")
    {
        return  _Country + Separator
            + _CurrencyCode + Separator + _CurrencyName + Separator
            + to_string(_Rate);
    }

    static clsCurrency _ConvertLineToCurrencyObject(string Line, string Separator = "#//#")
    {
        clsCurrency CurrencyObj;

        vector <string> vCurrenciesData = clsString::Split(Line, Separator);

        CurrencyObj._Country = vCurrenciesData[0];
        CurrencyObj._CurrencyCode = vCurrenciesData[1];
        CurrencyObj._CurrencyName = vCurrenciesData[2];
        CurrencyObj._Rate = stof(vCurrenciesData[3]);

        return CurrencyObj;
    }

    static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Separator = "#//#")
    {

        string CurrencyRecord = "";
        CurrencyRecord += Currency._Country + Separator;
        CurrencyRecord += Currency._CurrencyCode + Separator;
        CurrencyRecord += Currency._CurrencyName + Separator;
        CurrencyRecord += to_string(Currency._Rate);

        return CurrencyRecord;
    }

    static  vector <clsCurrency> _LoadCurrenciesDataFromFile()
    {

        vector <clsCurrency> vCurrencyData;

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                vCurrencyData.push_back(Currency);
            }
            MyFile.close();
        }
        return vCurrencyData;
    }

    static void _SaveCurrenciesDataToFile(vector <clsCurrency> vCurrencies)
{
    fstream MyFile;
    MyFile.open("Currencies.txt", ios::out);

    string DataLine;

    if (MyFile.is_open())
    {
        for (clsCurrency& C : vCurrencies)
        {
            DataLine = _ConvertCurrencyObjectToLine(C);
            MyFile << DataLine << endl;
        }
        MyFile.close();
    }
}

    void _Update()
    {
        vector <clsCurrency> vCurrencies;
        vCurrencies = _LoadCurrenciesDataFromFile();

        for (clsCurrency & C : vCurrencies)
        {
            if (C.CurrencyCode() == CurrencyCode())
            {
                C = *this;
                break;
            }
        }
        _SaveCurrenciesDataToFile(vCurrencies);
    }

public:

    clsCurrency(enMode Mode,string Country, string CurrencyCode, string CurrencyName, float Rate)
    {
        _Mode = Mode;
        _Country = Country;
        _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrencyName;
        _Rate = Rate;
    }
   
    clsCurrency() {};

    bool IsEmpty()
    {
        return (_Mode == enMode::eEmptyMode);
    }

    string Country()
    {
        return _Country;
    }

    string CurrencyCode()
    {
        return _CurrencyCode;
    }

    string CurrencyName()
    {
        return _CurrencyName;
    }  

    void UpdateRate(float NewRate)
    {
        _Rate = NewRate;
        _Update();
    }

    float Rate()
    {
        return _Rate;
    }

    static clsCurrency FindByCode(string CurrencyCode)
    {

        CurrencyCode = clsString::UpperAllString(CurrencyCode);

        vector <clsCurrency> vCurrencies;

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                if (Currency.CurrencyCode() == CurrencyCode)
                {
                    MyFile.close();
                    return Currency;
                }
            }
            MyFile.close();
            return clsCurrency(eEmptyMode, "", "", "", 0);
        }
    }

    static clsCurrency FindByCountry(string Country)
    {
        Country = clsString::UpperAllString(Country);

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

                if (Currency.Country() == Country)
                {
                    MyFile.close();
                    return Currency;
                }
            }
            MyFile.close();
            return clsCurrency(eEmptyMode, "", "", "", 0);
        }
    }

    static bool IsCurrencyExist(string CurrencyCode)
    {
        clsCurrency Currency = FindByCode(CurrencyCode);
        return (!Currency.IsEmpty());
    }

    static bool IsCurrencyExistWithCountry(string Country)
    {
        clsCurrency Currency = FindByCountry(Country);
        return (!Currency.IsEmpty());
    }

    static vector <clsCurrency> GetCurrencyList()
    {
        return _LoadCurrenciesDataFromFile();
    }

    float ConvertToUSD(float amount)
    {
        return (float)(amount / Rate());
    }

    float ConvertToOtherCurrency(float amount,clsCurrency Currency2)
    {
        float USDCurrency = ConvertToUSD(amount);
        if (Currency2.CurrencyCode() == "USD")
        {
            return USDCurrency;
        }

        return (float)(USDCurrency * Currency2.Rate());
    }

};

