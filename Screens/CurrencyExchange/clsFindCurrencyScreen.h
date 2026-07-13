#pragma once
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include <iostream>
#include <string>

class clsFindCurrencyScreen :protected clsScreen
{

private:
	static void _PrintCurrency(const clsCurrency& Currency)
	{
		cout << clsUtil::ColorText("\n[Currency Card]", "#9b96bc");
		cout << "\n____________________________";
		cout << "\nCountry       : " << Currency.Country();
		cout << "\nCurrency Code : " << Currency.CurrencyCode();
		cout << "\nCurrency Name : " << Currency.CurrencyName();
		cout << "\nRate(1$) =    : " << Currency.Rate();
		cout << "\n____________________________\n";

	}

	static void _ShowResult(clsCurrency& Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << clsUtil::ColorText("\nCurrency Found\n", clsUtil::enColor::GOLD);
			_PrintCurrency(Currency);
		}
		else
		{
			cout << clsUtil::ColorText("\nCurrency Was not Found", clsUtil::enColor::RED);
		}
	}

	static void _PrintCurrencyWithCode()
	{
		cout << "\nPlease Enter Currency Code: ";
		string CurrencyCode = clsInputValidate::ReadString();

		clsCurrency::PerformIsCurrencyCodeExist(CurrencyCode);

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		_ShowResult(Currency);

	}
	static void _PrintCurrencyWithCountry()
	{
		cout << "\nPlease Enter Currency Country: ";
		string CurrencyCountry = clsInputValidate::ReadString();

		clsCurrency::PerformIsCurrencyCountryExist(CurrencyCountry);

		clsCurrency Currency = clsCurrency::FindByCountry(CurrencyCountry);

		_ShowResult(Currency);


	}


public:

	static void ShowFindCurrencyScreen()
	{

		_DrawScreenHeader("\tFind Currency Screen");

		char Answer = '1';

		cout << clsUtil::ColorText(
			"\nShortcut Tip: You can combine your choice and input in one step together.\n Examples: 1EGP, 2Egypt\n\n",
			clsUtil::enColor::GOLD);

		cout << "Find By: [1]: Code Or [2]: Country ? : ";
		cin >> Answer;

		if (Answer == '1')
			_PrintCurrencyWithCode();
		else if (Answer == '2')
			_PrintCurrencyWithCountry();
		//		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

};



