#pragma once
#include <iostream>
using namespace std;

class clsCalculator
{

private:
    short _num = 0;
    short _LastNum = 0;
    short _PreviousResult = 0;
    enum _enCalc { add = 1, sub = 2, div = 3, multi = 4, Cancel = 5 };
    _enCalc _LastOperation;

public:

    void Clear()
    {
        _num = 0;
        _PreviousResult = 0;
        _LastNum = 0;
    }

    void Add(short AddNum)
    {
        _PreviousResult = _num;
        _num += AddNum;
        _LastNum = AddNum;
        _LastOperation = add;
    }

    void Substract(short SumNum)
    {
        _PreviousResult = _num;
        _num -= SumNum;
        _LastNum = SumNum;
        _LastOperation = sub;
    }

    void Divide(short Divider)
    {
        if (Divider == 0)
            Divider = 1;
        _PreviousResult = _num;
        _num /= Divider;
        _LastNum = Divider;
        _LastOperation = div;
    }

    void Multiply(short MultiNum)
    {
        _PreviousResult = _num;
        _num *= MultiNum;
        _LastNum = MultiNum;
        _LastOperation = multi;
    }

    void CancelLastOp()
    {
        _num = _PreviousResult;
        _LastOperation = Cancel;
    }

    void PrintResult()
    {

        switch (_LastOperation)
        {
        case add:cout << "Result after adding " << _LastNum << " is: " << _num << '\n';  break;
        case sub:cout << "Result after substracting " << _LastNum << " is: " << _num << '\n';  break;
        case div:cout << "Result after dividing " << _LastNum << " is: " << _num << '\n';  break;
        case multi:cout << "Result after multiplying " << _LastNum << " is: " << _num << '\n';  break;
        case Cancel:cout << "Result after Cancel Last Num is: " << _num << '\n';  break;
        }
    }

    void GetFinalResult()
    {
        cout << "Final result is " << _num;
    }

};