#pragma once
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsPerson.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include <clsUser.h>
#include <iostream>
#include <string>

class clsFindClientScreen :protected clsScreen
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

	static void ShowFindClientScreen()
	{

		_DrawScreenHeader("\tFind Client Screen");


		if (!CheckAccessRights(clsUser::enPermissions::epFindClient))
		{
			return;
		}

		string AccountNumber;
		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		clsBankClient::PerformIsClientAccountNumberExist(AccountNumber);

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		if (!Client1.IsEmpty())
		{
			cout << clsUtil::ColorText("\nClient Found \n", clsUtil::enColor::GOLD);
			_PrintClient(Client1);
		}
		else
		{
			cout << clsUtil::ColorText("\nClient Was not Found", clsUtil::enColor::RED);

		}

		//	_PrintClient(Client1);

	}

};

