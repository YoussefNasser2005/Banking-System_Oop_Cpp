#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

class clsString
{
    string _value;

    static bool IsLetterVowel(char Char)
    {
        Char = tolower(Char);
        return Char == 'a' || Char == 'e' || Char == 'i' || Char == 'o' || Char == 'u';
    }

public:

    clsString(string value = "")
    {
        _value = value;
    }

    void SetValue(string value) { _value = value; }
    string GetValue() { return _value; }

    __declspec(property(get = GetValue, put = SetValue)) string value;

    enum EnWhatYouCount { SmallLetters = 0, CapitalLetters = 1, All = 2 };

    short Length() { return _value.length(); }
    static short Length(string s1) { return s1.length(); }

    string InvertCharacter() { return InvertCharacter(_value); }
    static string InvertCharacter(string String)
    {
        string invert;
        for (char& c : String)
            invert += (isupper(c)) ? tolower(c) : toupper(c);
        return invert;
    }

    short CountLetters(EnWhatYouCount WhatYouCount = All) { return CountLetters(_value, WhatYouCount); }
    static short CountLetters(string String, EnWhatYouCount WhatYouCount = All)
    {
        short Counter = 0;
        if (WhatYouCount == All)
            return String.length();
        for (char& c : String)
        {
            if (WhatYouCount == CapitalLetters && isupper(c)) Counter++;
            if (WhatYouCount == SmallLetters && islower(c)) Counter++;
        }
        return Counter;
    }

    string LowerAllString() 
    { 
       return LowerAllString(_value);
    }
    static string LowerAllString(string words)
    {
        for (char& c : words)
            c = tolower(c);
        return words;
    }

    string UpperAllString() 
    { 
        return UpperAllString(_value);
    }
    static string UpperAllString(string words)
    {
        for (char& c : words)
            c = toupper(c);
        return words;
    }

    short CountVowels() 
    { 
        return CountVowels(_value);
    }
    static short CountVowels(string s1)
    {
        short counter = 0;
        for (char& c : s1)
            if (IsLetterVowel(c)) counter++;
        return counter;
    }

    string RemovePunctuations()
    { 
        return RemovePunctuations(_value);
    }
    static string RemovePunctuations(string s1)
    {
        string result;
        for (char& c : s1)
            if (!ispunct((unsigned char)c))
                result += c;
        return result;
    }

    string ReverseString()
    {
        return ReverseString(_value);
    }
    static string ReverseString(string s1)
    {
        reverse(s1.begin(), s1.end());
        return s1;
    }

    string TrimLeft()
    {
        return TrimLeft(_value);
    }
    static string TrimLeft(string s1)
    {
        size_t start = s1.find_first_not_of(" ");
        return (start == string::npos) ? "" : s1.substr(start);
    }

    string TrimRight() 
    {
        return TrimRight(_value);
    }
    static string TrimRight(string s1)
    {
        size_t end = s1.find_last_not_of(" ");
        return (end == string::npos) ? "" : s1.substr(0, end + 1);
    }

    string Trim() 
    {
        return Trim(_value); 
    }
    static string Trim(string s1)
    {
        return TrimRight(TrimLeft(s1));
    }

    vector<string> Split(string delim = " ")
    {
        return Split(_value, delim);
    }
    static vector<string> Split(string s1, string delim = " ")
    {
        short pos = 0; string sword;
        vector<string> vString;
        while ((pos = s1.find(delim)) != string::npos)
        {
            sword = s1.substr(0, pos);
            if (!sword.empty())
                vString.push_back(sword);
            s1.erase(0, pos + delim.length());
        }
        if (!s1.empty())
            vString.push_back(s1);
        return vString;
    }

    string JoinString(vector<string>& vString, string delim) { return JoinStringStatic(vString, delim); }
  
    static string JoinStringStatic(vector<string>& vString, string delim)
    {
        string s1 = "";
        for (string& i : vString)
            s1 = s1 + i + delim;
        return s1.substr(0, s1.length() - delim.length());
    }

    static vector<string> ConvertLineToRecord(string line)
    {
        vector<string> vString = Split(line, "/");

        if (vString.size() != 5)
        {
            cerr << "Error: Invalid record format -> " << line << endl;
            return {}; 
        }

        return vString;
    }

    bool Contains(string word) 
    { 
        return Contains(_value, word);
    }
    static bool Contains(string text, string word)
    {
        return text.find(word) != string::npos;
    }

    string Replace(string search, string replace) 
    { 
        return Replace(_value, search, replace);
    }
    static string Replace(string text, string search, string replace)
    {
        size_t pos = 0;
        while ((pos = text.find(search, pos)) != string::npos)
        {
            text.replace(pos, search.length(), replace);
            pos += replace.length();
        }
        return text;
    }

    string RemoveExtraSpaces() 
    {
        return RemoveExtraSpaces(_value);
    }
    static string RemoveExtraSpaces(string s1)
    {
        string result;
        bool lastSpace = false;
        for (char c : s1)
        {
            if (c == ' ')
            {
                if (!lastSpace)
                {
                    result += c;
                    lastSpace = true;
                }
            }
            else
            {
                result += c;
                lastSpace = false;
            }
        }
        return Trim(result);
    }

    bool IsPalindrome()
    { 
        return IsPalindrome(_value);
    }
    static bool IsPalindrome(string s1)
    {
        string cleaned;
        for (char c : s1)
            if (isalnum((unsigned char)c))
                cleaned += tolower(c);

        string reversed = cleaned;
        reverse(reversed.begin(), reversed.end());
        return cleaned == reversed;
    }
};
