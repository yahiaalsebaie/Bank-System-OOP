#pragma once
#include "clsDepositScreen.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <string>

class clsTransactionsScreen :protected clsScreen
{
private:
	enum class enTransactionsMenuOptions : unsigned char {
		MainMenu = 0, Deposit = 1, Withdraw = 2, TotalBalances = 3
	};

	static  void _GoBackToTransactionsMenu()
	{
		cout << setw(37) << left << "" << clsUtil::ColorText("\n\tPress any key to go back to Transactions Menu...\n", clsUtil::enColor::BRIGHT_RED);

		system("pause>0");
	}


	static short _ReadTransactionsMenuOption()
	{
		cout << setw(37) << left << "";
		short Choice = clsInputValidate::ReadNumberInRange(0, 3, "Choose what do you want to do?");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return Choice;
	}
	static void _ShowDepositScreen()
	{
		cout << "\n Deposit Screen  Will be here...\n";

	}

	static void _ShowWithdrawScreen()
	{
		cout << "\n Withdraw Will be here...\n";

	}

	static void _ShowTotalBalancesScreen()
	{
		cout << "\n TotalBalances Screen Will be here...\n";

	}



	static void _PerformTransactionsMenuOption(enTransactionsMenuOptions TransactionsMenuOption)
	{
		switch (TransactionsMenuOption)
		{
		case clsTransactionsScreen::enTransactionsMenuOptions::Deposit:
			system("cls");
			clsDepositScreen::ShowDepositScreen();
			_GoBackToTransactionsMenu();
			break;
		case clsTransactionsScreen::enTransactionsMenuOptions::Withdraw:
			system("cls");

			_GoBackToTransactionsMenu();
			break;
		case clsTransactionsScreen::enTransactionsMenuOptions::TotalBalances:
			system("cls");

			_GoBackToTransactionsMenu();
			break;
		case clsTransactionsScreen::enTransactionsMenuOptions::MainMenu:
		default:
			break;
		}
	}


public:


	static void ShowTransactionsMenu()
	{
		enTransactionsMenuOptions Choice;

		do {
			system("cls");
			_DrawScreenHeader("\t  Transactions Screen");
			string SeparatorLine = clsUtil::ColorText("===========================================\n", clsUtil::enColor::BRIGHT_CYAN);

			cout << setw(37) << left << "" << SeparatorLine;
			cout << setw(37) << left << "" << "\t\t  Transactions Menu\n";
			cout << setw(37) << left << "" << SeparatorLine;
			cout << setw(37) << left << "" << "\t[1] Deposit.\n";
			cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
			cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
			cout << setw(37) << left << "" << "\t[0] Main Menu.\n";
			cout << setw(37) << left << "" << SeparatorLine;

			Choice = (enTransactionsMenuOptions)_ReadTransactionsMenuOption();

			if (Choice != enTransactionsMenuOptions::MainMenu)
				_PerformTransactionsMenuOption(Choice);
		} while (Choice != enTransactionsMenuOptions::MainMenu);

	}

};

