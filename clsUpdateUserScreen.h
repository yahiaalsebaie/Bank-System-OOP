#pragma once
#include "clsAddNewUserScreen.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"
#include "clsUtil.h"
#include <iostream>
#include <string>

class clsUpdateUserScreen :protected clsAddNewUserScreen
{


private:
	// _PrintUser, _ReadPermissions, and _ReadUserInfo could be placed here, but since there is no change with clsAddNewUserScreen, I simply inherited it.

public:

	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("\t Update User Screen");

		string  UserName = "";

		cout << "\nPlease Enter User Name: ";
		UserName = clsInputValidate::ReadString();

		clsUser::PerformIsUserNameExist(UserName);

		clsUser User1 = clsUser::Find(UserName);
		_PrintUser(User1);


		char answer = 'n';
		cout << clsUtil::ColorText("\n Are you sure you want to update this User Info? [Y/N] : ", clsUtil::enColor::BEIGE);
		cin >> answer;


		if (answer == 'y' || answer == 'Y' || answer == '1')
		{

			cout << "\n\nUpdate User Info:";
			cout << clsUtil::ColorText("\n____________________\n", clsUtil::enColor::GREEN);
			_ReadUserInfo(User1);

			clsUser::enSaveResults SaveResult;

			SaveResult = User1.Save();

			switch (SaveResult)
			{
			case  clsUser::enSaveResults::svSucceeded:
			{
				cout << clsUtil::ColorText("\nUser Updated Successfully \n", clsUtil::enColor::GOLD);
				_PrintUser(User1);
				break;
			}
			case clsUser::enSaveResults::svFaildEmptyObject:
			{
				cout << clsUtil::ColorText("\nError: user was Not saved", clsUtil::enColor::RED);
				break;
			}

			}
		}
	}
};

