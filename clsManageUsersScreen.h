#pragma once
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsUsersListScreen.h"
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <string>

class clsManageUsersScreen :protected clsScreen
{
private:
	enum class enManageUsersMenuOptions : unsigned char {
		MainMenu = 0, ListUsers = 1, AddNewUser = 2, DeleteUser = 3, UpdateUser = 4, FindUser = 5,
	};

	static  void _GoBackToManageUsersMenu()
	{
		cout << setw(37) << left << "" << clsUtil::ColorText("\n\tPress any key to go back to Manage Users Menu...\n", clsUtil::enColor::BRIGHT_RED);

		system("pause>0");
	}


	static short _ReadManageUsersMenuOption()
	{
		cout << setw(37) << left << "";
		short Choice = clsInputValidate::ReadNumberInRange(0, 5, "Choose what do you want to do?");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return Choice;
	}

	static void _ShowListUsersScreen()
	{
		//cout << "\n ListUsers Screen  Will be here...\n";
		clsUsersListScreen::ShowUsersList();
	};
	static void _ShowAddNewUserScreen()
	{
		cout << "\n AddNewUser Screen  Will be here...\n";

	}
	static void _ShowDeleteUserScreen()
	{
		cout << "\n DeleteUser Screen  Will be here...\n";

	}
	static void _ShowUpdateUserScreen()
	{
		cout << "\n UpdateUser Screen  Will be here...\n";

	}
	static void _ShowFindUserScreen()
	{
		cout << "\n FindUser Screen  Will be here...\n";

	}



	static void _PerformManageUsersMenuOption(enManageUsersMenuOptions ManageUsersMenuOption)
	{

		switch (ManageUsersMenuOption)
		{

		case clsManageUsersScreen::enManageUsersMenuOptions::ListUsers:
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenu();
			break;
		case clsManageUsersScreen::enManageUsersMenuOptions::AddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenu();
			break;
		case clsManageUsersScreen::enManageUsersMenuOptions::DeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenu();
			break;
		case clsManageUsersScreen::enManageUsersMenuOptions::UpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenu();
			break;
		case clsManageUsersScreen::enManageUsersMenuOptions::FindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenu();
			break;
		case clsManageUsersScreen::enManageUsersMenuOptions::MainMenu:
		default:
			break;
		}
	}


public:


	static void ShowManageUsersMenu()
	{
		enManageUsersMenuOptions Choice;

		do {
			system("cls");
			_DrawScreenHeader("\t  Manage Users Screen");
			string SeparatorLine = clsUtil::ColorText("===========================================\n", clsUtil::enColor::BRIGHT_CYAN);

			cout << setw(37) << left << "" << SeparatorLine;//----------
			cout << setw(37) << left << "" << "\t\t Manage Users Menu\n";
			cout << setw(37) << left << "" << SeparatorLine;//----------

			cout << setw(37) << left << "" << "\t[1] List Users.\n";
			cout << setw(37) << left << "" << "\t[2] Add New User.\n";
			cout << setw(37) << left << "" << "\t[3] Delete User.\n";
			cout << setw(37) << left << "" << "\t[4] Update User.\n";
			cout << setw(37) << left << "" << "\t[5] Find User.\n";
			cout << setw(37) << left << "" << "\t[0] Main Menu.\n";

			cout << setw(37) << left << "" << SeparatorLine;//----------

			Choice = (enManageUsersMenuOptions)_ReadManageUsersMenuOption();

			if (Choice != enManageUsersMenuOptions::MainMenu)
				_PerformManageUsersMenuOption(Choice);
		} while (Choice != enManageUsersMenuOptions::MainMenu);

	}

};

