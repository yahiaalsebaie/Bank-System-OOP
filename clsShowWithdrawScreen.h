#pragma once
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include <iostream>
#include <string>

using namespace std;
class clsShowWithdrawScreen :protected clsScreen
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

	static void ShowWithdrawScreen()
	{

		_DrawScreenHeader("\t  Withdraw Screen ");
		string AccountNumber = "";

		std::cout << "\nPlease Enter client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		clsBankClient::PerformIsClientAccountNumberExist(AccountNumber);

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);


		double Amount = clsInputValidate::ReadPositiveDblNumber("\n\nPlease Enter Withdraw Amount : ");

		char Answer = 'N';
		std::cout << clsUtil::ColorText("\nAre you sure you want to perform this transaction ? [Y/N] >> ", clsUtil::enColor::ORANGE);
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y' || Answer == '1')
		{
			if (Client1.Withdraw(Amount))
				std::cout << clsUtil::ColorText(("Amount Withdraw Successfully Done, New Balance is [" + to_string(Client1.AccountBalance) + "]."), clsUtil::enColor::GOLD) << endl;
			else
			{
				cout << "\nCannot withdraw, Insufficient Balance!";
				cout << "\nAmount to withdraw is: " << clsUtil::ColorText(to_string(Amount), 255, 0, 0); //RGB Red
				cout << "\nYour Balance is: " << clsUtil::ColorText(to_string(Client1.AccountBalance), 150, 179, 149) << endl;


			}
		}
		else std::cout << clsUtil::ColorText("\nOperation was Cancelled..\n", clsUtil::enColor::RED) << endl;


	}

};

