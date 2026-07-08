#pragma once
#include "clsInputValidate.h"
#include "clsPerson.h"
#include "clsScreen.h"
#include "clsUser.h"
#include "clsUtil.h"
#include <iostream>
#include <string>


class clsDeleteUserScreen : protected clsScreen
{
private:

	static void _PrintUser(const clsUser& User)
	{
		cout << clsUtil::ColorText("\n[User Card]", "#9b96bc");
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName();
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}

public:
	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("\t Delete User Screen");

		string UserName = "";

		cout << "\nPlease Enter User Name: ";
		UserName = clsInputValidate::ReadString();

		clsUser::PerformIsUserNameExist(UserName);

		clsUser User1 = clsUser::Find(UserName);

		_PrintUser(User1);

		char Answer = 'n';
		cout << clsUtil::ColorText("\nAre you sure you want to Delete this User ? [Y/N] >> ", clsUtil::enColor::RED);
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (User1.Delete())
			{
				cout << clsUtil::ColorText("\nUser Deleted Successfully.\n", clsUtil::enColor::GOLD);
				_PrintUser(User1);
			}

			else  cout << clsUtil::ColorText("\nError: User Not Deleted.\n", clsUtil::enColor::RED);
		}

	}

};

