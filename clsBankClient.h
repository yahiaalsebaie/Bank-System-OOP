#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;
class clsBankClient : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

	/*const string _ClientsFileName = "Clients.txt";
	const string _UsersFileName = "Users.txt";*/


	/*static string _ConvertClientObjectToLine(const clsBankClient& Client, string Separator = "#//#")
	{
		string ClientObject = "";
		ClientObject += Client.AccountNumber + Separator;
		ClientObject += Client.Name + Separator;
		ClientObject += Client.Phone + Separator;
		ClientObject += Client.PinCode + Separator;
		ClientObject += to_string(Client.AccountBalance);

		return ClientObject;
	}*/


	static clsBankClient _ConvertLineToClientObject(string Line, string Separator = "#//#")
	{
		vector<string> vClientData = clsString::Split(Line, Separator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));
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

	bool IsEmpty() { return (_Mode == enMode::EmptyMode); }

	string AccountNumber() { return _AccountNumber; } // Get only

	void SetPinCode(string PinCode) { _PinCode = PinCode; }
	string GetPinCode() { return _PinCode; }
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance) { _AccountBalance = AccountBalance; };
	float GetAccountBalance() { return _AccountBalance; }
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";

	}


	static clsBankClient Find(const string& AccountNumber)
	{
		vector<clsBankClient> vClients;

		fstream myFile;
		myFile.open("Clients.txt", ios::in); //Read mode

		if (myFile.is_open())
		{
			string line;
			while (getline(myFile, line))
			{
				clsBankClient client = _ConvertLineToClientObject(line);
				if (client.AccountNumber() == AccountNumber)
				{
					myFile.close();
					return client;
				}
				vClients.push_back(client);
			}
		}
		return _GetEmptyClientObject();
	}
	static clsBankClient Find(const string& AccountNumber, const string& PinCode)
	{
		vector<clsBankClient> vClients;

		fstream myFile;
		myFile.open("Clients.txt", ios::in); //Read mode

		if (myFile.is_open())
		{
			string line;
			while (getline(myFile, line))
			{
				clsBankClient client = _ConvertLineToClientObject(line);
				if (client.AccountNumber() == AccountNumber && client.PinCode == PinCode)
				{
					myFile.close();
					return client;
				}
				vClients.push_back(client);
			}
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(const string& AccountNumber)
	{
		clsBankClient c = clsBankClient::Find(AccountNumber);

		return (!c.IsEmpty());
	}

	static void PerformAccountNumber(string AccountNumber, string ErrorMessage = "\nAccount number is not found, choose another one: ")
	{
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			if (ErrorMessage != "") cout << ErrorMessage;
			AccountNumber = clsInputValidate::ReadString();
		}
	}

};
