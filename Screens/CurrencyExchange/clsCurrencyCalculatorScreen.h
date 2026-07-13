#pragma once
#include "clsCurrency.h"
#include "clsUtil.h"
#include <clsInputValidate.h>
#include <clsScreen.h>
#include <cstdlib>
#include <iostream>
#include <string>
class clsCurrencyCalculatorScreen : protected clsScreen
{

private:
	static void _PrintCurrency(const clsCurrency& Currency, string Message = "\n[Currency Card]")
	{
		cout << clsUtil::ColorText(Message, "#9b96bc");
		cout << "\n__________________________________________";
		cout << "\nCountry       : " << Currency.Country();
		cout << "\nCurrency Code : " << Currency.CurrencyCode();
		cout << "\nCurrency Name : " << Currency.CurrencyName();
		cout << "\nRate(1$) =    : " << Currency.Rate();
		cout << "\n__________________________________________\n";

	}
	static clsCurrency _ReadCurrencyCode(string Message = "\nPlease Enter Currency Code: ")
	{
		string CurrencyCode = clsInputValidate::ReadString(Message);

		clsCurrency::PerformIsCurrencyCodeExist(CurrencyCode);

		return clsCurrency::FindByCode(CurrencyCode);
	}


public:
	static void ShowCurrencyCalculatorScreen()
	{
		char Answer = 'y';
		do
		{
			system("cls");
			_DrawScreenHeader("\tCurrency Calculator Screen");

			clsCurrency Currency1 = _ReadCurrencyCode("\nPlease Enter Currency 1 Code: ");
			clsCurrency Currency2 = _ReadCurrencyCode("\nPlease Enter Currency 2 Code: ");

			float amount = clsInputValidate::ReadFloatNumber("\nEnter Amount to Exchange: ");

			//float AmountInUSD = amount / Currency1.Rate();
			//float  FinalAmount = AmountInUSD * Currency2.Rate();

			float AmountInUSD = Currency1.ConvertToUSD(amount);
			float FinalAmount =	Currency1.ConvertTo(amount, Currency2);

			_PrintCurrency(Currency1, "\n\n[Converted From " + Currency1.CurrencyCode() + " to USD]");

			if (Currency1.CurrencyCode() != "USD")
			{
				cout << amount << " " << Currency1.CurrencyCode() << " = " << Currency1.ConvertToUSD(amount) << " USD\n";

			}

			if (Currency2.CurrencyCode() != "USD")
			{
				_PrintCurrency(Currency2, "\n\n[Converted From " + Currency1.CurrencyCode() + " to " + Currency2.CurrencyCode() + "]:");

				cout << amount << " " << Currency1.CurrencyCode() << " = " << (FinalAmount) << " USD.\n";
			}



			cout << clsUtil::ColorText("\nDo you want to perform another calculation [Y/N] : ", clsUtil::enColor::GOLD);
			cin >> Answer;
		} while (Answer == 'y' || Answer == 'Y' || Answer == '1');

	}

};

