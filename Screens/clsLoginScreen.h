#pragma once
#include "clsMainScreen.h";
#include "clsScreen.h";
#include "clsUser.h";
#include "Global.h";
#include <clsUtil.h>
#include <cstdlib>
#include <iostream>
#include <string>


class clsLoginScreen : private clsScreen
{
private:
	static void _Login()
	{
		bool loginFailed = false;

		string userName = "", Password = "";

		do
		{
			if (loginFailed) cout << clsUtil::ColorText("\n Invalid UserName/Password!\n\n", clsUtil::enColor::BEIGE);

			cout << "Enter UserName: ";
			cin >> userName;

			cout << "Enter Password: ";
			cin >> Password;

			CurrentUser = clsUser::Find(userName, Password);

			loginFailed = CurrentUser.IsEmpty();

		} while (loginFailed);

		clsMainScreen::ShowMainMenu();
	}

public:
	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t\tLogin Screen");
		_Login();
	}
};

