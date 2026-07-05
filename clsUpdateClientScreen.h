#pragma once
#include "clsAddNewClientScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include <iostream>
#include <string>

class clsUpdateClientScreen :protected clsAddNewClientScreen
{


private:

	//static void _ReadClientInfo(clsBankClient& Client)
	//{
	//	//Different ways to get input.

	//	cout << "\nEnter FirstName: ";
	//	clsPerson::PerformFirstName(Client); //Upcasting -> Zero Performance Overhead // PerformFirstName() here without any numbers or spatial characters.

	//	Client.LastName = clsInputValidate::ReadString("\nEnter LastName: "); // Normal input.

	//	cout << "\nEnter Email: ";
	//	clsPerson::PerformEmail(Client);

	//	cout << "\nEnter Phone: ";
	//	Client.PerformPhone(Client);

	//	cout << "Enter PinCode: ";
	//	Client.PinCode = clsInputValidate::ReadString();

	//	cout << "\nEnter Account Balance: ";
	//	Client.AccountBalance = clsInputValidate::ReadFloatNumber();

	//	//cout << "Enter Gender [M/F]: "; //I didn't implement it and MartialStatus in output to keep it as simple as can.
	//	//Client.PerformGenderInfo(Client);
	//}

	//static void _PrintClient(const clsBankClient& Client)
	//{
	//	cout << clsUtil::ColorText("\n[Client Card]", "#9b96bc");
	//	cout << "\n___________________";
	//	cout << "\nFirstName   : " << Client.FirstName;
	//	cout << "\nLastName    : " << Client.LastName;
	//	cout << "\nFull Name   : " << Client.FullName();
	//	cout << "\nEmail       : " << Client.Email;
	//	cout << "\nPhone       : " << Client.Phone;
	//	cout << "\nAcc. Number : " << Client.AccountNumber();
	//	cout << "\nPassword    : " << Client.PinCode;
	//	cout << "\nBalance     : " << Client.AccountBalance;
	//	cout << "\n___________________\n";

	//}

public:

	static void ShowUpdateClientScreen()
	{
		_DrawScreenHeader("\t Update Client Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		clsBankClient::PerformIsClientAccountNumberExist(AccountNumber);

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);



		cout << "\n\nUpdate Client Info:";
		cout << clsUtil::ColorText("\n____________________\n", clsUtil::enColor::GREEN);
		_ReadClientInfo(Client1);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = Client1.Save();

		switch (SaveResult)
		{
		case  clsBankClient::enSaveResults::svSucceeded:
		{
			cout << clsUtil::ColorText("\nAccount Updated Successfully \n", clsUtil::enColor::GOLD);
			_PrintClient(Client1);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << clsUtil::ColorText("\nError account was not saved because it's Empty", clsUtil::enColor::RED);
			break;

		}


		}
	}
};

