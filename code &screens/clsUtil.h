#pragma once
#include <iostream>
#include "clsDate.h"

using namespace std;

class clsUtil
{


public:

	enum enCharType
	{
		SamallLetter = 1, CapitalLetter = 2,
		Digit = 3, MixChar = 4
	};

	static void Srand()
	{
		::srand(time(0));
	}

	static int RandomNumber(int from, int to)
	{
		int randNum = rand() % (to - from + 1) + from;
		return randNum;
	}

	static char GetRandomCharacter(enCharType CharType)
	{
		switch (CharType)
		{
	
		case enCharType::SamallLetter:
		{
			return char(RandomNumber(97, 122));
			break;
		}
	
		case enCharType::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
			break;
		}

		case enCharType::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}

	
		case enCharType::MixChar:
		{
			int r = RandomNumber(1, 3);
			if (r == 1)
				return char(RandomNumber(97, 122)); 
			else if (r == 2)
				return char(RandomNumber(65, 90)); 
			else
				return char(RandomNumber(48, 57)); 
		}
		}
	}

	static 	string GenerateWord(enCharType CharType, short Length)
	{
		string Word;
		for (int i = 1; i <= Length; i++)
		{
			Word = Word + GetRandomCharacter(CharType);
		}
		return Word;
	}

	static string GenerateKey(enCharType CharType)
	{
		string Key = "";
		Key = GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4);
		return Key;
	}

	static void GenerateKeys(short NumberOfKeys, enCharType CharType)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : ";
			cout << GenerateKey(CharType) << endl;
		}
	}

	static void FillArrayWithKeys(string arr[100], int arrLength, enCharType CharType)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateKey(CharType);
	}

	static void PrintStringArray(string arr[100], int arrLength)
	{
		cout << "\nArray elements:\n\n";
		for (int i = 0; i < arrLength; i++)
		{
			cout << "Array[" << i << "] : ";
			cout << arr[i] << "\n";
		}
		cout << "\n";
	}

	static void ReadArray(int arr[100], int& arrLength)
	{
		cout << "\nEnter number of elements:\n";
		cin >> arrLength;

		cout << "\nEnter array elements: \n";
		for (int i = 0; i < arrLength; i++)
		{
			cout << "Element [" << i + 1 << "] : ";
			cin >> arr[i];
		}
		cout << endl;
	}

	static void PrintArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			cout << arr[i] << " ";

		cout << "\n";
	}

	static void Swap(int& A, int& B)
	{
		int Temp;
		Temp = A;
		A = B;
		B = Temp;
	}	
	
	static void Swap(float& A, float& B)
	{
		float Temp;
		Temp = A;
		A = B;
		B = Temp;
	}	
	
	static void Swap(string & A, string & B)
	{
		string Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(clsDate & A, clsDate& B)
	{
		clsDate Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1],
				arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void ShuffleArray(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1],
				arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void FillArrayWithRandomNumbers(int arr[100], int arrLength, short from,
		short to)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = RandomNumber(from, to);
	}

	static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType,
		short WordLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = "";
			for (int j = 0; j < WordLength; j++)
			{
				arr[i] += GetRandomCharacter(CharType);
			}
			cout << arr[i] << '\n';
		}
	}

	static string Tabs(short Tab)
	{
		string a = "";
		for (short i = 0; i < Tab; i++)
			a += "\t";

		return a;
	}

	static string EncryptText(string Text, short EncryptionKey = 5)
	{
		for (int i = 0; i <= Text.size(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	}

	static string DecryptText(string Text, short EncryptionKey = 5)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}

	static string NumberToText(int num)
	{
		if (num == 0)
		{
			return "";
		}

		if (num >= 1 && num <= 19)
		{
			string ArrSt[] = { "", "One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
			"Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","SevenTeen","Eighteen","Nineteen" };

			return ArrSt[num] + " ";
		}

		if (num >= 20 && num <= 99)
		{
			string ArrSt[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty",
			"Ninety" };
			return ArrSt[num / 10] + " " + NumberToText(num % 10);
		}

		if (num >= 100 && num <= 999)
		{
			return NumberToText(num / 100) + "hundred " + NumberToText(num % 100);
		}

		if (num >= 1000 && num <= 999999)
		{
			return NumberToText(num / 1000) + "Thousand " + NumberToText(num % 1000);
		}

		if (num >= 1000000 && num <= 999999999)
		{
			return NumberToText(num / 1000000) + "Million " + NumberToText(num % 1000000);
		}

		if (num >= 1000000000 && num <= 1999999999)
		{
			return"One Billion " + NumberToText(num % 1000000000);
		}
		else
		{
			return NumberToText(num / 1000000000) + "Billion " + NumberToText(num % 1000000000);
		}

	}


};

