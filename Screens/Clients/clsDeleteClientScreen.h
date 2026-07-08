#pragma once
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsPerson.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include <clsUser.h>
#include <iostream>
#include <string>


class clsDeleteClientScreen : protected clsScreen
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
	static void ShowDeleteClientScreen()
	{
		_DrawScreenHeader("\t Delete Client Screen");


		if (!CheckAccessRights(clsUser::enPermissions::epDeleteClient))
		{
			return;
		}

		string AccountNumber = "";

		cout << "\nPlease Enter client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		clsBankClient::PerformIsClientAccountNumberExist(AccountNumber);

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		_PrintClient(Client1);

		char Answer = 'n';
		cout << clsUtil::ColorText("\nAre you sure you want to Delete this Client ? [Y/N] >> ", clsUtil::enColor::RED);
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (Client1.Delete())
			{
				cout << clsUtil::ColorText("\nClient Deleted Successfully.\n", clsUtil::enColor::GOLD);
				_PrintClient(Client1);
			}

			else  cout << clsUtil::ColorText("\nError: Client Not Deleted.\n", clsUtil::enColor::RED);
		}

	}

};

