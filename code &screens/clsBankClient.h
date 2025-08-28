#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsUser.h"

using namespace std;
class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;

    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkedForDelete = false;

    struct stTransferLog;

    static clsBankClient::stTransferLog _GetEmptyTransferLog()
    {
        clsBankClient::stTransferLog T;

        T.Date = "";
        T.A1_AccountNumber = "";
        T.A2_AccountNumber = "";
        T.amount = 0;
        T.A1_AccountNumber = 0.0;
        T.A2_AccountNumber = 0.0;
        T.UserName = "";

        return T;
    }


    static clsBankClient _ConvertLineToClientObject(string Line, string Separator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Separator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

    }
      
    static stTransferLog _ConvertTransferLineToObject(string Line, string Separator = "#//#")
    {
        vector<string> vTransferData;
        vTransferData = clsString::Split(Line, Separator);

        if (vTransferData.size() < 7)
            return _GetEmptyTransferLog();


        stTransferLog stTransferLog;
        
        stTransferLog.Date = vTransferData[0];
        stTransferLog.A1_AccountNumber = vTransferData[1];
        stTransferLog.A2_AccountNumber = vTransferData[2];
        stTransferLog.amount = stof(vTransferData[3]);
        stTransferLog.A1_AccountBalance = stof(vTransferData[4]);
        stTransferLog.A2_AccountBalance = stof(vTransferData[5]);
        stTransferLog.UserName = vTransferData[6];
           
        return stTransferLog;
    }

    static string _ConvertClientObjectToLine(clsBankClient Client, string Separator = "#//#")
    {

        string stClientRecord = "";

        stClientRecord += Client.FirstName + Separator;
        stClientRecord += Client.LastName + Separator;
        stClientRecord += Client.Email + Separator;
        stClientRecord += Client.Phone + Separator;
        stClientRecord += Client.AccountNumber() + Separator;
        stClientRecord += Client.PinCode + Separator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;

    }

     string _PrepareTransferLog(float amount, clsBankClient AccountDeposit,
        string UserName,string Separator = "#//#")
     {
         string TransferLog = "";

         TransferLog += clsDate::GetCurrentDateTimeString() + Separator;
         TransferLog += AccountNumber() + Separator;
         TransferLog += AccountDeposit.AccountNumber() + Separator;
         TransferLog += to_string(amount) + Separator;
         TransferLog += to_string(AccountBalance) + Separator;
         TransferLog += to_string(AccountDeposit.AccountBalance) + Separator;
         TransferLog += UserName + Separator;

         return TransferLog;
     }

    void _RegisterTransferLog(float amount, clsBankClient AccountDeposit, 
        string UserName, string Separator = "#//#")
    {
        string FileData = _PrepareTransferLog(amount, AccountDeposit, UserName);

        fstream MyFile;
        
        MyFile.open("Transfer.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << FileData << endl;
            MyFile.close();
        }
    }

    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }  
    
    static  vector <stTransferLog> _LoadTransferClientsDataFromFile()
    {

        vector <stTransferLog> vClients;

        fstream MyFile;
        MyFile.open("Transfer.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {
                stTransferLog Client = _ConvertTransferLineToObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();
        }

        return vClients;

    }

    static void _SaveClientsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if (C.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _ConvertClientObjectToLine(C);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveClientsDataToFile(_vClients);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:


    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }


    struct stTransferLog 
    {
        string Date;
        string A1_AccountNumber;
        string A2_AccountNumber;
        float amount;
        float A1_AccountBalance;
        float A2_AccountBalance;
        string UserName;
   
    };

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    static clsBankClient Find(string AccountNumber)
    {


        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {



        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };
    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {

                return enSaveResults::svFaildEmptyObject;

            }

        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();

                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }



    }

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }

    bool Delete()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkedForDelete = true;
                break;
            }

        }

        _SaveClientsDataToFile(_vClients);

        *this = _GetEmptyClientObject();

        return true;

    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    static vector <clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    static vector <stTransferLog> GetTransferList()
    {
        return _LoadTransferClientsDataFromFile();
    }

    bool Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
        return true;
    }

    bool Withdraw(double Amount)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        _AccountBalance -= Amount;
        Save();
        return true;
    }

    bool Transfer(double Amount, clsBankClient & AccountDeposit,string UserName)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }

        Withdraw(Amount);
        AccountDeposit.Deposit(Amount);
        _RegisterTransferLog(Amount, AccountDeposit, UserName);

        return true;
    }

    static double GetTotalBalances()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        double TotalBalances = 0;

        for (clsBankClient Client : vClients)
        {

            TotalBalances += Client.AccountBalance;
        }

        return TotalBalances;
    }
};

