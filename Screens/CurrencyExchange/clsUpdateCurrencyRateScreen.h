#pragma once
#include "clsCurrency.h"
#include "clsFindCurrencyScreen.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include <iostream>
#include <string>

class clsUpdateCurrencyRateScreen :private clsFindCurrencyScreen
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
public:

	static void ShowUpdateRateScreen()
	{
		_DrawScreenHeader("\t Update Currency Screen");

		string  CurrencyCode = "";

		cout << "\nPlease Enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();

		clsCurrency::PerformIsCurrencyCodeExist(CurrencyCode);

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency);


		char answer = 'n';
		cout << clsUtil::ColorText("\n Are you sure you want to update this Currency Rate? [Y/N] : ", clsUtil::enColor::BEIGE);
		cin >> answer;

		float newRate = 0;

		if (answer == 'y' || answer == 'Y' || answer == '1')
		{

			cout << clsUtil::ColorText("\n\nUpdate Currency Rate : ", clsUtil::enColor::GOLD);
			cout << "\n____________________\n";

			newRate = clsInputValidate::ReadFloatNumber("Enter New Currency Rate: ");

			Currency.UpdateRate(newRate);

			cout << clsUtil::ColorText("\n\nCurrency Rate Updated Successfully...", clsUtil::enColor::GOLD);

			_PrintCurrency(Currency);

		}
	}
};

