#pragma once
//#include "clsCurrencyCalculatorScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrenciesListScreen.h"
#include "clsUser.h"
#include "clsUtil.h"
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <string>

class clsCurrencyExchangeMainScreen :protected clsScreen
{
private:
	enum class enCurrencyExchangeMenuOptions : unsigned char {
		MainMenu = 0, ListCurrencies = 1, FindCurrency = 2, UpdateRate = 3, CurrencyCalculator = 4
	};

	static  void _GoBackToCurrencyExchangeMenu()
	{
		cout << setw(37) << left << "" << clsUtil::ColorText("\n\tPress any key to go back to Currency Exchange Menu...\n", clsUtil::enColor::BRIGHT_RED);

		system("pause>0");
	}


	static short _ReadCurrencyExchangeMenuOption()
	{
		//cout << setw(37) << left << "";
		string Msg = string(37, ' ') + "Choose what do you want to do?";
		string ErrorMsg = string(37, ' ') + "Invalid Number, Enter a valid one : ";
		short Choice = clsInputValidate::ReadNumberInRange(0, 4, Msg, ErrorMsg);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return Choice;
	}

	static void _ShowListCurrenciesScreen()
	{
		//cout << "\n ListCurrencies Screen  Will be here...\n";
		clsCurrenciesListScreen::ShowCurrenciesList();
	};
	static void _ShowFindCurrencyScreen()
	{
		//cout << "\n FindCurrency Screen  Will be here...\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	static void _ShowUpdateRateScreen()
	{
		//cout << "\n UpdateRate Screen  Will be here...\n";
		clsUpdateCurrencyRateScreen::ShowUpdateRateScreen();
	}
	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\n CurrencyCalculator Screen  Will be here...\n";
		//clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}



	static void _PerformCurrencyExchangeMenuOption(enCurrencyExchangeMenuOptions CurrencyExchangeMenuOption)
	{

		switch (CurrencyExchangeMenuOption)
		{

		case clsCurrencyExchangeMainScreen::enCurrencyExchangeMenuOptions::ListCurrencies:
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		case clsCurrencyExchangeMainScreen::enCurrencyExchangeMenuOptions::FindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		case clsCurrencyExchangeMainScreen::enCurrencyExchangeMenuOptions::UpdateRate:
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		case clsCurrencyExchangeMainScreen::enCurrencyExchangeMenuOptions::CurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenu();
			break;

		case clsCurrencyExchangeMainScreen::enCurrencyExchangeMenuOptions::MainMenu:
		default:
			break;
		}
	}


public:


	static void ShowCurrencyExchangeMenu()
	{
		enCurrencyExchangeMenuOptions Choice;

		do {
			system("cls");
			_DrawScreenHeader("\tCurrency Exchange Screen");

			if (!CheckAccessRights(clsUser::enPermissions::epMangeUsers))
			{
				return;
			}

			string SeparatorLine = clsUtil::ColorText("===========================================\n", clsUtil::enColor::BRIGHT_CYAN);

			cout << setw(37) << left << "" << SeparatorLine;//----------
			cout << setw(37) << left << "" << "\t\t Currency Exchange Menu\n";
			cout << setw(37) << left << "" << SeparatorLine;//----------

			cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
			cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
			cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
			cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
			cout << setw(37) << left << "" << "\t[0] Main Menu.\n";

			cout << setw(37) << left << "" << SeparatorLine;//----------

			Choice = (enCurrencyExchangeMenuOptions)_ReadCurrencyExchangeMenuOption();

			if (Choice != enCurrencyExchangeMenuOptions::MainMenu)
				_PerformCurrencyExchangeMenuOption(Choice);
		} while (Choice != enCurrencyExchangeMenuOptions::MainMenu);

	}

};

