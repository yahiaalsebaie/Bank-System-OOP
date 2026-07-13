#pragma once
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <limits>
#include <limits>
#include <string>
#include <vector>

using namespace std;


class clsCurrenciesListScreen : protected clsScreen
{
private:

	static void PrintCurrencyRecordLine(const clsCurrency& Currency)
	{
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(30) << Currency.Country();
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(5) << Currency.CurrencyCode();
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(40) << Currency.CurrencyName();
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(20) << Currency.Rate();
	}


public:

	static void ShowCurrenciesList()
	{
		const vector<clsCurrency>& vCurrencies = clsCurrency::GetCurrenciesList();

		//Head
		string separatorLine = "\n____________________________________________________________________________________________________________________\n";
		string NumberOfCurrencies = to_string(vCurrencies.size());
		string Title = "\t\tCurrency List ";
		string SubTitle = clsUtil::ColorText("\t       [", clsUtil::enColor::RED) + clsUtil::ColorText(NumberOfCurrencies, clsUtil::enColor::YELLOW) + clsUtil::ColorText("]", clsUtil::enColor::RED) + " Currency(s).";

		_DrawScreenHeader(Title, SubTitle);


		//Body
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(30) << "Country";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(5) << "Code";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(40) << "Name";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(20) << "Rate";
		cout << clsUtil::ColorText(separatorLine, clsUtil::enColor::YELLOW);

		if (vCurrencies.empty())
			clsUtil::PrintColoredTextLine("\t\t\t\tNo Currencies Data Available In System!", clsUtil::enColor::RED);
		else
		{
			for (const clsCurrency& Currency : vCurrencies)
			{
				PrintCurrencyRecordLine(Currency);
				cout << endl;
			}
		}
		//Footer
		cout << clsUtil::ColorText(separatorLine, clsUtil::enColor::YELLOW);
	//	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}

};

