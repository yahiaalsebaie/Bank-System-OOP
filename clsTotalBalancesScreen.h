#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class clsTotalBalancesScreen :protected clsScreen
{
private:


	static void _PrintClientRecordBalanceLine(const clsBankClient& Client)
	{
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(15) << Client.AccountNumber();
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(30) << Client.FullName();
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(15) << Client.AccountBalance;
	}

public:

	static void ShowTotalBalancesScreen()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		string SeparatorLine = "\n_________________________________________________________________________________________________________\n";
		string NumberOfClients = to_string(vClients.size());
		/*cout << "\n\t\t\t\t\tClient List " << clsUtil::ColorText("[", clsUtil::enColor::RED) << clsUtil::ColorText(NumberOfClients, clsUtil::enColor::YELLOW) << clsUtil::ColorText("]", clsUtil::enColor::RED) << " Client(s).";*/
		string subTitle = clsUtil::ColorText("\t    [", clsUtil::enColor::RED) + clsUtil::ColorText(NumberOfClients, clsUtil::enColor::YELLOW) + clsUtil::ColorText("]", clsUtil::enColor::RED) + " Client(s).";

		_DrawScreenHeader("\t Balances List Screen", subTitle);

		cout << clsUtil::ColorText(SeparatorLine, clsUtil::enColor::YELLOW);

		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(15) << "Account Number";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(30) << "Client Name";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(15) << "Balance";
		cout << clsUtil::ColorText(SeparatorLine, clsUtil::enColor::YELLOW);

		if (vClients.size() == 0)
			clsUtil::PrintColoredTextLine("\t\t\t\tNo Clients Available In System!", clsUtil::enColor::RED);
		else

			for (const clsBankClient& Client : vClients)
			{
				_PrintClientRecordBalanceLine(Client);
				cout << endl;
			}

		cout << clsUtil::ColorText(SeparatorLine, clsUtil::enColor::YELLOW);

		//Total Balances
		double TotalBalances = clsBankClient::GetTotalBalances(vClients);

		cout <<  "\t\t\t\tTotal Balances = " << clsUtil::ColorText(to_string(TotalBalances), 150, 179, 149) << endl;

		string txt = clsUtil::ConvertNumberToText<unsigned long>(TotalBalances);

		if (TotalBalances == 0)
			cout << "\n\t\t\t\t\t\t\t" << "Zero" << endl;
		else
			cout << "\n\t\t\t\t" << txt << endl;

	}

};

