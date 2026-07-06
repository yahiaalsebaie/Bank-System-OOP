#pragma once
#include "clsInputValidate.h"
#include "clsPerson.h"
#include "clsString.h"
#include "clsUtil.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class clsBankClient : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete = false;

	/*const string _ClientsFileName = "Clients.txt";
	const string _UsersFileName = "Users.txt";*/


	static string _ConvertClientObjectToLine(const clsBankClient& Client, string Separator = "#//#")
	{
		string ClientObj = "";
		ClientObj += Client.FirstName + Separator;
		ClientObj += Client.LastName + Separator;
		ClientObj += Client.Email + Separator;
		ClientObj += Client.Phone + Separator;
		ClientObj += Client.AccountNumber() + Separator;
		ClientObj += Client.PinCode + Separator;
		ClientObj += to_string(Client.AccountBalance);

		return ClientObj;
	}


	static clsBankClient _ConvertLineToClientObject(string Line, string Separator = "#//#")
	{
		vector<string> vClientData = clsString::Split(Line, Separator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static vector<clsBankClient> _LoadClientsDataFromFile(string FileName = "Clients.txt")
	{
		vector<clsBankClient> vClients;
		fstream myFile;
		myFile.open(FileName, ios::in);//Read (input) mode.

		if (myFile.is_open())
		{
			string line;
			while (getline(myFile, line))
			{
				if (line == "")
					continue;
				clsBankClient Client = _ConvertLineToClientObject(line);
				vClients.push_back(Client);
			}
			myFile.close();
		}
		return vClients;
	}
	static void _SaveClientsDataToFile(const vector<clsBankClient>& vClients)
	{
		string FileName = "Clients.txt";
		fstream myFile;
		myFile.open(FileName, ios::out);

		if (myFile.is_open())
		{
			string line;
			for (const clsBankClient& c : vClients)
			{
				if (c._MarkForDelete == false)
				{
					line = _ConvertClientObjectToLine(c);
					myFile << line << endl;
				}
			}
			myFile.close();
		}
	}

	static void _AddDataLineToFile(string FileName, const string DataLine)
	{
		fstream myFile;
		myFile.open(FileName, ios::out | ios::app);

		if (myFile.is_open())
		{
			myFile << DataLine << endl;
			myFile.close();
		}
	}
	void _Update()
	{
		vector <clsBankClient> _vClients = _LoadClientsDataFromFile("Clients.txt");

		for (clsBankClient& c : _vClients)
		{
			if (c.AccountNumber() == AccountNumber())
			{
				c = *this; // *this == updated information
				break;
			}
		}
		_SaveClientsDataToFile(_vClients);
	}

	void _AddNew()
	{
		_AddDataLineToFile("Clients.txt", _ConvertClientObjectToLine(*this));
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
	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFailedAccountNumberExists = 2 };

	bool IsEmpty() { return (_Mode == enMode::EmptyMode); }

	string AccountNumber() const { return _AccountNumber; } // Get only

	void SetPinCode(string PinCode) { _PinCode = PinCode; }
	string GetPinCode() const { return _PinCode; }
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance) { _AccountBalance = AccountBalance; };
	float GetAccountBalance() const { return _AccountBalance; }
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;


	/*void Print() //No UI Related code inside object.
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

	}*/


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

	static void PerformIsClientAccountNumberExist(string& AccountNumber, string ErrorMessage = "\nAccount number is not found, choose another one: ")
	{
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			if (ErrorMessage != "") cout << clsUtil::ColorText(ErrorMessage, clsUtil::enColor::ORANGE);
			AccountNumber = clsInputValidate::ReadString();
		}
	}

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case clsBankClient::EmptyMode:
			return enSaveResults::svFaildEmptyObject;

		case clsBankClient::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
		}
		case clsBankClient::AddNewMode:
		{
			if (clsBankClient::IsClientExist(_AccountNumber))
				return enSaveResults::svFailedAccountNumberExists;
			else
			{
				_AddNew();
				return enSaveResults::svSucceeded;
			}

		}

		}
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	//--Delete--//
	bool Delete()
	{
		vector <clsBankClient> _vClients = _LoadClientsDataFromFile();

		for (clsBankClient& c : _vClients)
		{
			if (_AccountNumber == c._AccountNumber)
			{
				c._MarkForDelete = true;
				break;
			}
		}
		_SaveClientsDataToFile(_vClients);
		*this = _GetEmptyClientObject();
		return true;
	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalances(const vector <clsBankClient>& vClients)
	{
		double totalBalances = 0;

		for (const clsBankClient& c : vClients)
		{
			totalBalances += c.AccountBalance;
		}
		return totalBalances;

	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}
	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance) return false;
		else
		{
			_AccountBalance -= Amount;
			Save();
		}
		return true;

	}
};
