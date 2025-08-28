#pragma once
#include <iostream>
#include "clsDate.h"
using namespace std;

class clsInputValidate
{

public:

	static bool IsNumberBetween(short a, short from, short to)
	{
		return a >= from && a <= to;
	}

	static bool IsNumberBetween(int a, int from, int to)
	{
		return a >= from && a <= to;
	}

	static bool IsNumberBetween(float a, float from, float to)
	{
		return a >= from && a <= to;
	}

	static bool IsDateBetween(clsDate Date, clsDate from, clsDate to)
	{
		return (clsDate::CompareDates(Date, from) != clsDate::enCheckDates::Before) &&
			(clsDate::CompareDates(Date, to) != clsDate::enCheckDates::After);
	}

	static int ReadIntNumber(string s)
	{
		int Number;
		cin >> Number;

		while (cin.fail() || Number < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input! " << s;
			cin >> Number;
		}

		return Number;
	}	
	
	static float ReadFloatNumber()
	{
		float Number;
		cin >> Number;

		while (cin.fail() || Number < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input! ";
			cin >> Number;
		}

		return Number;
	}

	static double ReadDbNumber(string s)
	{
		double Number;
		cout << "Enter Double Number";
		cin >> Number;

		while (cin.fail() || Number < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input! " << s;
			cin >> Number;
		}

		return Number;
	}	
	
	static double ReadDbNumber()
	{
		double Number;
		cin >> Number;

		while (cin.fail() || Number < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input! Enter Correct Number";
			cin >> Number;
		}

		return Number;
	}

	static short ReadShortNumberBetween(short from ,short to, string s)
	{
		short Number = ReadIntNumber(s);
		while (!IsNumberBetween(Number,from,to))
		{
			cout << s << '\n';
			Number = ReadIntNumber(s);
		}
		return Number;
	}

	static bool IsLeapYear(short Year)
	{
		return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
	}

	static bool IsValidDate(const clsDate& Date)
	{
		return clsDate::IsValid(Date);
	}

	static string ReadString()
	{
		string s = "";
		getline(cin >> ws, s);
		return s;
	}

};

