#pragma once
#include "Clients/clsAddNewClientScreen.h"
#include "Clients/clsClientListScreen.h"
#include "Clients/clsDeleteClientScreen.h"
#include "Clients/clsFindClientScreen.h"
#include "Clients/clsUpdateClientScreen.h"
#include "clsCurrencyExchangeMainScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsUtil.h"
#include "Screens/clsScreen.h"
#include "Transactions/clsTransactionsScreen.h"
#include "Users/clsManageUsersScreen.h"
#include <cstdlib>
#include <Global.h>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <string>


using namespace std;

class clsMainScreen :protected clsScreen
{


private:
	enum class enMainMenuOptions : unsigned char {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenu = 6,
		eManageUsers = 7, eCurrencyExchange = 8, eLogout = 0
	};

	static short _ReadMainMenuOption()
	{
		//cout << setw(37) << left << "";
		string Msg = string(37, ' ') + "Choose what do you want to do?";
		string ErrorMsg = string(37, ' ') + "Invalid Number, Enter a valid one : ";
		short Choice = clsInputValidate::ReadNumberInRange(0, 8, Msg, ErrorMsg);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return Choice;
	}

	static  void _GoBackToMainMenu()
	{
		cout << setw(37) << left << "" << clsUtil::ColorText("\n\tPress any key to go back to Main Menu...\n", clsUtil::enColor::BRIGHT_RED);

		system("pause>0");
	}

	static void _ShowAllClientsScreen()
	{
		// cout << "\nClient List Screen Will be here...\n";
		clsClientListScreen::ShowClientsList();

	}

	static void _ShowAddNewClientsScreen()
	{
		// cout << "\nAdd New Client Screen Will be here...\n";
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		//cout << "\nDelete Client Screen Will be here...\n";
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		//cout << "\nUpdate Client Screen Will be here...\n";
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		//cout << "\nFind Client Screen Will be here...\n";
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenu()
	{
		// cout << "\nTransactions Menu Will be here...\n";
		clsTransactionsScreen::ShowTransactionsMenu();
	}

	static void _ShowManageUsersMenu()
	{
		//cout << "\nUsers Menu Will be here...\n";
		clsManageUsersScreen::ShowManageUsersMenu();
	}
	static void _ShowCurrencyExchangeMenu()
	{
		clsCurrencyExchangeMainScreen::ShowCurrencyExchangeMenu();

	}

	static void _ShowLogoutScreen()
	{
		//cout << "\nEnd Screen Will be here...\n";
		CurrentUser = clsUser::Find("", "");

	}

	static void _PerformMainMenuOption(enMainMenuOptions MainMenuOption)
	{
		switch (MainMenuOption)
		{
		case enMainMenuOptions::eListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eAddNewClient:
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::eDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::eUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::eFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::eShowTransactionsMenu:
			system("cls");
			_ShowTransactionsMenu();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::eManageUsers:
			system("cls");
			_ShowManageUsersMenu();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::eCurrencyExchange:
			system("cls");
			_ShowCurrencyExchangeMenu();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::eLogout:
			system("cls");
			_ShowLogoutScreen();

			break;
		}

	}



public:


	static void ShowMainMenu()
	{
		enMainMenuOptions Choice;

		do {
			system("cls");
			_DrawScreenHeader("\t\tMain Screen");
			string SeparatorLine = clsUtil::ColorText("===========================================\n", clsUtil::enColor::BRIGHT_CYAN);

			cout << setw(37) << left << "" << SeparatorLine;
			cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
			cout << setw(37) << left << "" << SeparatorLine;
			cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
			cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
			cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
			cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
			cout << setw(37) << left << "" << "\t[5] Find Client.\n";
			cout << setw(37) << left << "" << "\t[6] Transactions.\n";
			cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
			cout << setw(37) << left << "" << "\t[8] Currency Exchange.\n";
			cout << setw(37) << left << "" << "\t[0] Logout.\n";
			cout << setw(37) << left << "" << SeparatorLine;

			Choice = (enMainMenuOptions)_ReadMainMenuOption();

			if (Choice != enMainMenuOptions::eLogout)
				_PerformMainMenuOption(Choice);
		} while (Choice != enMainMenuOptions::eLogout);

		system("cls");
		_ShowLogoutScreen();
	}

};

