#pragma once
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include <ios>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

class clsTransferScreen :protected clsScreen
{
private:


	static void _PrintClient(const clsBankClient& Client, string Message = "")
	{
		cout << clsUtil::ColorText("\n[Client Card]", "#9b96bc");
		if (Message != "") cout << Message;
		cout << "\n______________________________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n______________________________________\n";

	}

	static clsBankClient _PerformClientInfo()
	{
		string AccountNumber = "";
		AccountNumber = clsInputValidate::ReadString();

		clsBankClient::PerformIsClientAccountNumberExist(AccountNumber);

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		return Client1;
	}

public:
	static void ShowTransferScreen()
	{

		_DrawScreenHeader("\t  Transfer Screen ");

		std::cout << "\nPlease Enter Account Number to Transfer From : ";
		clsBankClient From = _PerformClientInfo();
		_PrintClient(From);

		std::cout << "\nPlease Enter Account Number to Transfer To : ";
		clsBankClient To = _PerformClientInfo();
		_PrintClient(To);


		double Amount = clsInputValidate::ReadPositiveDblNumber("\n\nPlease Enter Transfer Amount : ");

		while (From.AccountBalance < Amount)
		{
			Amount = clsInputValidate::ReadPositiveDblNumber("\n\nAmount Exceeds tha available Balance," + clsUtil::ColorText("Enter Another Amount : ", clsUtil::enColor::BRIGHT_YELLOW));
		}

		char Answer = 'N';
		std::cout << clsUtil::ColorText("\nAre you sure you want to perform this transaction ? [Y/N] : ", clsUtil::enColor::ORANGE);
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y' || Answer == '1')
		{

			From.Transfer(Amount, To);

			std::cout << clsUtil::ColorText(("\nTransfer Successfully Done From [" + From.AccountNumber() + "] To [" + To.AccountNumber() + "]."), clsUtil::enColor::GOLD) << endl;
		}
		else std::cout << clsUtil::ColorText("\nOperation was Cancelled..\n", clsUtil::enColor::RED) << endl;

		_PrintClient(From, "From:");
		_PrintClient(To, "To:");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

};
