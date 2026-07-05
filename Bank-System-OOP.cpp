#include <iostream>
#include <string>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <cstdlib>
#include "clsPerson.h"
#include "clsUtil.h"
#include <iomanip>
#include "clsMainScreen.h"

using namespace std;

//--TotalBalances--
void PrintClientRecordBalanceLine(const clsBankClient& Client)
{
    cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(15) << Client.AccountNumber();
    cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(30) << Client.FullName();
    cout << clsUtil::ColorText("| ", clsUtil::enColor::RED) << left << setw(15) << Client.AccountBalance;
}
void ShowTotalBalances()
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();
string SeparatorLine = "\n_________________________________________________________________________________________________________\n";
string NumberOfClients = to_string(vClients.size());
cout << "\n\t\t\t\t\tClient List " << clsUtil::ColorText("[", clsUtil::enColor::RED) << clsUtil::ColorText(NumberOfClients, clsUtil::enColor::YELLOW) << clsUtil::ColorText("]", clsUtil::enColor::RED) << " Client(s).";
cout << clsUtil::ColorText(SeparatorLine, clsUtil::enColor::YELLOW);

    cout << clsUtil::ColorText("| ",clsUtil::enColor::RED) << left << setw(15) << "Account Number";
    cout << clsUtil::ColorText("| ",clsUtil::enColor::RED) << left << setw(30) << "Client Name";
    cout << clsUtil::ColorText("| ",clsUtil::enColor::RED) << left << setw(15) << "Balance";
    cout << clsUtil::ColorText(SeparatorLine, clsUtil::enColor::YELLOW);

    if (vClients.size() == 0)
        clsUtil::PrintColoredTextLine("\t\t\t\tNo Clients Available In System!", clsUtil::enColor::RED);
    else

        for (const clsBankClient& Client : vClients)
        {
            PrintClientRecordBalanceLine(Client);
            cout << endl;
        }

    cout << clsUtil::ColorText(SeparatorLine, clsUtil::enColor::YELLOW);

    //Total Balances
    double TotalBalances = clsBankClient::GetTotalBalances(vClients);

    cout << clsUtil::ColorText(("\t\t\t\tTotal Balances = " + to_string(TotalBalances)), clsUtil::enColor::GREEN);

    string txt = clsUtil::ConvertNumberToText<unsigned long>(TotalBalances);

    if (TotalBalances == 0)
        cout << "\n\t\t\t\t\t\t" << "Zero" << endl;
    else 
        cout << "\n\t\t\t" << txt << endl;

}


int main()

{
    //UpdateClient();
    //AddNewClient();
    //DeleteClient();
    //ShowClientsList();
    //ShowTotalBalances();

    clsMainScreen::ShowMainMenu();

     system("pause>0");
    return 0;
}