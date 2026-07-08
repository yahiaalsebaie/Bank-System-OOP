#pragma once
#include "clsInputValidate.h"
#include "clsPerson.h"
#include "clsScreen.h"
#include "clsUser.h"
#include "clsUtil.h"
#include <iostream>
#include <string>

class clsFindUserScreen :protected clsScreen
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

	static void ShowFindUserScreen()
	{

		_DrawScreenHeader("\tFind User Screen");

		string  UserName;
		cout << "\nPlease Enter  User Name: ";
		UserName = clsInputValidate::ReadString();

		clsUser::PerformIsUserNameExist(UserName);

		clsUser User1 = clsUser::Find(UserName);

		if (!User1.IsEmpty())
		{
			cout << clsUtil::ColorText("\nUser Found \n", clsUtil::enColor::GOLD);
			_PrintUser(User1);
		}
		else
		{
			cout << clsUtil::ColorText("\nUser Was not Found", clsUtil::enColor::RED);
		}

		//	_PrintUser(User1);

	}

};

