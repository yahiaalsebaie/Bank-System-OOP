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






	static bool _Login()
	{
		bool loginFailed = false;

		string userName = "", Password = "";

		short Trials = 2;

		do
		{
			if (loginFailed)
			{

				cout << clsUtil::ColorText("\n Invalid UserName/Password!\n\n", clsUtil::enColor::BEIGE);
				cout << " You have [" << clsUtil::ColorText(to_string(Trials), clsUtil::enColor::BRIGHT_YELLOW) << "] trial(s) left.\n\n";

				if (Trials == 0)
				{
					system("cls");
					cout << clsUtil::ColorText("\n\n\n\n\n\n\n\n You are locked after 3 trail(s)\n\n", clsUtil::enColor::BEIGE);
					return false;
				}
				Trials--;

			}

			cout << "Enter UserName: ";
			cin >> userName;

			cout << "Enter Password: ";
			cin >> Password;

			CurrentUser = clsUser::Find(userName,Password);
			//CurrentUser = clsUser::Find(userName, clsUtil::DecryptText(Password, 2));

			loginFailed = CurrentUser.IsEmpty();


		} while (loginFailed);
		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenu();
		return true;
	}

public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t      Login Screen");
		return	_Login();
	}
};

