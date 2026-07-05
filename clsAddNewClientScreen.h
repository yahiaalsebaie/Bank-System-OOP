#pragma once
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsPerson.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include <iostream>
#include <string>

class clsAddNewClientScreen : protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& Client)
	{
		//Different ways to get input.

		cout << "\nEnter FirstName: ";
		clsPerson::PerformFirstName(Client); //Upcasting -> Zero Performance Overhead // PerformFirstName() here without any numbers or spatial characters.

		Client.LastName = clsInputValidate::ReadString("\nEnter LastName: "); // Normal input.

		cout << "\nEnter Email: ";
		clsPerson::PerformEmail(Client);

		cout << "\nEnter Phone: ";
		Client.PerformPhone(Client);

		cout << "Enter PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter Account Balance: ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();

		//cout << "Enter Gender [M/F]: "; //I didn't implement it and MartialStatus in output to keep it as simple as can.
		//Client.PerformGenderInfo(Client);
	}

	static void _PrintClient(const clsBankClient& Client)
	{
		cout << clsUtil::ColorText("\n[Client Card]", "#9b96bc");
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}



public:
	static void ShowAddNewClientScreen()
	{
		string AccountNumber = "";

		_DrawScreenHeader("\t Add New Client Screen");

		cout << "\nPlease Enter client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << clsUtil::ColorText("\nAccount Number Is Already Used, Choose another one: ", clsUtil::enColor::ORANGE);
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient newClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		_ReadClientInfo(newClient);

		clsBankClient::enSaveResults saveResult;

		saveResult = newClient.Save();

		switch (saveResult)
		{
		case clsBankClient::enSaveResults::svSucceeded:
			cout << clsUtil::ColorText("\nAccount Added Successfully\n\n", clsUtil::enColor::GOLD);
			_PrintClient(newClient);
			break;
		case clsBankClient::enSaveResults::svFaildEmptyObject:
			cout << clsUtil::ColorText("\nError: account was Not saved!\n\n", clsUtil::enColor::RED);
			break;

		}

	}

};

