#pragma once
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include <iostream>
#include <string>

using namespace std;

class clsDepositScreen :protected clsScreen
{
private:


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
	static void ShowDepositScreen()
	{

		_DrawScreenHeader("\t  Deposit Screen ");
		string AccountNumber = "";

		std::cout << "\nPlease Enter client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		clsBankClient::PerformIsClientAccountNumberExist(AccountNumber);

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);


		double Amount = clsInputValidate::ReadPositiveDblNumber("\n\nPlease Enter Deposit Amount : ");

		char Answer = 'N';
		std::cout << clsUtil::ColorText("\nAre you sure you want to perform this transaction ? [Y/N] >> ", clsUtil::enColor::ORANGE);
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y' || Answer == '1')
		{
			Client1.Deposit(Amount);

			std::cout << clsUtil::ColorText(("Amount Deposit Successfully, New balance is [" + to_string(Client1.AccountBalance) + "]."), clsUtil::enColor::GOLD) << endl;
		}
		else std::cout << clsUtil::ColorText("\nOperation was cancelled..\n", clsUtil::enColor::RED) << endl;


	}

};
