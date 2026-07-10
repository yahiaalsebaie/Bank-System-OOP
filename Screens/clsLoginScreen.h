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

		short Trails = 2;

		do
		{
			if (loginFailed)
			{

				cout << clsUtil::ColorText("\n Invalid UserName/Password!\n\n", clsUtil::enColor::BEIGE);
				cout << " You have [" << clsUtil::ColorText(to_string(Trails), clsUtil::enColor::BRIGHT_YELLOW) << "] to login.\n\n";

				if (Trails == 0)
				{
					system("cls");
					cout << clsUtil::ColorText("\n\n\n\n\n\n\n\n You are locked after 3 trail(s)\n\n", clsUtil::enColor::BEIGE);
					return false;
				}
				Trails--;

			}

			cout << "Enter UserName: ";
			cin >> userName;

			cout << "Enter Password: ";
			cin >> Password;

			CurrentUser = clsUser::Find(userName, Password);

			loginFailed = CurrentUser.IsEmpty();


		} while (loginFailed);

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

