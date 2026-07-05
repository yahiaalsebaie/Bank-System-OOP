#pragma once
#include "clsBankClient.h"
#include "clsPerson.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class clsClientListScreen : protected clsScreen
{


private:

	static void PrintClientRecordLine(const clsBankClient& Client)
	{
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(15) << Client.AccountNumber();
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(20) << Client.FullName();
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(15) << Client.Phone;
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(25) << Client.Email;
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(10) << Client.PinCode;
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(12) << Client.AccountBalance;
	}


public:

	static void ShowClientsList()
	{
		const vector<clsBankClient>& vClients = clsBankClient::GetClientsList();

		//Head
		string separatorLine = "\n_________________________________________________________________________________________________________\n";
		string NumberOfClients = to_string(vClients.size());
		string Title = "\t   Client List ";
		string SubTitle = clsUtil::ColorText("\t [", clsUtil::enColor::RED) + clsUtil::ColorText(NumberOfClients, clsUtil::enColor::YELLOW) + clsUtil::ColorText("]", clsUtil::enColor::RED) + " Client(s).";

		_DrawScreenHeader(Title, SubTitle);


		//Body
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(15) << "Account Number";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(20) << "Client Name";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(15) << "Phone";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(25) << "Email";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(10) << "Pin Code";
		cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(12) << "Balance";
		cout << clsUtil::ColorText(separatorLine, clsUtil::enColor::YELLOW);

		if (vClients.empty())
			clsUtil::PrintColoredTextLine("\t\t\t\tNo Clients Data Available In System!", clsUtil::enColor::RED);
		else
		{
			for (const clsBankClient& Client : vClients)
			{
				PrintClientRecordLine(Client);
				cout << endl;
			}
		}
		//Footer
		cout << clsUtil::ColorText(separatorLine, clsUtil::enColor::YELLOW);

	}

};

